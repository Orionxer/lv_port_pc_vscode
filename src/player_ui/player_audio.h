#ifndef PLAYER_AUDIO_H
#define PLAYER_AUDIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

#define PLAYER_AUDIO_SAMPLE_RATE 16000U
#define PLAYER_AUDIO_CHANNELS    1U
#define PLAYER_AUDIO_SAMPLE_SIZE 2U

bool player_audio_init(void);
void player_audio_deinit(void);
bool player_audio_load(const char *path);
void player_audio_play(void);
void player_audio_pause(void);
void player_audio_set_playing(bool playing);
bool player_audio_is_playing(void);
void player_audio_seek(uint32_t seconds);
uint32_t player_audio_get_position(void);
uint32_t player_audio_get_duration(void);
void player_audio_set_volume(uint8_t volume);

#ifdef __cplusplus
}
#endif

#endif
