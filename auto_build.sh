#!/bin/bash
# RV1126B LVGL 交叉编译构建脚本

# 创建构建目录
# rm -rf build # 手动清理构建项目
mkdir -p build
cd build

# 配置并构建
cmake --no-warn-unused-cli .. || exit 1
make -j$(nproc) || exit 1
cd ..

# 关闭其他lvgl进程
echo "关闭其他lvgl进程..."
sshpass -p luckfox ssh aura "killall lvgl_app"
# 如果配置好SSH，可以主动推送至开发板
echo "正在推送至开发板..."
sshpass -p luckfox scp ./build/lvgl_app aura:/app/lvgl
echo "推送完成."
# 运行
echo "运行lvgl_app..."
# sshpass -p luckfox ssh aura "/app/lvgl/lvgl_app"
timeout 1 sshpass -p luckfox ssh aura "/app/lvgl/lvgl_app"