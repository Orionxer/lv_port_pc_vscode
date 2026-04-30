#include "player_audio.h"

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    SDL_AudioDeviceID device;
    uint8_t *data;
    uint32_t data_size;
    uint32_t position;
    uint8_t volume;
    bool initialized;
    bool playing;
} player_audio_t;

static player_audio_t g_player_audio = {
    .volume = 62,
};

static void audio_cb(void *userdata, uint8_t *stream, int len);
static void clear_audio_data(void);

bool player_audio_init(void)
{
    if(g_player_audio.initialized) {
        return true;
    }

    if(SDL_WasInit(SDL_INIT_AUDIO) == 0 && SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
        SDL_Log("SDL audio init failed: %s", SDL_GetError());
        return false;
    }

    SDL_AudioSpec want;
    SDL_zero(want);
    want.freq = PLAYER_AUDIO_SAMPLE_RATE;
    want.format = AUDIO_S16SYS;
    want.channels = PLAYER_AUDIO_CHANNELS;
    want.samples = 1024;
    want.callback = audio_cb;

    SDL_AudioSpec have;
    SDL_zero(have);
    g_player_audio.device = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
    if(g_player_audio.device == 0) {
        SDL_Log("SDL open audio device failed: %s", SDL_GetError());
        return false;
    }

    if(have.freq != want.freq || have.format != want.format || have.channels != want.channels) {
        SDL_Log("Unexpected audio format: %d Hz, format %u, channels %u",
                have.freq, (unsigned int)have.format, (unsigned int)have.channels);
        SDL_CloseAudioDevice(g_player_audio.device);
        g_player_audio.device = 0;
        return false;
    }

    g_player_audio.initialized = true;
    SDL_PauseAudioDevice(g_player_audio.device, 0);
    return true;
}

void player_audio_deinit(void)
{
    if(g_player_audio.device != 0) {
        SDL_LockAudioDevice(g_player_audio.device);
        clear_audio_data();
        g_player_audio.playing = false;
        SDL_UnlockAudioDevice(g_player_audio.device);
        SDL_CloseAudioDevice(g_player_audio.device);
    }

    memset(&g_player_audio, 0, sizeof(g_player_audio));
}

bool player_audio_load(const char *path)
{
    if(!player_audio_init()) {
        return false;
    }

    FILE *file = fopen(path, "rb");
    if(file == NULL) {
        SDL_Log("Open PCM failed: %s", path);
        return false;
    }

    if(fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return false;
    }

    long file_size = ftell(file);
    if(file_size <= 0) {
        fclose(file);
        return false;
    }

    rewind(file);
    uint8_t *data = malloc((size_t)file_size);
    if(data == NULL) {
        fclose(file);
        return false;
    }

    size_t read_size = fread(data, 1, (size_t)file_size, file);
    fclose(file);

    if(read_size != (size_t)file_size) {
        free(data);
        return false;
    }

    SDL_LockAudioDevice(g_player_audio.device);
    clear_audio_data();
    g_player_audio.data = data;
    g_player_audio.data_size = (uint32_t)file_size;
    g_player_audio.position = 0;
    g_player_audio.playing = false;
    SDL_UnlockAudioDevice(g_player_audio.device);

    return true;
}

void player_audio_play(void)
{
    player_audio_set_playing(true);
}

void player_audio_pause(void)
{
    player_audio_set_playing(false);
}

void player_audio_set_playing(bool playing)
{
    if(!g_player_audio.initialized) {
        return;
    }

    SDL_LockAudioDevice(g_player_audio.device);
    if(g_player_audio.data != NULL && g_player_audio.position < g_player_audio.data_size) {
        g_player_audio.playing = playing;
    }
    SDL_UnlockAudioDevice(g_player_audio.device);
}

bool player_audio_is_playing(void)
{
    bool playing = false;

    if(!g_player_audio.initialized) {
        return false;
    }

    SDL_LockAudioDevice(g_player_audio.device);
    playing = g_player_audio.playing;
    SDL_UnlockAudioDevice(g_player_audio.device);

    return playing;
}

void player_audio_seek(uint32_t seconds)
{
    uint32_t byte_pos = seconds * PLAYER_AUDIO_SAMPLE_RATE * PLAYER_AUDIO_CHANNELS * PLAYER_AUDIO_SAMPLE_SIZE;

    if(!g_player_audio.initialized) {
        return;
    }

    byte_pos -= byte_pos % PLAYER_AUDIO_SAMPLE_SIZE;
    SDL_LockAudioDevice(g_player_audio.device);
    if(g_player_audio.data != NULL) {
        g_player_audio.position = byte_pos < g_player_audio.data_size ? byte_pos : g_player_audio.data_size;
        if(g_player_audio.position >= g_player_audio.data_size) {
            g_player_audio.playing = false;
        }
    }
    SDL_UnlockAudioDevice(g_player_audio.device);
}

uint32_t player_audio_get_position(void)
{
    uint32_t position = 0;

    if(!g_player_audio.initialized) {
        return 0;
    }

    SDL_LockAudioDevice(g_player_audio.device);
    position = g_player_audio.position;
    SDL_UnlockAudioDevice(g_player_audio.device);

    return position / (PLAYER_AUDIO_SAMPLE_RATE * PLAYER_AUDIO_CHANNELS * PLAYER_AUDIO_SAMPLE_SIZE);
}

uint32_t player_audio_get_duration(void)
{
    uint32_t data_size = 0;

    if(!g_player_audio.initialized) {
        return 0;
    }

    SDL_LockAudioDevice(g_player_audio.device);
    data_size = g_player_audio.data_size;
    SDL_UnlockAudioDevice(g_player_audio.device);

    return data_size / (PLAYER_AUDIO_SAMPLE_RATE * PLAYER_AUDIO_CHANNELS * PLAYER_AUDIO_SAMPLE_SIZE);
}

void player_audio_set_volume(uint8_t volume)
{
    if(volume > 100) {
        volume = 100;
    }

    if(!g_player_audio.initialized) {
        g_player_audio.volume = volume;
        return;
    }

    SDL_LockAudioDevice(g_player_audio.device);
    g_player_audio.volume = volume;
    SDL_UnlockAudioDevice(g_player_audio.device);
}

static void audio_cb(void *userdata, uint8_t *stream, int len)
{
    (void)userdata;

    SDL_memset(stream, 0, len);

    if(!g_player_audio.playing || g_player_audio.data == NULL || g_player_audio.position >= g_player_audio.data_size) {
        g_player_audio.playing = false;
        return;
    }

    uint32_t available = g_player_audio.data_size - g_player_audio.position;
    uint32_t copy_size = available < (uint32_t)len ? available : (uint32_t)len;
    copy_size -= copy_size % PLAYER_AUDIO_SAMPLE_SIZE;

    const int16_t *src = (const int16_t *)(g_player_audio.data + g_player_audio.position);
    int16_t *dst = (int16_t *)stream;
    uint32_t samples = copy_size / PLAYER_AUDIO_SAMPLE_SIZE;
    uint8_t volume = g_player_audio.volume;

    for(uint32_t i = 0; i < samples; i++) {
        dst[i] = (int16_t)(((int32_t)src[i] * volume) / 100);
    }

    g_player_audio.position += copy_size;
    if(g_player_audio.position >= g_player_audio.data_size) {
        g_player_audio.playing = false;
    }
}

static void clear_audio_data(void)
{
    free(g_player_audio.data);
    g_player_audio.data = NULL;
    g_player_audio.data_size = 0;
    g_player_audio.position = 0;
}
