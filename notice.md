# Notice

- 主控是RK3566，buildroot系统
- 2GB内存
- 使用DRM显示

## DRM显示驱动


## 测试运行
```sh
# 推送程序到开发板
scp_tspi ./bin/main tspi:/app/lvgl
```
```sh
# 进入开发板运行
ssh_tspi /app/lvgl/main
```

## 参考链接
- [LVGL官方的DRM教程](https://docs.lvgl.io/master/integration/embedded_linux/drivers/drm.html#using-drm-with-egl)