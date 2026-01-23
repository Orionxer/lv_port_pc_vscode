# RK3566 交叉编译工具链文件

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# 工具链路径
set(TOOLCHAIN_PATH /home/orionxer/tspi/sdk/Release/prebuilts/gcc/linux-x86/aarch64/gcc-buildroot-9.3.0-2020.03-x86_64_aarch64-rockchip-linux-gnu)
set(SYSROOT_PATH /home/orionxer/tspi/sdk/Release/buildroot/output/rockchip_rk3566/host/aarch64-buildroot-linux-gnu/sysroot)

# 编译器路径
set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}/bin/aarch64-rockchip-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH}/bin/aarch64-rockchip-linux-gnu-g++)
set(CMAKE_AR ${TOOLCHAIN_PATH}/bin/aarch64-rockchip-linux-gnu-ar)
set(CMAKE_STRIP ${TOOLCHAIN_PATH}/bin/aarch64-rockchip-linux-gnu-strip)

# Sysroot 配置
set(CMAKE_SYSROOT ${SYSROOT_PATH})
set(CMAKE_FIND_ROOT_PATH ${SYSROOT_PATH})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# 编译参数
set(CMAKE_C_FLAGS "-march=armv8-a")
set(CMAKE_CXX_FLAGS "-march=armv8-a")

# DRM 头文件路径
include_directories(BEFORE ${SYSROOT_PATH}/usr/include/libdrm)
