cmake_minimum_required(VERSION 3.12.4)

project(lvgl_app C CXX)

# 添加 LVGL 子目录
add_subdirectory(lvgl)

# 添加头文件路径
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/src/custom)
include_directories(${PROJECT_SOURCE_DIR}/src/generated)
include_directories(${PROJECT_SOURCE_DIR}/src/hal)

# RGA 头文件路径 (Rockchip RGA 硬件加速)
include_directories(/home/orionxer/tspi/sdk/Release/external/linux-rga/include)
include_directories(/home/orionxer/tspi/sdk/Release/external/linux-rga/im2d_api)

# 收集源文件
set(SOURCES
    src/main.c
    src/mouse_cursor_icon.c
    src/hal/rk_drm.c
)

set_source_files_properties(src/hal/rk_drm.c PROPERTIES LANGUAGE CXX)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接库 (运行时使用开发板上的librga.so)
target_link_libraries(${PROJECT_NAME}
    lvgl::lvgl
    pthread
    m
    drm
    rga
)
