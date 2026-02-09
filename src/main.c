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

#include <rga/im2d.h>
#include <rga/RgaApi.h>

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

int main(int argc, char **argv)
{
	(void)argc; /*Unused*/
	(void)argv; /*Unused*/
	// rga_test();
	// return 0;
	/*Initialize LVGL*/
	lv_init();

	/*Initialize the HAL (display, input devices, tick) for LVGL*/
	// 不开RGA加速平均帧率32FPS，开启RGA加速平均帧率45FPS
	rk_drm_init();
	// ? 需要确保 lv_conf.h 中 LV_USE_EVDEV 已启用
	/* Initialize touch input */
	lv_indev_t * indev = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event1");
    if(indev) {
        lv_indev_set_display(indev, lv_display_get_default());
    }

	/* Run the default demo */
	/* To try a different demo or example, replace this with one of: */
	lv_demo_benchmark();
	// lv_demo_stress();
	// lv_demo_music();
	// lv_demo_widgets();
	/* - etc. */
	// setup_ui(&guider_ui);
	// events_init(&guider_ui);
	// lv_demo_widgets();

	while (1)
	{
		/* Periodically call the lv_task handler.
		 * It could be done in a timer interrupt or an OS task too.*/
		uint32_t sleep_time_ms = lv_timer_handler();
		if (sleep_time_ms == LV_NO_TIMER_READY)
		{
			sleep_time_ms = LV_DEF_REFR_PERIOD;
		}
#ifdef _MSC_VER
		Sleep(sleep_time_ms);
#else
		usleep(sleep_time_ms * 1000);
#endif
	}

	return 0;
}

#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/
