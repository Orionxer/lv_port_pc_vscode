# Music Playback Function

## 资源格式

音乐资源放在 `music/` 目录，原始文件为 MP3。

按照 `music/README.md` 的要求，播放前转换为 PCM：

```sh
ffmpeg -i xxx.mp3 -f s16le -ar 16000 -ac 1 -acodec pcm_s16le music/output/xxx.pcm
```

当前播放器直接播放 `music/output/` 下的 PCM 文件。

PCM 参数：

- 格式：`s16le`
- 采样率：`16000 Hz`
- 声道：`1`
- 每个采样：`2 bytes`

## 音频模块

音频播放逻辑封装在：

- `src/player_ui/player_audio.h`
- `src/player_ui/player_audio.c`

模块职责：

- 初始化 SDL audio device
- 加载 PCM 文件到内存
- 通过 SDL audio callback 输出 PCM
- 支持播放、暂停、seek、获取当前位置、获取总时长
- 支持 `0-100` 音量控制

## UI 联动

播放器 UI 通过 `player_audio` 控制真实音频：

- 初始化 UI 时加载当前歌曲并开始播放
- 点击歌曲列表：加载对应 PCM 并播放
- 上一首/下一首：切换 PCM、重置进度并播放
- 播放/暂停按钮：同步控制音频播放状态
- 拖动进度条：松开后调用 seek 跳转到对应秒数
- 音量滑条：实时更新音频输出音量

进度条显示来自真实音频播放位置：

```c
player_audio_get_position()
```

歌曲时长来自 PCM 文件大小计算：

```c
player_audio_get_duration()
```

## 当前歌曲

当前接入 `music` 目录中的 5 首歌曲，对应 PCM 路径写在 `g_songs` 中。

为避免 C 字符串和文件路径编码问题，Oasis 的 PCM 文件名使用 ASCII 版本：

```text
music/output/Oasis_Dont_Look_Back_In_Anger.pcm
```

## 验证

构建：

```sh
cd build && make -j16 && cd ..
```

运行：

```sh
./bin/main
```

短时间检查可使用：

```sh
timeout 4 ./bin/main
```

`timeout` 返回 `124` 表示程序被主动结束，不代表播放器异常。
