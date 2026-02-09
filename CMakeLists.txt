cmake_minimum_required(VERSION 3.12.4)

# RV1126B 交叉编译配置 (迁移自 aarch64-rockchip-linux-gnu.cmake)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# 设置交叉编译工具链
set(TOOLCHAIN_PATH "/sdk/tools/linux/toolchain/aarch64-rockchip1240-linux-gnu")
set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}/bin/aarch64-rockchip1240-linux-gnu-gcc)

project(lvgl_app C CXX)

# DRM 头文件路径 (迁移自 aarch64-rockchip-linux-gnu.cmake)
include_directories(
    /sdk/media/libdrm/out/include/libdrm
    /sdk/media/libdrm/out/include
    )

# RGA 头文件路径
include_directories(
    /sdk/media/rga/out/include
)

# 添加 LVGL 子目录
add_subdirectory(lvgl)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/src/custom)
include_directories(${PROJECT_SOURCE_DIR}/src/generated)
include_directories(${PROJECT_SOURCE_DIR}/src/hal)

# 收集源文件
set(SOURCES
    src/main.c
    src/mouse_cursor_icon.c
    src/hal/rk_drm.c
)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# DRM库路径
set(LIBDRM_PATH "/sdk/media/libdrm/libdrm-2.4.120-aarch64-rockchip1240-linux-gnu")
link_directories(${LIBDRM_PATH}/lib)

# RGA库路径
set(RGA_PATH "/sdk/media/rga/out")
link_directories(${RGA_PATH}/lib)

# 链接库
target_link_libraries(${PROJECT_NAME}
    lvgl::lvgl
    pthread
    m
    rt
    ${LIBDRM_PATH}/lib/libdrm.so
    ${RGA_PATH}/lib/librga.a
)
