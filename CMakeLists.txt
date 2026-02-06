cmake_minimum_required(VERSION 3.12.4)

# RK3566 交叉编译工具链配置
set(SDK_PATH /home/orionxer/tspi/sdk/Release)
set(TOOLCHAIN_PATH ${SDK_PATH}/prebuilts/gcc/linux-x86/aarch64/gcc-buildroot-9.3.0-2020.03-x86_64_aarch64-rockchip-linux-gnu)
set(SYSROOT_PATH ${SDK_PATH}/buildroot/output/rockchip_rk3566/host/aarch64-buildroot-linux-gnu/sysroot)

# 交叉编译目标平台
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# 编译器路径
set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}/bin/aarch64-rockchip-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH}/bin/aarch64-rockchip-linux-gnu-g++)
set(CMAKE_AR ${TOOLCHAIN_PATH}/bin/aarch64-rockchip-linux-gnu-ar)
set(CMAKE_STRIP ${TOOLCHAIN_PATH}/bin/aarch64-rockchip-linux-gnu-strip)

# Sysroot 配置 (限制库和头文件搜索范围)
set(CMAKE_SYSROOT ${SYSROOT_PATH})
set(CMAKE_FIND_ROOT_PATH ${SYSROOT_PATH})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# 编译器运行时库路径 (cc1 依赖 libisl.so 等库)
set(ENV{LD_LIBRARY_PATH} "${TOOLCHAIN_PATH}/lib:$ENV{LD_LIBRARY_PATH}")

project(lvgl_app C CXX)

# 构建阶段为编译器注入库路径 (C/C++/ASM 全部生效)
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "env LD_LIBRARY_PATH=${TOOLCHAIN_PATH}/lib")

# DRM 头文件路径 (BEFORE 确保优先于系统路径, LVGL 内部依赖)
include_directories(BEFORE ${SYSROOT_PATH}/usr/include/libdrm)

# LVGL 图形库
add_subdirectory(lvgl)

# 头文件路径
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/freertos
    ${PROJECT_SOURCE_DIR}/src/hal
    ${SDK_PATH}/external/linux-rga/include        # RGA 硬件加速
    ${SDK_PATH}/external/linux-rga/im2d_api       # RGA im2d API
)

# 链接库搜索路径
link_directories(${TOOLCHAIN_PATH}/lib)

# 源文件
set(SOURCES
    src/main.c
    src/mouse_cursor_icon.c
    src/hal/rk_drm.c
)

# 指定文件为 C++ 源文件 (避免编译错误)
# set_source_files_properties(src/hal/rk_drm.c PROPERTIES LANGUAGE CXX)

# 可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接库
target_link_libraries(${PROJECT_NAME}
    lvgl::lvgl
    pthread
    m
    drm
    rga
)
