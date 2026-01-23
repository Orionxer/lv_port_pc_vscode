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

# 收集源文件
set(SOURCES
    src/main.c
    src/mouse_cursor_icon.c
)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接库
target_link_libraries(${PROJECT_NAME}
    lvgl::lvgl
    pthread
    m
    drm
)
