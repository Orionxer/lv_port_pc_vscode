/*
 * Copyright (c) 2025 BekenCorp. All rights reserved.
 * 
 * This software is proprietary and confidential. No part of this software may be
 * reproduced, distributed, or transmitted in any form or by any means, including
 * photocopying, recording, or other electronic or mechanical methods, without the
 * prior written permission of BekenCorp, except in the case of brief quotations
 * embodied in critical reviews and certain other noncommercial uses permitted
 * by copyright law.
 * 
 * For permission requests, write to BekenCorp at armino_support@bekencorp.com.

 * Author: Beken LVGL Designer Tool
*/
/**
 * @file beken_ui.c
 * @brief Beken UI implementation file
 * 
 * This file contains the implementation of the Beken UI system.
 * Customers can modify this file to customize their UI without
 * touching the main application code or build system.
 */

#ifndef __BEKEN_UI_H__
#define __BEKEN_UI_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

/* Display configuration */
#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   480

typedef struct
{
    /* Page: 0 objects */
    lv_obj_t *Home;
    lv_obj_t *Home_label_1;
    lv_obj_t *Home_label_2;
    lv_obj_t *Home_obj_3;
    lv_obj_t *Home_obj_1;
    lv_obj_t *Home_label_3;
    lv_obj_t *Home_obj_4;
    lv_obj_t *Home_label_4;
    lv_obj_t *Home_obj_5;
    lv_obj_t *Home_label_5;
    lv_obj_t *Home_obj_6;
    lv_obj_t *Home_label_6;
    lv_obj_t *Home_button_1;
    lv_obj_t *Home_button_1_label;
    lv_obj_t *Home_image_1;
    lv_obj_t *Home_image_2;
    /* Page: 1 objects */
    lv_obj_t *Make;
    lv_obj_t *Make_animimg_1;
    lv_obj_t *Make_pause_btn;
    lv_obj_t *Make_pause_btn_label;
    lv_obj_t *Make_label_1;
    lv_obj_t *Make_continue_btn;
    lv_obj_t *Make_continue_btn_label;
    lv_obj_t *Make_image_1;
    lv_obj_t *Make_obj_1;
    lv_obj_t *Make_image_2;
    lv_obj_t *Make_label_2;
    /* Page: 2 objects */
    lv_obj_t *Setting_coffe;
    lv_obj_t *Setting_coffe_obj_1;
    lv_obj_t *Setting_coffe_image_1;
    lv_obj_t *Setting_coffe_label_1;
    lv_obj_t *Setting_coffe_button_1;
    lv_obj_t *Setting_coffe_button_1_label;
    lv_obj_t *Setting_coffe_obj_2;
    lv_obj_t *Setting_coffe_image_2;
    lv_obj_t *Setting_coffe_label_2;
    lv_obj_t *Setting_coffe_obj_3;
    lv_obj_t *Setting_coffe_image_3;
    lv_obj_t *Setting_coffe_label_3;
    lv_obj_t *Setting_coffe_obj_4;
    lv_obj_t *Setting_coffe_image_4;
    lv_obj_t *Setting_coffe_label_4;
    lv_obj_t *Setting_coffe_obj_5;
    lv_obj_t *Setting_coffe_image_5;
    lv_obj_t *Setting_coffe_label_5;
    lv_obj_t *Setting_coffe_obj_8;
    lv_obj_t *Setting_coffe_obj_7;
    lv_obj_t *Setting_coffe_label_6;
    lv_obj_t *Setting_coffe_line_1;
    lv_obj_t *Setting_coffe_slider_1;
    lv_obj_t *Setting_coffe_label_7;
    lv_obj_t *Setting_coffe_label_8;
    lv_obj_t *Setting_coffe_obj_9;
    lv_obj_t *Setting_coffe_label_9;
    lv_obj_t *Setting_coffe_line_2;
    lv_obj_t *Setting_coffe_dropdown_1;
    lv_obj_t* Setting_coffe_dropdown_1_list;
    /* Page: 3 objects */
    lv_obj_t *Setting_temp;
    lv_obj_t *Setting_temp_obj_1;
    lv_obj_t *Setting_temp_image_1;
    lv_obj_t *Setting_temp_label_1;
    lv_obj_t *Setting_temp_button_1;
    lv_obj_t *Setting_temp_button_1_label;
    lv_obj_t *Setting_temp_obj_2;
    lv_obj_t *Setting_temp_image_2;
    lv_obj_t *Setting_temp_label_2;
    lv_obj_t *Setting_temp_obj_3;
    lv_obj_t *Setting_temp_image_3;
    lv_obj_t *Setting_temp_label_3;
    lv_obj_t *Setting_temp_obj_4;
    lv_obj_t *Setting_temp_image_4;
    lv_obj_t *Setting_temp_label_4;
    lv_obj_t *Setting_temp_obj_5;
    lv_obj_t *Setting_temp_image_5;
    lv_obj_t *Setting_temp_label_5;
    lv_obj_t *Setting_temp_obj_6;
    lv_obj_t *Setting_temp_obj_7;
    lv_obj_t *Setting_temp_label_6;
    lv_obj_t *Setting_temp_line_1;
    lv_obj_t *Setting_temp_obj_8;
    lv_obj_t *Setting_temp_label_7;
    lv_obj_t *Setting_temp_label_8;
    lv_obj_t *Setting_temp_switch_1;
    lv_obj_t *Setting_temp_obj_9;
    lv_obj_t *Setting_temp_label_9;
    lv_obj_t *Setting_temp_line_2;
    lv_obj_t *Setting_temp_slider_1;
    lv_obj_t *Setting_temp_label_10;
    lv_obj_t *Setting_temp_label_11;
    lv_obj_t *Setting_temp_obj_10;
    lv_obj_t *Setting_temp_label_13;
    lv_obj_t *Setting_temp_label_14;
    lv_obj_t *Setting_temp_label_15;
    lv_obj_t *Setting_temp_label_12;
    /* Page: 4 objects */
    lv_obj_t *Setting_mat;
    lv_obj_t *Setting_mat_obj_1;
    lv_obj_t *Setting_mat_image_1;
    lv_obj_t *Setting_mat_label_1;
    lv_obj_t *Setting_mat_button_1;
    lv_obj_t *Setting_mat_button_1_label;
    lv_obj_t *Setting_mat_obj_2;
    lv_obj_t *Setting_mat_image_2;
    lv_obj_t *Setting_mat_label_2;
    lv_obj_t *Setting_mat_obj_3;
    lv_obj_t *Setting_mat_image_3;
    lv_obj_t *Setting_mat_label_3;
    lv_obj_t *Setting_mat_obj_4;
    lv_obj_t *Setting_mat_image_4;
    lv_obj_t *Setting_mat_label_4;
    lv_obj_t *Setting_mat_obj_5;
    lv_obj_t *Setting_mat_image_5;
    lv_obj_t *Setting_mat_label_5;
    lv_obj_t *Setting_mat_obj_6;
    lv_obj_t *Setting_mat_obj_7;
    lv_obj_t *Setting_mat_label_6;
    lv_obj_t *Setting_mat_line_1;
    lv_obj_t *Setting_mat_obj_9;
    lv_obj_t *Setting_mat_label_9;
    lv_obj_t *Setting_mat_line_2;
    lv_obj_t *Setting_mat_obj_10;
    lv_obj_t *Setting_mat_label_10;
    lv_obj_t *Setting_mat_line_3;
    lv_obj_t *Setting_mat_obj_11;
    lv_obj_t *Setting_mat_obj_12;
    lv_obj_t *Setting_mat_label_11;
    lv_obj_t *Setting_mat_label_12;
    lv_obj_t *Setting_mat_obj_13;
    lv_obj_t *Setting_mat_label_13;
    lv_obj_t *Setting_mat_label_14;
    lv_obj_t *Setting_mat_obj_14;
    lv_obj_t *Setting_mat_label_15;
    lv_obj_t *Setting_mat_label_16;
    lv_obj_t *Setting_mat_dropdown_1;
    lv_obj_t* Setting_mat_dropdown_1_list;
    lv_obj_t *Setting_mat_obj_8;
    lv_obj_t *Setting_mat_label_7;
    lv_obj_t *Setting_mat_label_8;
    lv_obj_t *Setting_mat_start;
    lv_obj_t *Setting_mat_start_label;
    lv_obj_t *Setting_mat_spinner_1;
    lv_obj_t *Setting_mat_stop;
    lv_obj_t *Setting_mat_stop_label;
    /* Page: 5 objects */
    lv_obj_t *Setting_sys;
    lv_obj_t *Setting_sys_obj_1;
    lv_obj_t *Setting_sys_image_1;
    lv_obj_t *Setting_sys_label_1;
    lv_obj_t *Setting_sys_button_1;
    lv_obj_t *Setting_sys_button_1_label;
    lv_obj_t *Setting_sys_obj_2;
    lv_obj_t *Setting_sys_image_2;
    lv_obj_t *Setting_sys_label_2;
    lv_obj_t *Setting_sys_obj_3;
    lv_obj_t *Setting_sys_image_3;
    lv_obj_t *Setting_sys_label_3;
    lv_obj_t *Setting_sys_obj_4;
    lv_obj_t *Setting_sys_image_4;
    lv_obj_t *Setting_sys_label_4;
    lv_obj_t *Setting_sys_obj_5;
    lv_obj_t *Setting_sys_image_5;
    lv_obj_t *Setting_sys_label_5;
    lv_obj_t *Setting_sys_obj_6;
    lv_obj_t *Setting_sys_obj_7;
    lv_obj_t *Setting_sys_label_6;
    lv_obj_t *Setting_sys_line_1;
    lv_obj_t *Setting_sys_button_2;
    lv_obj_t *Setting_sys_button_2_label;
    lv_obj_t *Setting_sys_dropdown_1;
    lv_obj_t* Setting_sys_dropdown_1_list;
    lv_obj_t *Setting_sys_obj_8;
    lv_obj_t *Setting_sys_obj_9;
    lv_obj_t *Setting_sys_label_7;
    lv_obj_t *Setting_sys_label_8;
    lv_obj_t *Setting_sys_obj_10;
    lv_obj_t *Setting_sys_label_9;
    lv_obj_t *Setting_sys_label_10;
    lv_obj_t *Setting_sys_obj_11;
    lv_obj_t *Setting_sys_label_11;
    lv_obj_t *Setting_sys_label_12;
    lv_obj_t *Setting_sys_obj_12;
    lv_obj_t *Setting_sys_label_13;
    lv_obj_t *Setting_sys_label_14;
} bk_lv_ui_t;

