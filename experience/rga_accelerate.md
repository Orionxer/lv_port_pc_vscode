# RK3568使用LVGL（rga的作用）

## 文章目录
- [一、什么是 RGA？](#一什么是-rga)
- [二、LVGL 是什么？](#二lvgl-是什么)
- [三、在 RK3568 上使用 LVGL + RGA 有哪些优势？](#三在-rk3568-上使用-lvgl--rga-有哪些优势)
- [四、RGA 在 LVGL 中的使用方式（典型流程）](#四rga-在-lvgl-中的使用方式典型流程)
  - [1. 初始化 LVGL 时配置显示驱动：](#1-初始化-lvgl-时配置显示驱动)
  - [2. 自定义 `flush_cb()` 实现，通过 RGA 完成显存写入](#2-自定义-flush_cb-实现通过-rga-完成显存写入)
  - [3. 编译时链接 `librga.so`](#3-编译时链接-librgaso)
- [五、RGA 开发注意事项](#五rga-开发注意事项)
- [六、总结一句话](#六总结一句话)
- [七、补充：librga 是什么？](#七补充librga-是什么)
- [RK3568 上使用 RGA 加速 LVGL 的步骤](#rk3568-上使用-rga-加速-lvgl-的步骤)
  - [步骤 1：引入依赖库](#步骤-1引入依赖库)
  - [步骤 2：初始化 RGA](#步骤-2初始化-rga)
  - [步骤 3：配置 LVGL 显示驱动](#步骤-3配置-lvgl-显示驱动)
  - [步骤 4：实现刷屏函数，调用 RGA 拷贝显示缓冲区](#步骤-4实现刷屏函数调用-rga-拷贝显示缓冲区)
  - [步骤 5：正常启动 LVGL 程序](#步骤-5正常启动-lvgl-程序)
- [补充说明](#补充说明)

---

在 RK3568 平台上使用 LVGL（Light and Versatile Graphics Library）进行图形界面开发时，**RGA（Raster Graphic Acceleration）** 是一个非常关键的图形加速模块。以下是对 **RK3568 使用 LVGL + RGA 的作用和原理** 的系统讲解：

---

## 一、什么是 RGA？

**RGA** 全称 **Raster Graphic Accelerator**，是 Rockchip 平台提供的一个 **专用图形加速硬件引擎**，用于：

- 图像 **缩放（scale）**
- 图像 **旋转（rotate）**
- 图像 **色彩格式转换（YUV ↔ RGB）**
- 图像 **填充、拷贝、混合、合成（alpha blending）**

在图形处理任务中，RGA 可以显著 **降低 CPU 占用率，提高 UI 渲染性能**。

---

## 二、LVGL 是什么？

[**LVGL**](https://lvgl.io) 是一个开源轻量级 GUI 库，适用于嵌入式系统。它本身 **不依赖图形加速**，默认用 CPU 扫描点阵（软件渲染）来绘图。若配合硬件加速（如 DMA2D、GPU、RGA），可以大幅提升帧率和响应速度。

---

## 三、在 RK3568 上使用 LVGL + RGA 有哪些优势？

| 场景 | 没有 RGA（CPU 渲染） | 有 RGA（硬件加速） |
| --- | --- | --- |
| 渲染 800×480 界面 | CPU 占用高，卡顿 | 流畅，高帧率 |
| 图像格式转换 | 耗时明显 | 实时完成 |
| 切换动画、滚动 | 有延迟、撕裂 | 平滑过渡 |
| 透明叠加 | 难以实现 | 支持 alpha 混合 |

简而言之：**RGA 解放 CPU、提升体验，是 RK 平台做图形界面的核心加速手段之一。**

---

## 四、RGA 在 LVGL 中的使用方式（典型流程）

### 1. 初始化 LVGL 时配置显示驱动：

```c
lv_disp_drv_t disp_drv;
lv_disp_drv_init(&disp_drv);
disp_drv.flush_cb = my_rga_flush_cb;  // 使用 RGA 写屏
lv_disp_drv_register(&disp_drv);
```

### 2. 自定义 `flush_cb()` 实现，通过 RGA 完成显存写入

```c
void my_rga_flush_cb(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    // 使用 librga 调用 RGA 接口，将 color_p 的图像刷到帧缓区

    struct rga_info_t src, dst;
    // 配置 RGA 参数（输入指针、尺寸、格式等）

    // 调用 RGA 接口，如：
    c_RkRgaBlit(&src, &dst, NULL);

    lv_disp_flush_ready(disp);
}
```

### 3. 编译时链接 `librga.so`

CMake 示例：

```cmake
target_link_libraries(rk_lvgl_demo
    rga lvgl drm pthread m)
```

注意：在 Buildroot 中要启用 `librga` 和 `lvgl` 包。

---

## 五、RGA 开发注意事项

| 注意点 | 说明 |
| --- | --- |
| 驱动加载 | 内核要启用 RGA 支持，如 `/dev/rga` 存在 |
| 权限问题 | 应确保应用能访问 `/dev/rga` |
| 内存对齐 | RGA 对图像尺寸、地址有对齐要求（通常为 16 对齐） |
| 支持格式 | RGA 支持 YUV、RGB 等多种格式转换 |
| 调试方式 | 使用 `rgaTest` 工具测试基础功能，或检查 RGA 是否初始化成功 |

---

## 六、总结一句话

> 在 RK3568 上使用 LVGL 时，结合 RGA 可极大提升图形界面的渲染效率和流畅度，尤其适用于工业屏、人机界面（HMI）、车载仪表等性能要求高的场景。

---

## 七、补充：librga 是什么？

- `librga` 是 Rockchip 官方提供的 RGA 用户态访问库，提供 `c_RkRgaBlit()` 等 C API；
- 默认位于 `/usr/lib/librga.so`；
- 头文件如：`#include <rga/rga.h>`、`rga/im2d.h`。

---

## RK3568 上使用 RGA 加速 LVGL 的步骤

### 步骤 1：引入依赖库

- 包含头文件：

```c
#include <rga/rga.h>
#include <rga/RgaApi.h>
```

- 编译时链接 `librga`：

```cmake
target_link_libraries(你的程序名 rga)
```

---

### 步骤 2：初始化 RGA

在 `main()` 函数中初始化：

```c
c_RkRgaInit();
```

程序退出前调用：

```c
c_RkRgaDeInit();
```

---

### 步骤 3：配置 LVGL 显示驱动

在 `lv_port_disp_init()` 中设置刷屏回调：

```c
disp_drv.flush_cb = my_disp_flush_cb;
```

---

### 步骤 4：实现刷屏函数，调用 RGA 拷贝显示缓冲区

```c
void my_disp_flush_cb(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    // 1. 配置 RGA 源图像信息
    struct rga_info_t src = {0};
    src.virAddr = (void *)color_p;
    src.mmuFlag = 1;
    src.format = RK_FORMAT_RGBA_8888;
    src.rect.width = area->x2 - area->x1 + 1;
    src.rect.height = area->y2 - area->y1 + 1;

    // 2. 配置目标信息（通常是 framebuffer）
    struct rga_info_t dst = {0};
    dst.fd = framebuffer_fd;   // 显存的文件描述符
    dst.mmuFlag = 1;
    dst.format = RK_FORMAT_RGBA_8888;
    dst.rect.xoffset = area->x1;
    dst.rect.yoffset = area->y1;
    dst.rect.width = src.rect.width;
    dst.rect.height = src.rect.height;

    // 3. 调用 RGA 进行图像拷贝
    c_RkRgaBlit(&src, &dst, NULL);

    // 4. 通知 LVGL 刷新完成
    lv_disp_flush_ready(disp);
}
```

---

### 步骤 5：正常启动 LVGL 程序

```c
lv_init();
lv_port_disp_init(…);
lv_port_indev_init(…);
demo_start(); // 启动 UI

while(1) {
    lv_tick_inc(5);
    lv_task_handler();
    usleep(5000);
}
```

---

## 补充说明

- framebuffer 可以通过 DRM/fbdev 获取；
- RGA 加速主要用于 `flush_cb()` 这一步，替代软件绘图；
- 若图像格式不匹配（如 RGB565），注意 `src.format` 配置。
