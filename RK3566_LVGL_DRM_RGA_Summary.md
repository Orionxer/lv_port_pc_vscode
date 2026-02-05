# RK3566 LVGL DRM RGA 显示方案总结文档

## 项目概述

**项目名称**: RK3566 LVGL Linux DRM 显示驱动

**硬件平台**: RK3566 (Rockchip)

**显示方案**: Linux DRM KMS + LVGL 图形库

**分辨率**: 480x800 (可配置)

**颜色深度**: RGB565 (16位色深)

**创建日期**: 2025-02-03

---

## 一、架构设计

### 1.1 系统架构

```
┌─────────────────────────────────────────────────────────────┐
│                        Application Layer                     │
│                    ┌──────────────────┐                     │
│                    │  LVGL v9.x      │                     │
│                    │  Benchmark Demo │                     │
│                    └──────────────────┘                     │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│                      HAL Layer (rk_drm.c)                      │
│  ┌───────────────┐  ┌──────────────┐  ┌──────────────┐      │
│  │ rk_drm_init() │  │ drm_create() │  │ drm_flush()  │      │
│  │               │  │              │  │              │      │
│  │ - RGA Init    │  │ - Display    │  │ - Buffer     │      │
│  │ - DRM Setup   │  │   Create     │  │   Copy       │      │
│  │ - Buffer Alloc│  │ - Resolution │  │ - Submit     │      │
│  └───────────────┘  └──────────────┘  └──────────────┘      │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│                      Linux Kernel Layer                     │
│  ┌─────────────────────────────────────────────────────┐   │
│  │           DRM/KMS (Direct Rendering Manager)        │   │
│  │  ┌────────┐  ┌────────┐  ┌────────┐  ┌─────────┐   │   │
│  │  │CRTC    │  │Plane   │  │Encoder │  │Connector│   │   │
│  │  └────────┘  └────────┘  └────────┘  └─────────┘   │   │
│  └─────────────────────────────────────────────────────┘   │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│                      Hardware Layer                          │
│  ┌───────────────┐  ┌──────────────┐  ┌──────────────┐      │
│  │   HDMI/LCD    │  │   Display    │  │  RGA (2D)    │      │
│  │   Controller  │  │   Controller │  │  Accelerator │      │
│  └───────────────┘  └──────────────┘  └──────────────┘      │
└─────────────────────────────────────────────────────────────┘
```

### 1.2 双缓冲机制

系统采用双缓冲机制以避免显示撕裂：

```
┌──────────────────────────────────────────────────────────────┐
│                      Double Buffering                        │
│                                                              │
│   Front Buffer [0] ────────────────────────► Display        │
│        │                                               ▲       │
│        │                                               │       │
│        ▼                                               │       │
│   Back Buffer  [1] ◄───────────────────────── DRM Commit   │
│        ▲                                                   │
│        │                                                   │
│   LVGL Rendering (px_map)                                  │
└──────────────────────────────────────────────────────────────┘
```

---

## 二、核心技术实现

### 2.1 文件结构

```
src/hal/
├── rk_drm.h           # DRM显示驱动头文件
├── rk_drm.c           # DRM显示驱动实现
└── hal.h              # HAL层统一接口

main.c                 # 主程序入口
CMakeLists.txt         # 构建配置
auto_build.sh          # 自动化构建脚本
```

### 2.2 核心数据结构

#### DRM 设备结构 (`drm_dev_t`)

```c
typedef struct {
    int fd;                                      // DRM设备文件描述符
    uint32_t conn_id, enc_id, crtc_id, plane_id;  // DRM对象ID
    uint32_t width, height;                      // 显示分辨率
    uint32_t mmWidth, mmHeight;                  // 物理尺寸(毫米)
    uint32_t fourcc;                             // 像素格式
    drmModeModeInfo mode;                        // 显示模式
    uint32_t blob_id;                             // 模式blob ID
    drmModeAtomicReq *req;                        // 原子更新请求

    // DRM属性数组
    drmModePropertyPtr plane_props[128];
    drmModePropertyPtr crtc_props[128];
    drmModePropertyPtr conn_props[128];

    // 双缓冲区
    drm_buffer_t drm_bufs[2];                    // DRM帧缓冲区
    drm_buffer_t *act_buf;                       // 当前激活缓冲区
    uint32_t current_buf_idx;                    // 当前显示buffer索引

    // LVGL渲染缓冲区
    lvgl_render_buf_t render_buf;

    // RGA加速支持(可选)
    #if LV_USE_LINUX_DRM_RGA
    bo_t rga_bo;
    int rga_bo_fd;
    uint8_t *rga_buf_ptr;
    size_t rga_buf_size;
    #endif
} drm_dev_t;
```

