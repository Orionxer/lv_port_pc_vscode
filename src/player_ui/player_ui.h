#ifndef PLAYER_UI_H
#define PLAYER_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include <stdbool.h>
#include <stdint.h>

#define PLAYER_SCREEN_WIDTH  320
#define PLAYER_SCREEN_HEIGHT 240

void player_ui_init(void);

#ifdef __cplusplus
}
#endif

#endif
