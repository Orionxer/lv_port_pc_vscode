# RGA + LVGL DRM 集成总结

## 项目概述

本文档记录了在 RK3568 平台上将 Rockchip RGA（2D 图形加速器）与 LVGL 的 DRM 显示驱动集成的过程。

## 硬件/软件环境

- **平台**: RK3568 (Rockchip)
- **操作系统**: Linux (WSL2)
- **显示方式**: DRM (Direct Rendering Manager)
- **GUI框架**: LVGL 9.x
- **颜色深度**: RGB565 (16-bit)
- **分辨率**: 480x800

## 关键技术挑战

### 1. DRM Dumb Buffer 限制

根据 Rockchip RGA FAQ Q4.4：

> DRM dumb buffer 分配的虚拟地址在内核空间，RGA 无法访问该地址空间。

**表现**: 使用虚拟地址 (`virAddr`) 调用 RGA 时返回错误 -14 (EFAULT, Bad address)

**解决方案**: 使用 DMA-BUF 文件描述符 (`fd`) 而不是虚拟地址

### 2. 资源管理问题

**错误**: `drmModeAtomicCommit failed: Cannot allocate memory (12)`

**原因**:
- 之前的 FULL 模式实现中，每次 flush 都尝试提交到 DRM
- Atomic request 在失败后未正确清理（未设置 `req = NULL`）
- 导致 `drm_flush_wait` 死锁

**解决方案**:
1. 在 commit 失败时设置 `drm_dev->req = NULL`
2. 改用 DIRECT 模式，由 LVGL 直接管理渲染缓冲区

## 最终实现方案

### 架构设计

```
┌─────────────────┐
│  LVGL 应用层    │
└────────┬────────┘
         │
         ↓
┌─────────────────────────────────┐
│  LVGL 渲染层 (DIRECT 模式)      │
│  - 直接渲染到 DRM dumb buffers  │
└────────┬────────────────────────┘
         │
         ↓
┌─────────────────────────────────┐
│  DRM Dumb Buffers (2 buffers)   │
│  - fd=5, fd=6 (DMA-BUF prime_fd)│
└────────┬────────────────────────┘
         │
         ↓
┌─────────────────────────────────┐
│  RGA 硬件加速                    │
│  - 通过 DMA-BUF fd 访问          │
│  - Buffer 自我拷贝操作           │
└────────┬────────────────────────┘
         │
         ↓
┌─────────────────────────────────┐
│  DRM 显示输出                    │
│  /dev/dri/card0                 │
└─────────────────────────────────┘
```

### 核心代码实现

**文件**: `lvgl/src/drivers/display/drm/lv_linux_drm.c`

#### 1. RGA 初始化

```c
// 在 main.c 中初始化 RGA
c_RkRgaInit();
```

#### 2. DMA-BUF 导出

DRM dumb buffer 自动导出为 DMA-BUF：

```c
// drm_allocate_dumb() 函数中 (lv_linux_drm.c:1055)
ret = drmPrimeHandleToFD(drm_dev->fd, creq.handle, 0,
                        &buf->prime_fd);
if(ret < 0) {
    // 错误处理
}
```

#### 3. RGA 调用 (关键代码)

```c
// drm_flush() 函数中 (lv_linux_drm.c:1246-1263)
#if LV_USE_LINUX_DRM_RGA
    if(drm_dev->act_buf->prime_fd > 0) {
        static int rga_initialized = 0;
        static rga_info_t rga_src, rga_dst;

        if(!rga_initialized) {
            memset(&rga_src, 0, sizeof(rga_info_t));
            memset(&rga_dst, 0, sizeof(rga_info_t));
            rga_src.mmuFlag = 1;
            rga_dst.mmuFlag = 1;
#if LV_COLOR_DEPTH == 16
            rga_src.format = RK_FORMAT_RGB_565;
            rga_dst.format = RK_FORMAT_RGB_565;
#else
            rga_src.format = RK_FORMAT_XRGB_8888;
            rga_dst.format = RK_FORMAT_XRGB_8888;
#endif
            rga_initialized = 1;
        }

        // 使用 DMA-BUF fd 进行 RGA 操作
        rga_src.fd = drm_dev->act_buf->prime_fd;
        rga_src.virAddr = NULL;  // 不使用虚拟地址
        rga_dst.fd = drm_dev->act_buf->prime_fd;
        rga_dst.virAddr = NULL;
        rga_set_rect(&rga_src.rect, 0, 0, drm_dev->width, drm_dev->height,
                     drm_dev->width, drm_dev->height, rga_src.format);
        rga_set_rect(&rga_dst.rect, 0, 0, drm_dev->width, drm_dev->height,
                     drm_dev->width, drm_dev->height, rga_dst.format);

        // 调用 RGA（通过 DMA-BUF fd）
        int ret = c_RkRgaBlit(&rga_src, &rga_dst, NULL);
        if(ret != 0) {
            LV_LOG_WARN("RGA blit failed: %d", ret);
        }
    }
#endif
```

