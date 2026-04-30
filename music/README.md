# Music Commands

## 播放 MP3
```sh
ffplay -nodisp -autoexit xxx.mp3
```

## 转换 PCM
```sh
ffmpeg -i xxx.mp3 -f s16le -ar 16000 -ac 1 -acodec pcm_s16le output/xxx.pcm
```

## 播放 PCM
```sh
ffplay -f s16le -ar 16000 -ac 1 output/xxx.pcm
```
