# 构建说明

## 编译环境
> 自行准备好GCC交叉编译环境

## 下载LVGL
> 自行选择目录，推荐SDK下的app目录，例如`~/tspi/sdk/Release/app`
```sh
# 下载lvgl
git clone --recursive https://github.com/orionxer/lv_port_pc_vscode
```
```sh
# 切换分支
git checkout tspi
```
根据实际情况修改以下文件
- `CMakeLists.txt`，修改编译工具链，链接库等以通过编译
- `auto_build.sh`，如果需要自动编译并推送运行，则需要修改SSH相关内容，不需要可以忽略
```sh
# 创建编译目录
mkdir -p build && cd build
```
```sh
# 构建编译
cmake .. && make -j16
# 编译成功后 ./build/lvgl_app为可执行文件，推送到目标板后运行
```
```sh
# 自动编译并推送运行
./auto_build.sh
```

## 渲染加速说明
本项目使用RGA进行加速，如果需要对比是否启用加速的帧率，可以修改 `lv_conf.h` 中的 `LV_USE_GPU_RGA` 宏定义来启用或禁用RGA加速。

- `LV_USE_LINUX_DRM_RGA` 是否启用`RGA`加速
- `LV_USE_LINUX_DRM_RGA_FLUSH` 是否启用`RGA`刷新，也就是零拷贝

> 注意，RGA有个Bug，即便是RGB565格式，RGA分配buffer时也必须使用32位对齐，否则显示异常，因此无法在`LVGL_COLOR_DEPTH`为16时使用`RGA`刷新。

启用`lv_demo_benchmark()`实测数据表格

| RGA加速 | 色深 | 刷新方式 | 平均帧率 |
|---------|------|---------|---------|
| ✅ 启用 | 16 (RGB565)   | CPU | 59fps |
| ✅ 启用 | 32 (ARGB8888) | CPU | 54fps |
| ✅ 启用 | 32 (ARGB8888) | RGA | 53fps |
| ❌ 禁用 | 16 (RGB565)   | CPU | 31fps |
| ❌ 禁用 | 32 (RGB565)   | CPU | 26fps |

## 参考链接

- [LVGL官方的DRM教程](https://docs.lvgl.io/master/integration/embedded_linux/drivers/drm.html#using-drm-with-egl)
- [瑞芯微RGA仓库](https://github.com/airockchip/librga)
- [RGA IM2D API 开发指南](https://github.com/airockchip/librga/blob/main/docs/Rockchip_Developer_Guide_RGA_CN.md)，参考`应用接口`章节，可以实现`querystring`Demo，查询获取当前芯片平台RGA硬件版本与功能支持信息，以字符串的形式返回。
- [Rockchip_FAQ_RGA_CN](https://github.com/airockchip/librga/blob/main/docs/Rockchip_FAQ_RGA_CN.md)，如果有报错，优先从这里寻找解决方案
- SDK中的RGA仓库路径: `~/tspi/sdk/Release/external/linux-rga`