#!/bin/bash
# RK3566 LVGL 交叉编译构建脚本

# 创建构建目录
# rm -rf build # 手动清理构建项目
mkdir -p build
cd build

# 配置并构建
cmake --no-warn-unused-cli .. || exit 1
make -j$(nproc) || exit 1
cd ..

# 推送并运行 需要提前配置好开发板的ssh登录
echo "关闭其他lvgl进程..."
sshpass -p tspi ssh tspi "pkill lvgl"
echo "正在推送至开发板..."
sshpass -p tspi scp ./build/lvgl_app tspi:/app/lvgl
echo "推送完成."
echo "运行lvgl_app..."
# 主动设置超时，脚本退出，程序继续运行
timeout 2s sshpass -p tspi ssh tspi "/app/lvgl/lvgl_app" || echo "程序运行超时或结束"
# sshpass -p tspi ssh tspi "/app/lvgl/lvgl_app"