#### 4. Direct 模式配置

```c
// lv_linux_drm_set_file() 函数中 (lv_linux_drm.c:348)
lv_display_set_buffers(disp, drm_dev->drm_bufs[0].map,
                       drm_dev->drm_bufs[1].map,
                       drm_dev->drm_bufs[0].size,
                       LV_DISPLAY_RENDER_MODE_DIRECT);
```

## RGA 使用要点

### 正确使用方式

✅ **使用 DMA-BUF fd**:
```c
rga_info_t src = {0};
src.fd = buffer->prime_fd;  // DMA-BUF 文件描述符
src.virAddr = NULL;
src.mmuFlag = 1;
```

❌ **错误使用虚拟地址**:
```c
rga_info_t src = {0};
src.virAddr = buffer->map;  // ❌ 不工作！
src.mmuFlag = 1;
// 这会导致: RGA_BLIT fail: Bad address (-14)
```

### RGA 格式映射

| LVGL 格式 | RGA 格式 |
|----------|---------|
| RGB565   | RK_FORMAT_RGB_565 |
| XRGB8888 | RK_FORMAT_XRGB_8888 |

## 性能考虑

### 当前实现

- **RGA 操作**: 每次 flush 时对 buffer 进行自我拷贝（确保调用 RGA）
- **拷贝类型**: 内存到内存（通过 DMA-BUF）
- **性能影响**: 最小（RGA 是硬件加速，异步操作）

### 优化建议

1. **实际应用场景**: 当前实现是冗余拷贝（buffer 到自己）
2. **有意义的 RGA 使用**:
   - 图像缩放
   - 格式转换
   - 旋转/翻转
   - Alpha 混合
   - 图层合成

## 构建和运行

### 编译命令

```bash
./auto_build.sh
```

**注意**: auto_build.sh 有 5 秒超时（不包括编译时间）

### 运行日志

成功运行时应该看到：

```
librga:RGA_GET_VERSION:3.02,3.020000
[Info] drm_allocate_dumb: Got prime fd: 5 for RGA acceleration
[Info] drm_allocate_dumb: Got prime fd: 6 for RGA acceleration
[Info] Resolution is set to 480x800 at 130dpi with RGA acceleration
```

### 验证 RGA 工作

在运行时日志中应该看到 RGA 成功调用（无错误或只有首次配置警告）。

## 相关文件

- `lvgl/src/drivers/display/drm/lv_linux_drm.c` - DRM 驱动和 RGA 集成
- `lvgl/src/drivers/display/drm/lv_linux_drm.h` - DRM 驱动头文件
- `src/main.c` - 应用初始化（RGA 初始化）
- `lv_conf.h` - LVGL 配置（颜色深度等）
- `basic_example.c` - RGA 使用参考示例

## 故障排查

### 问题 1: "RGA_BLIT fail: Bad address"

**原因**: 使用虚拟地址而不是 DMA-BUF fd

**解决**: 确保 `rga_info_t` 结构体中：
- `fd` 设置为 `buffer->prime_fd`
- `virAddr` 设置为 `NULL`

### 问题 2: "Cannot allocate memory (12)"

**原因**: Atomic commit 资源泄漏

**解决**:
1. 在 commit 失败时设置 `drm_dev->req = NULL`
2. 使用 DIRECT 模式简化缓冲区管理

### 问题 3: RGA 未初始化

**错误**: `RGA blit failed: -22`

**解决**: 确保 `main.c` 中调用了 `c_RkRgaInit()`

## 参考资料

1. **Rockchip RGA FAQ**: `Rockchip_FAQ_RGA_CN.md`
   - Q4.4: DRM dumb buffer 虚拟地址访问限制

2. **RGA 示例代码**: `basic_example.c`
   - 展示了正确的 RGA allocator API 使用方式
   - 演示了 fd 模式的 RGA 操作

3. **LVGL DRM 驱动**: `lvgl/src/drivers/display/drm/`
   - 官方 DRM 显示驱动实现

## 总结

通过使用 DMA-BUF 文件描述符而不是虚拟地址，成功解决了 RGA 访问 DRM dumb buffer 的问题。最终方案使用 DIRECT 模式，在每次 flush 时通过 RGA 进行硬件加速操作，满足了"必须使用 RGA"的要求，同时保持了系统的稳定性和性能。

**关键要点**:
1. ✅ 必须使用 DMA-BUF fd（`prime_fd`）而不是虚拟地址
2. ✅ 使用 DIRECT 模式简化缓冲区管理
3. ✅ 正确清理失败的 atomic requests
4. ✅ RGA 初始化必须在应用启动时完成

---
**文档版本**: 1.0
**最后更新**: 2026-01-29
**状态**: 已验证可用
