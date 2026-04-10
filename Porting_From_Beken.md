# Beken LVGL UI Designer 移植指南

## 官方仓库
[官方github仓库](https://github.com/bekencorp/lvgl_ui_designer)

## lvgl_ui_designer 如何导出 UI
1. 打开 lvgl_ui_designer，设计好 UI 页面
2. 右上角找到 `C Language`下拉框，选择 `Generate Code`
3. 在工程根目录下找到 `beken_generated` 文件夹，里面就是导出的代码
4. 将 `beken_generated` 文件夹复制到本项目的 `src/` 目录下

## 移植说明

### 文件目录

`src`目录结构
```sh
src/
├── beken_generated # 从 lvgl_ui_designer 导出的代码
└── main.c
```

## CMake 说明
顶层`CMakeLists.txt`只需要添加一行代码来包含导出的 CMake 文件即可：
```cmake
include(src/beken_generated/beken_generated.cmake)
```
`beken_generated.cmake` 会自动递归收集 `src/beken_generated/` 下的 `.c` 文件和头文件目录，并把它们添加到 `main` 目标中编译。

## main.c 说明
```c
#include "beken_ui.h"
int main()
{
    // 初始化 LVGL
    lv_init();
    // 初始化SDL 或者其他 HAL 硬件层
    sdl_hal_init(xxx, xxx); 

    // 初始化 Beken UI Designer 导出的页面
    beken_ui_init();

    // 进入 LVGL 任务循环
    while (1) {
    }

    return 0;
}
```

### 启动流程说明
- `main.c` 在 `lv_init()` 和 `sdl_hal_init()` 之后调用 `beken_ui_init()`
- `beken_ui_init()` 负责创建页面并加载默认屏幕

### 注意
- Page重命名或更换项目，最好把 `beken_generated`文件夹删除后再导入一次