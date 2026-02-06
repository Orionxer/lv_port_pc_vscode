/**
 * @file main.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE /* needed for usleep() */
#endif

#include <stdlib.h>
#include <stdio.h>
#ifdef _MSC_VER
#include <Windows.h>
#else
#include <unistd.h>
#include <pthread.h>
#endif
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"


#include "hal/hal.h"
#include "hal/rk_drm.h"

// #include "generated/gui_guider.h"
// #include "generated/events_init.h"
// lv_ui guider_ui;


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

#if LV_USE_OS != LV_OS_FREERTOS

void acclerate_info(void)
{
#if LV_USE_LINUX_DRM_RGA
    const char *accelerate = "RGA Accelerate";
	uint32_t bg_color = 0xFFB267;
#else
    const char *accelerate = "No Acceleration";
	uint32_t bg_color = 0x666666;
#endif
	lv_obj_t * rect = lv_obj_create(lv_layer_top());
	lv_obj_set_size(rect, 170, 40);
	lv_obj_align(rect, LV_ALIGN_RIGHT_MID, +10, 0);
	lv_obj_set_style_bg_color(rect, lv_color_hex(bg_color), 0);
	lv_obj_set_style_bg_opa(rect, LV_OPA_80, 0);
	lv_obj_set_scrollbar_mode(rect, LV_SCROLLBAR_MODE_OFF);

	lv_obj_t * label = lv_label_create(rect);
	lv_label_set_text(label, accelerate);
	lv_obj_set_style_text_color(label, lv_color_white(), 0);
	lv_obj_set_style_text_font(label, &lv_font_montserrat_18, 0);
	lv_obj_set_style_text_outline_stroke_color(label, lv_color_white(), 0);
	lv_obj_set_style_text_outline_stroke_width(label, 1, 0);
	lv_obj_set_style_text_outline_stroke_opa(label, LV_OPA_COVER, 0);
	lv_obj_center(label);
}

void rgb_depth_info(void)
{
	const char *color_depth = (LV_COLOR_DEPTH == 16) ? "RGB565" : "ARGB8888";
	lv_obj_t *rect = lv_obj_create(lv_layer_top());
	lv_obj_set_size(rect, 130, 40);
	lv_obj_align(rect, LV_ALIGN_LEFT_MID, -10, 0);
	lv_obj_set_style_bg_color(rect, lv_color_hex(0x2C2C2C), 0);
	lv_obj_set_style_bg_opa(rect, LV_OPA_80, 0);
	lv_obj_set_scrollbar_mode(rect, LV_SCROLLBAR_MODE_OFF);

	lv_obj_t *label = lv_label_create(rect);
	lv_label_set_text(label, color_depth);
	lv_obj_set_style_text_color(label, lv_color_white(), 0);
	lv_obj_set_style_text_font(label, &lv_font_montserrat_18, 0);
	lv_obj_set_style_text_outline_stroke_color(label, lv_color_white(), 0);
	lv_obj_set_style_text_outline_stroke_width(label, 1, 0);
	lv_obj_set_style_text_outline_stroke_opa(label, LV_OPA_COVER, 0);
	lv_obj_center(label);
}

int main(int argc, char **argv)
{
	(void)argc; /*Unused*/
	(void)argv; /*Unused*/

	/*Initialize LVGL*/
	lv_init();

	/*Initialize the HAL (display, input devices, tick) for LVGL*/
	rk_drm_init();

	// ? 需要确保 lv_conf.h 中 LV_USE_EVDEV 已启用
	/* Initialize touch input */
	lv_indev_t *indev = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event2");
	if (indev)
	{
		lv_indev_set_display(indev, lv_display_get_default());
	}
	// return 0;
#if 1 // 色深以及是否加速的信息提示
	rgb_depth_info();
	acclerate_info();
#endif
	/* Run the default demo */
	/* To try a different demo or example, replace this with one of: */
	lv_demo_benchmark();
	// lv_demo_stress();
	// lv_demo_music();
	// lv_demo_widgets();
	// lv_demo_keypad_encoder();
	/* - lv_example_label_1(); */
	/* - etc. */
	// setup_ui(&guider_ui);
	// events_init(&guider_ui);
	// lv_demo_widgets();

    while (1) {
        uint32_t time_until_next = lv_timer_handler();
        if(time_until_next == LV_NO_TIMER_READY) {
            time_until_next = LV_DEF_REFR_PERIOD;
        }
        lv_delay_ms(time_until_next);
    }
	rk_drm_deinit();
	return 0;
}

#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/
