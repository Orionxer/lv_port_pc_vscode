# LVGL9.4 + Gui Guider 移植 (Windows)

> 本项目基于LVGL官方仓库 [lv_port_pc_vscode](https://github.com/lvgl/lv_port_pc_vscode) Fork，实现了在Windows下模拟LVGL 9.4.0的运行环境，并将Gui Guider的Demo: SmartAppliance移植到该环境中运行，其余Demo同理。

## 下载项目
```bash
git clone --recursive https://github.com/orionxer/lv_port_pc_vscode
```

## 环境
检查`gcc`,`g++`, `make`, `cmake`编译环境，如果不具备则安装mingw64和cmake

### Mingw64下载安装
下载已经编译好的mingw64版本[mingw-build-binaries](https://github.com/niXman/mingw-builds-binaries/releases),选择类似于`x86_64-15.2.0-release-posix-seh-ucrt-rt_v13-rev0.7z`的版本下载并解压到D盘下，例如`D:\mingw64`,则PATH的系统环境变量应该添加`D:\mingw64\bin`，注意，在该目录下把`mingw32-make.exe`复制一份并重命名为`make.exe`。

### CMake下载安装

下载cmake的安装包[cmake](https://cmake.org/download/)，选择类似于`cmake-4.1.2-windows-x86_64.zip`的版本，解压到D盘下，例如`D:\cmake-4.1.2-windows-x86_64`,则PATH的系统环境变量应该添加`D:\cmake-4.1.2-windows-x86_64\bin`。

### Vcpkg下载安装
在D盘下克隆vcpkg的仓库，[教程：通过 CMake 安装和使用包](https://learn.microsoft.com/zh-cn/vcpkg/get_started/get-started?pivots=shell-powershell)
```sh
git clone https://github.com/microsoft/vcpkg.git
```
进入vcpkg目录，执行启动脚本
```sh
cd vcpkg; .\bootstrap-vcpkg.bat
```
环境变量PATH添加`D:\vcpkg`
### 检查环境
```sh
gcc --version
```
```sh
g++ --version
```
```sh
make --version
```
```sh
cmake --version
```
```sh
vcpkg --version
```

## 安装SDL2环境
```sh
vcpkg install sdl2:x64-mingw-static
```
则安装好的SDL2的路径应该是`D:\vcpkg\installed\x64-mingw-static\share\sdl2`

## 编译
创建并进入build目录
```sh
mkdir build && cd build
```
生成Makefile
```sh
cmake -G "MinGW Makefiles" ..
```
编译项目
```sh
make -j16
```
## 运行
进入`bin`目录找到`main.exe`双击运行
```sh
cd ../bin; ./main.exe
```

## 说明
默认运行了Gui Guider的Demo: SmartAppliance, 其中`src`目录下的`custome`和`generated`目录为Gui Guider导出的代码，详细导出步骤与CMakefile说明参考博客[TODO]()
`src`目录结构如下
```sh
src/
├── custom
├── freertos
├── freertos_main.c
├── generated
├── hal
├── main.c
└── mouse_cursor_icon.c
```