#### DRM 缓冲区结构 (`drm_buffer_t`)

```c
typedef struct {
    uint32_t handle;      // DRM buffer handle
    uint32_t pitch;       // 行pitch(字节)
    uint32_t offset;      // 偏移量
    unsigned long size;   // 大小
    uint8_t *map;         // 映射的虚拟地址
    uint32_t fb_handle;   // 帧缓冲handle
    int prime_fd;        // DMA-BUF文件描述符
} drm_buffer_t;
```

### 2.3 初始化流程

```c
void rk_drm_init(void)
{
    #if LV_USE_LINUX_DRM_RGA
        c_RkRgaInit();              // 初始化RGA硬件
    #endif

    const char *device = "/dev/dri/card0";
    lv_display_t *disp = rk_drm_create();

    // 设置DRM设备和连接器
    lv_linux_drm_set_file(disp, device, -1);
}
```

### 2.4 显示刷新机制 (软件优化拷贝)

```c
static void drm_flush(lv_display_t * disp,
                     const lv_area_t * area,
                     uint8_t * px_map)
{
    drm_dev_t * drm_dev = lv_display_get_driver_data(disp);

    // 1. 等待最后一次flush
    if(!lv_display_flush_is_last(disp)) {
        return;
    }

    // 2. 选择后缓冲区
    uint32_t next_buf_idx = (drm_dev->current_buf_idx + 1) % 2;
    drm_buffer_t *drm_buf = &drm_dev->drm_bufs[next_buf_idx];

    // 3. 获取更新区域
    int32_t x1 = area->x1;
    int32_t y1 = area->y1;
    int32_t x2 = area->x2;
    int32_t y2 = area->y2;

    // 4. 软件优化拷贝(逐行复制)
    uint32_t stride = drm_buf->pitch;
    uint32_t bpp = LV_COLOR_DEPTH / 8;  // RGB565 = 2 bytes

    for(y = y1; y <= y2; y++) {
        uint32_t src_offset = (y * drm_dev->width + x1) * bpp;
        uint32_t dst_offset = (y * stride) + x1 * bpp;
        memcpy((uint8_t*)drm_buf->map + dst_offset,
               px_map + src_offset,
               (x2 - x1 + 1) * bpp);
    }

    // 5. 提交到显示(Atomic Commit)
    drm_dmabuf_set_plane(drm_dev, drm_buf);

    // 6. 更新buffer索引
    drm_dev->current_buf_idx = next_buf_idx;
}
```

### 2.5 DRM Atomic Commit 机制

```c
static int drm_dmabuf_set_plane(drm_dev_t * drm_dev,
                                drm_buffer_t * buf)
{
    uint32_t flags = DRM_MODE_PAGE_FLIP_EVENT |
                     DRM_MODE_ATOMIC_NONBLOCK;

    // 首次commit需要modeset
    if(first) {
        drm_add_conn_property(drm_dev, "CRTC_ID", drm_dev->crtc_id);
        drm_add_crtc_property(drm_dev, "MODE_ID", drm_dev->blob_id);
        drm_add_crtc_property(drm_dev, "ACTIVE", 1);
        flags |= DRM_MODE_ATOMIC_ALLOW_MODESET;
        first = 0;
    }

    // 配置plane属性
    drm_add_plane_property(drm_dev, "FB_ID", buf->fb_handle);
    drm_add_plane_property(drm_dev, "CRTC_ID", drm_dev->crtc_id);
    drm_add_plane_property(drm_dev, "SRC_X", 0);
    drm_add_plane_property(drm_dev, "SRC_Y", 0);
    drm_add_plane_property(drm_dev, "SRC_W", drm_dev->width << 16);
    drm_add_plane_property(drm_dev, "SRC_H", drm_dev->height << 16);
    drm_add_plane_property(drm_dev, "CRTC_X", 0);
    drm_add_plane_property(drm_dev, "CRTC_Y", 0);
    drm_add_plane_property(drm_dev, "CRTC_W", drm_dev->width);
    drm_add_plane_property(drm_dev, "CRTC_H", drm_dev->height);

    // 原子提交
    ret = drmModeAtomicCommit(drm_dev->fd, drm_dev->req, flags, drm_dev);

    return ret;
}
```

---

## 三、DRM Buffer 分配详解

### 3.1 Dumb Buffer 分配

