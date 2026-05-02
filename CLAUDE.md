# 项目说明

## 项目概述
实现一个模拟时钟应用，尽可能一比一参考子仓库 lvgl_clock

## 屏幕
- 分辨率：390x450

## 技术栈
- 编程语言：C
- LVGL：v9.4.0

## 开发环境设置
不需要前置条件，直接参考 [#编译命令] 和 [#运行命令] 即可

## 项目结构
```sh
.
├── FreeRTOS # 子仓库，不能修改
├── Porting_From_Beken.md
├── auto_build.sh # 自动构建脚本
├── bin # 可执行文件目录
├── build # 构建目录
├── lvgl # 子仓库，不能修改
└── src # 源代码目录
    ├── beken_generated # 参考 Porting_From_Beken.md 生成的代码
    ├── freertos
    ├── freertos_main.c
    ├── hal
    ├── main.c
    ├── mouse_cursor_icon.c
    └── watch_ui # 此处实现时钟界面相关代码
```

## 开发规范
1. 代码风格：4空格缩进
2. 代码lint: 用户如果没有明确指定，不要进行LSP相关检查


## 编译命令
```sh
mkdir -p build && cd build && cmake -G "Unix Makefiles" .. && make -j16 && cd ..
```

## 运行命令
```sh
./bin/main
```

## 注意事项
- 使用 `rg` 代替 `grep` 进行代码搜索
- 使用 `fd` 代替 `find` 进行文件搜索

