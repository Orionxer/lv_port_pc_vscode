#!/bin/bash
# RK3566 LVGL 交叉编译构建脚本

# 设置编译器库路径
export LD_LIBRARY_PATH=/home/orionxer/tspi/sdk/Release/prebuilts/gcc/linux-x86/aarch64/gcc-buildroot-9.3.0-2020.03-x86_64_aarch64-rockchip-linux-gnu/lib:$LD_LIBRARY_PATH
# 创建构建目录
# rm -rf build # 手动清理构建项目
mkdir -p build
cd build

# 配置并构建
cmake --no-warn-unused-cli -DCMAKE_TOOLCHAIN_FILE=../aarch64-rockchip-linux-gnu.cmake .. || exit 1
make -j$(nproc)
cd ..

# 如果配置好SSH，可以主动推送至开发板
echo "正在推送至开发板..."
sshpass -p tspi scp ./build/lvgl_app tspi:/app/lvgl
echo "推送完成."
# 关闭其他lvgl进程
echo "关闭其他lvgl进程..."
sshpass -p tspi ssh tspi "pkill lvgl"
# 运行
echo "运行lvgl_app..."
sshpass -p tspi ssh tspi "/app/lvgl/lvgl_app"