#!/bin/bash
# RK3566 LVGL 交叉编译构建脚本

run_app() {
    echo "关闭其他lvgl进程..."
    sshpass -p tspi ssh tspi "pkill lvgl"
    echo "正在推送至开发板..."
    sshpass -p tspi scp ./build/lvgl_app tspi:/app/lvgl
    echo "推送完成."
    echo "运行lvgl_app..."
    timeout 5s sshpass -p tspi ssh tspi "/app/lvgl/lvgl_app" || echo "程序运行超时或结束"
    # sshpass -p tspi ssh tspi "/app/lvgl/lvgl_app" || echo "程序运行超时或结束"
}

# 接收参数，如果只有run，则只运行不编译
if [ "$1" == "run" ]; then
    echo "只运行已编译的程序..."
    run_app
    exit 0
fi

# 设置编译器库路径
export LD_LIBRARY_PATH=/home/orionxer/tspi/sdk/Release/prebuilts/gcc/linux-x86/aarch64/gcc-buildroot-9.3.0-2020.03-x86_64_aarch64-rockchip-linux-gnu/lib:$LD_LIBRARY_PATH
# 创建构建目录
# rm -rf build # 手动清理构建项目
mkdir -p build
cd build

# 配置并构建
cmake --no-warn-unused-cli -DCMAKE_TOOLCHAIN_FILE=../aarch64-rockchip-linux-gnu.cmake .. || exit 1
make -j$(nproc)
# 编译失败退出脚本
if [ $? -ne 0 ]; then
    exit 1
fi
cd ..

# 推送并运行
run_app