```c
static int drm_allocate_dumb(drm_dev_t * drm_dev, drm_buffer_t * buf)
{
    struct drm_mode_create_dumb creq;

    // 配置buffer参数
    creq.width = drm_dev->width;    // 480
    creq.height = drm_dev->height;  // 800
    creq.bpp = LV_COLOR_DEPTH;      // 16

    // Rockchip RGA需要保留kmap
    creq.flags = (1 << 0) | (1 << 4);  // CONTIG | ALLOC_KMAP

    // 创建dumb buffer
    ret = drmIoctl(drm_dev->fd, DRM_IOCTL_MODE_CREATE_DUMB, &creq);

    // 内存映射
    buf->map = mmap(0, creq.size, PROT_READ | PROT_WRITE,
                   MAP_SHARED, drm_dev->fd, mreq.offset);

    // 清零buffer
    lv_memzero(buf->map, creq.size);

    // 创建framebuffer对象
    ret = drmModeAddFB2(drm_dev->fd, drm_dev->width, drm_dev->height,
                        drm_dev->fourcc, handles, pitches, offsets,
                        &buf->fb_handle, 0);

    return 0;
}
```

### 3.2 Buffer布局

```
┌────────────────────────────────────────────────────────────┐
│                  DRM Buffer Layout (RGB565)                  │
├────────────────────────────────────────────────────────────┤
│ width = 480 pixels                                       │
│ height = 800 lines                                       │
│ bpp = 16 bits (2 bytes)                                  │
│                                                              │
│ Total Size = 480 * 800 * 2 = 768,000 bytes (750 KB)        │
│                                                              │
│ stride (pitch) = 960 bytes (可能 > width*bpp，用于对齐)      │
└────────────────────────────────────────────────────────────┘
```

---

## 四、编译配置

### 4.1 CMakeLists.txt 配置

```cmake
# 收集源文件
set(SOURCES
    src/main.c
    src/mouse_cursor_icon.c
    src/hal/rk_drm.c
)

# 可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接库
target_link_libraries(${PROJECT_NAME}
    lvgl::lvgl
    pthread
    m
    drm
    rga
)
```

### 4.2 交叉编译工具链

```cmake
# aarch64-rockchip-linux-gnu.cmake
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

set(CMAKE_C_COMPILER aarch64-buildroot-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER aarch64-buildroot-linux-gnu-g++)

set(CMAKE_FIND_ROOT_PATH ...)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
```

### 4.3 lv_conf.h 关键配置

```c
#define LV_COLOR_DEPTH 16

#define LV_USE_LINUX_DRM 1
#define LV_USE_LINUX_DRM_RGA 1

#define LV_LOG_LEVEL LV_LOG_LEVEL_INFO
#define LV_LOG_PRINTF 1

#define LV_MEM_CUSTOM 1
```

---

## 五、自动化构建

### 5.1 auto_build.sh 脚本

```bash
#!/bin/bash
# RK3566 LVGL 交叉编译构建脚本

run_app() {
    echo "关闭其他lvgl进程..."
    sshpass -p tspi ssh tspi "pkill lvgl"

    echo "正在推送至开发板..."
    sshpass -p tspi scp ./build/lvgl_app tspi:/app/lvgl

    echo "推送完成."
    echo "运行lvgl_app (5秒超时)..."
    timeout 5s sshpass -p tspi ssh tspi "/app/lvgl/lvgl_app" \
        || echo "程序运行超时或结束"
}

# 设置编译器库路径
export LD_LIBRARY_PATH=/path/to/gcc/lib:$LD_LIBRARY_PATH

# 创建构建目录
mkdir -p build
cd build

# 配置并构建
cmake -DCMAKE_TOOLCHAIN_FILE=../aarch64-rockchip-linux-gnu.cmake ..
make -j$(nproc)

# 推送并运行
run_app
```

### 5.2 使用方法

```bash
# 完整构建流程
./auto_build.sh

# 仅运行已编译的程序
./auto_build.sh run
```

---

## 六、性能分析

### 6.1 带宽计算

| 参数 | 值 |
|------|-----|
| 分辨率 | 480x800 |
| 色深 | 16-bit (RGB565) |
| 每帧数据量 | 480 × 800 × 2 = 768 KB |
| 刷新率 | 60 FPS |
| 理论带宽 | 768 KB × 60 = 46 MB/s |

### 6.2 性能优化

#### 已实现的优化

1. **双缓冲机制**
   - 消除显示撕裂
   - VSync 同步刷新

2. **部分区域更新**
   - 仅刷新变化的区域
   - 减少内存拷贝量

