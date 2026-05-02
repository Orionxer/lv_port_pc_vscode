#ifndef WATCH_UI_H
#define WATCH_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#define WATCH_SCREEN_WIDTH  390
#define WATCH_SCREEN_HEIGHT 450

void init_watch_time(uint8_t hour, uint8_t minute, uint8_t second);
void init_watch_day(uint8_t day);
void watch_ui_init(void);

#ifdef __cplusplus
}
#endif

#endif
