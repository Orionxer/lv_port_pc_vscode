# RGA (Raster Graphic Acceleration) 使用说明

本文档记录了如何在 `lv_port_pc_vscode` 工程中集成和使用 Rockchip RGA 硬件加速库。

## 1. 简介

RGA (Raster Graphic Acceleration) 是 Rockchip 平台特有的 2D 图形加速引擎，支持图像缩放、旋转、格式转换、合成等操作。在本项目中，我们集成了 RGA 库以便利用硬件加速能力。

## 2. 工程配置

### MakeLists.txt 修改

为了让工程能够编译和链接 RGA 库，需要在 `CMakeLists.txt` 中添加头文件路径和库链接配置。

**1. 头文件路径**

添加 `rga` 的头文件搜索路径：

```cmake
# RGA 头文件路径
include_directories(
    /sdk/media/rga/out/include
)
```

**2. 库链接配置**

设置 RGA 库路径并链接静态库 `librga.a`（或动态库 `librga.so`，视环境而定，本例优先使用静态链接以减少运行时依赖问题）：

```cmake
# RGA库路径
set(RGA_PATH "/sdk/media/rga/out")
# 如果需要动态链接，可以添加 link_directories(${RGA_PATH}/lib)

# 链接库
target_link_libraries(${PROJECT_NAME}
    lvgl::lvgl
    pthread
    m
    rt
    ${LIBDRM_PATH}/lib/libdrm.so
    ${RGA_PATH}/lib/librga.a  # 链接静态库
)
```

## 3. 代码集成

在源文件中（如 `src/main.c`），需要包含相关头文件并进行初始化。

### 头文件引用

```c
#include <rga/im2d.h>
#include <rga/RgaApi.h>
```

### 初始化与测试

在使用 RGA 功能前，建议调用 `c_RkRgaInit()` 进行初始化（尽管较新版本的 Librga 在调用 API 时会自动初始化，但显式初始化有助于尽早发现环境问题）。

可以通过 `querystring(RGA_ALL)` 获取当前 RGA 库的版本信息。

示例代码：

```c
void rga_test(void)
{
    printf("---------- RGA INFO START ----------\n");
    
    // 初始化 RGA
    int ret = c_RkRgaInit();
    if (ret != 0) {
        printf("RGA init failed! ret=%d\n", ret);
    } else {
        printf("RGA init success!\n");
    }

    // 打印版本信息 (包含 librga version, driver version 等)
    // 需包含 <rga/im2d.h>
    printf("%s", querystring(RGA_ALL));

    // 反初始化 (程序退出前调用)
    c_RkRgaDeInit();
    
    printf("----------- RGA INFO END -----------\n");
}
```

## 4. 常用 API 说明

集成完成后，通过 `#include <rga/im2d.h>` 可以使用 IM2D API（推荐），这是一套更易用的 C++ 风格封装（也兼容 C），常用函数包括：

- `imcheck()`: 检查当前硬件是否支持某些操作。
- `imresize()`: 图像缩放。
- `imcvtcolor()`: 格式转换。
- `imcrop()`: 图像裁剪。
- `improcess()`: 综合处理，执行 `rga_buffer_t` 描述的任务。

详细 API 参考请查阅 SDK 目录下的文档：
- 路径: `/sdk/media/rga/rga/docs/`
- 头文件: `/sdk/media/rga/out/include/rga/im2d.h`

## 5. 参考资源

- **RGA SDK 路径**: `/sdk/media/rga`
- **头文件**: `/sdk/media/rga/out/include`
- **库文件**: `/sdk/media/rga/out/lib`
- **示例代码**: `/sdk/media/rga/samples` (包含基础的 resize, copy, crop 等 demo)