void init_page_Home(bk_lv_ui_t *bk_ui);
void destroy_page_Home(bk_lv_ui_t *bk_ui);
void init_page_Make(bk_lv_ui_t *bk_ui);
void destroy_page_Make(bk_lv_ui_t *bk_ui);
void init_page_Setting_coffe(bk_lv_ui_t *bk_ui);
void destroy_page_Setting_coffe(bk_lv_ui_t *bk_ui);
void init_page_Setting_temp(bk_lv_ui_t *bk_ui);
void destroy_page_Setting_temp(bk_lv_ui_t *bk_ui);
void init_page_Setting_mat(bk_lv_ui_t *bk_ui);
void destroy_page_Setting_mat(bk_lv_ui_t *bk_ui);
void init_page_Setting_sys(bk_lv_ui_t *bk_ui);
void destroy_page_Setting_sys(bk_lv_ui_t *bk_ui);

/* declare image */
LV_IMAGE_DECLARE(cappuccino_ARGB8888);
LV_IMAGE_DECLARE(coffee_setting_24x24_RGB565A8_NONE);
LV_IMAGE_DECLARE(down_white_20x20_RGB565A8_NONE);
LV_IMAGE_DECLARE(espresso_ARGB8888);
LV_IMAGE_DECLARE(latte_ARGB8888);
LV_IMAGE_DECLARE(macchiato_ARGB8888);
LV_IMAGE_DECLARE(maintenance_setting_20x20_RGB565A8_NONE);
LV_IMAGE_DECLARE(p_0_269x286_RGB565A8_NONE);
LV_IMAGE_DECLARE(p_100_269x286_RGB565A8_NONE);
LV_IMAGE_DECLARE(p_17_269x286_RGB565A8_NONE);
LV_IMAGE_DECLARE(p_33_269x286_RGB565A8_NONE);
LV_IMAGE_DECLARE(p_50_269x286_RGB565A8_NONE);
LV_IMAGE_DECLARE(p_67_269x286_RGB565A8_NONE);
LV_IMAGE_DECLARE(p_83_269x286_RGB565A8_NONE);
LV_IMAGE_DECLARE(setting_32x32_RGB565A8_NONE);
LV_IMAGE_DECLARE(temperature_setting_24x24_RGB565A8_NONE);

