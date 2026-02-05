# 画面撕裂问题解决方案

## 问题分析

**现象**: 帧率稳定在60 FPS，但出现画面撕裂

**原因**:
- 之前只使用固定的buffer 0
- 在显示器还在读取buffer时，RGA就开始写入新数据
- 导致上半部分是旧画面，下半部分是新画面

## 解决方案：双缓冲

### 实现原理

```
传统单缓冲（撕裂）:
┌─────────────────┐
│  DRM Buffer 0  │ ← 同时被读取（显示）和写入（RGA）
└─────────────────┘
     ↓ 写入时撕裂！

双缓冲（无撕裂）:
┌─────────────────┐     ┌─────────────────┐
│  Front Buffer   │     │  Back Buffer    │
│  (正在显示)      │     │  (正在写入)      │
│   Buffer 0      │     │   Buffer 1      │
└─────────────────┘     └─────────────────┘
     ↓ 只读取                  ↓ 只写入
     VSync后切换                → RGA写入
```

### 代码实现

#### 1. 添加当前buffer索引

```c
typedef struct {
    // ... 其他字段 ...
    drm_buffer_t drm_bufs[BUFFER_CNT];
    uint32_t current_buf_idx;  /* 当前显示的buffer索引 */
} drm_dev_t;
```

#### 2. 初始化buffer索引

```c
static int drm_setup_buffers(drm_dev_t * drm_dev)
{
    // ... 分配buffer ...

    /* 初始化当前显示buffer索引为buffer 0 */
    drm_dev->current_buf_idx = 0;

    return 0;
}
```

#### 3. 双缓冲刷新逻辑

```c
static void drm_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map)
{
    drm_dev_t * drm_dev = lv_display_get_driver_data(disp);

    /* 双缓冲策略：使用下一个可用的buffer（与当前显示的buffer不同） */
    uint32_t next_buf_idx = (drm_dev->current_buf_idx + 1) % BUFFER_CNT;
    drm_buffer_t *drm_buf = &drm_dev->drm_bufs[next_buf_idx];

    /* 使用RGA写入到后缓冲区 */
    rga_dst.fd = drm_buf->prime_fd;  /* 后缓冲区 */
    // ... RGA操作 ...

    /* 提交后缓冲区到显示 - 这会触发VSync同步 */
    drm_dmabuf_set_plane(drm_dev, drm_buf);

    /* 更新当前显示的buffer索引 */
    drm_dev->current_buf_idx = next_buf_idx;
}
```

## 工作流程

### Frame N
```
1. current_buf_idx = 0
2. Front Buffer = drm_bufs[0] (正在显示)
3. Back Buffer = drm_bufs[1] (RGA写入Frame N+1)
4. VSync触发 → 切换到Buffer 1
5. current_buf_idx = 1
```

### Frame N+1
```
1. current_buf_idx = 1
2. Front Buffer = drm_bufs[1] (正在显示)
3. Back Buffer = drm_bufs[0] (RGA写入Frame N+2)
4. VSync触发 → 切换到Buffer 0
5. current_buf_idx = 0
```

## 优势

1. **消除撕裂**: Front Buffer只被读取，Back Buffer只被写入
2. **保持帧率**: RGA并行写入到Back Buffer，不影响Front Buffer显示
3. **VSync同步**: DRM自动在VSync时切换buffer，确保完美同步
4. **硬件加速**: 仍然使用RGA硬件加速拷贝

## 性能数据

| 指标 | 单缓冲 | 双缓冲 |
|------|--------|--------|
| 帧率 | 60 FPS | 60 FPS |
| 画面撕裂 | ✗ 有 | ✓ 无 |
| CPU使用 | 相同 | 相同 |
| 内存占用 | 1x buffer | 2x buffers |

## 关键要点

1. **必须使用VSync同步**
   - DRM的atomic commit会自动等待VSync
   - 确保buffer切换在垂直回扫期间进行

2. **RGA操作必须成功**
   - 纯硬件加速，无软件回退
   - RGA失败时记录错误但不重试

3. **FULL模式必需**
   - LVGL渲染到独立buffer
   - flush时用RGA拷贝到DRM buffer
   - 实现真正的双缓冲

4. **DMA-BUF fd关键**
   - 使用`prime_fd`而不是虚拟地址
   - RGA可以直接访问DMA-BUF
   - 避免不必要的CPU拷贝

## 验证方法

### 检查是否有撕裂

观察快速移动的物体或动画：
- ✓ 无撕裂: 物体平滑移动，无断层
- ✗ 有撕裂: 物体出现水平错位或断层

### 检查帧率

查看右下角的FPS显示：
- 应该稳定在 60 FPS
- 不应该低于 55 FPS

### 检查日志

观察日志中的buffer切换：
```
RGA HW blit to back buffer 1: ...
RGA HW blit to back buffer 0: ...
```

应该看到buffer索引在0和1之间交替。

## 常见问题

### Q: 双缓冲会增加延迟吗？

**A**: 理论上增加1帧延迟（约16ms @ 60Hz），但实际上：
- RGA硬件加速延迟极低（微秒级）
- VSync同步确保流畅
- 用户感觉不到延迟

### Q: 可以使用三缓冲吗？

**A**: 可以，但通常不必要：
- 三缓冲可以进一步降低延迟风险
- 但会增加内存占用
- 双缓冲已经足够消除撕裂

### Q: 为什么不使用DIRECT模式？

**A**: DIRECT模式无法实现真正的双缓冲：
- DIRECT模式直接渲染到DRM buffer
- 无法避免读写冲突
- FULL模式 + RGA = 最佳方案

## 总结

通过实现双缓冲机制：
1. ✅ **完全消除画面撕裂**
2. ✅ **保持60 FPS稳定帧率**
3. ✅ **继续使用RGA硬件加速**
4. ✅ **VSync同步保证流畅**

这是在RK3568平台上使用RGA加速的最佳实践。

---

**文档版本**: 1.0
**最后更新**: 2026-01-29
**状态**: 已验证并应用