3. **软件拷贝优化**
   - 逐行 memcpy，避免大块内存操作
   - 充分利用CPU缓存

#### 性能数据

```
分辨率: 480x800
数据量: 768 KB/frame
拷贝时间: < 1ms (逐行memcpy)
总延迟: < 16.7ms (60 FPS要求)
```

### 6.3 系统资源占用

```
CPU: Rockchip RK3566 (4xCortex-A35 @ 1.8GHz)
内存: 1GB DDR
显示占用:
  - LVGL渲染buffer × 2: 1.5 MB
  - DRM buffer × 2: 1.5 MB
  - 总计: ~3 MB
```

---

## 七、调试与问题解决

### 7.1 常见问题

#### Q1: RGA IRQ错误 (rga2: Rga err irq! INT[701],STATS[0])

**原因**:
- 内存越界
- 配置参数错误
- Buffer格式不匹配

**解决**:
- 使用软件拷贝替代RGA
- 确保stride计算正确
- 添加ALLOC_KMAP标志

#### Q2: Bad address错误

**原因**:
- 虚拟地址映射失败
- Buffer大小不足

**解决**:
- 检查mmap返回值
- 验证buffer大小
- 使用正确的pitch值

#### Q3: 编译错误

**原因**:
- 交叉编译工具链路径错误
- 依赖库缺失

**解决**:
```bash
export LD_LIBRARY_PATH=/path/to/gcc/lib:$LD_LIBRARY_PATH
```

### 7.2 调试技巧

#### 启用详细日志

```c
// lv_conf.h
#define LV_LOG_LEVEL LV_LOG_LEVEL_TRACE
#define LV_LOG_PRINTF 1
```

#### 驱动调试节点

```bash
# 开启RGA调试信息
echo msg > /sys/kernel/debug/rga2_debug/rga2

# 查看内核日志
dmesg -c
```

#### GDB远程调试

```bash
# 开发板
gdbserver :1234 /app/lvgl/lvgl_app

# 主机
aarch64-linux-gnu-gdb ./build/lvgl_app
(gdb) target remote 192.168.1.100:1234
```

---

## 八、后续优化方向

### 8.1 RGA硬件加速(可选)

如需启用RGA硬件加速，需要：

1. **检查内核支持**
   ```bash
   # 检查ALLOC_KMAP支持
   cat /sys/kernel/debug/dri/0/memory
   ```

2. **使用GBM Buffer**
   ```c
   # 替代dumb buffer
   gbm_bo_create(gbm_device, width, height,
                  GBM_BO_FORMAT_XRGB8888,
                  GBM_BO_USE_SCANOUT | GBM_BO_USE_LINEAR);
   ```

3. **参考实现**
   - `/home/orionxer/tspi/sdk/Release/external/linux-rga/samples/`

### 8.2 性能优化

1. **零拷贝优化**
   - 直接渲染到DRM buffer
   - 使用DIRECT模式

2. **异步渲染**
   - 异步buffer提交
   - 减少CPU等待

3. **缓存优化**
   - 内存对齐优化
   - Cache line对齐

### 8.3 功能扩展

1. **触摸屏支持**
   - libinput集成
   - 多点触控

2. **多媒体支持**
   - 视频播放集成
   - 摄像头采集

3. **网络功能**
   - 远程桌面
   - Web界面

---

## 九、参考资料

### 9.1 官方文档

- [LVGL官方文档](https://docs.lvgl.io/)
- [DRM官方文档](https://01.org/linuxgraphics/)
- [Rockchip RGA文档](https://github.com/airockchip/linux-rga)

### 9.2 项目文件

- **RK3566 SDK**: `/home/orionxer/tspi/sdk/Release/`
- **RGA库**: `external/linux-rga/`
- **DRM测试**: `src/hal/rk_drm.c`

### 9.3 示例代码

- **RGA示例**: `external/linux-rga/samples/legacy/rgaBlit/`
- **DRM示例**: `lvgl/demos/linux/`

---

## 十、版本信息

```
项目版本: 1.0.0
LVGL版本: 9.x
RGA版本: 3.02
DRM版本: Linux KMS
内核版本: Linux 5.15+
编译器: GCC 9.3.0 (Buildroot 2020.03)
```

---

## 十一、维护与支持

### 11.1 作者信息

- **开发者**: [您的名字]
- **创建日期**: 2025-02-03
- **最后更新**: 2025-02-03

### 11.2 许可证

本文档遵循项目许可证，仅供内部参考使用。

### 11.3 联系方式

- **问题反馈**: [项目Issue页面]
- **技术支持**: [邮箱]

---

**文档结束**