/* declare fonts */
LV_FONT_DECLARE(lv_font_ali_36);
LV_FONT_DECLARE(lv_font_ali_17);
LV_FONT_DECLARE(lv_font_ali_18);
LV_FONT_DECLARE(lv_font_ali_16);
LV_FONT_DECLARE(lv_font_montserrat_regular_16);
LV_FONT_DECLARE(lv_font_ali_15);
LV_FONT_DECLARE(lv_font_montserrat_regular_20);

/**
 * @brief Initialize the Beken UI system
 * 
 * This function initializes the UI components and creates the main interface.
 * Customers can modify this function to customize their UI layout.
 */
void beken_ui_init(void);

/**
 * @brief Get the configured screen width
 * @return Screen width in pixels
 */
int beken_get_screen_width(void);

/**
 * @brief Get the configured screen height
 * @return Screen height in pixels
 */
int beken_get_screen_height(void);

extern bk_lv_ui_t bk_lv_tool_ui;

/* Digital clock functions */
void lv_digital_clock_timer(lv_timer_t *timer);
void lv_digital_clock_register(lv_obj_t *label, int show_second, int use_ampm, int hour, int minute, int second);
void lv_digital_clock_unregister(lv_obj_t *label);
void lv_digital_clock_register(lv_obj_t *label, int show_second, int use_ampm, int hour, int minute, int second);
void lv_digital_clock_unregister(lv_obj_t *label);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /* __BEKEN_UI_H__ */
