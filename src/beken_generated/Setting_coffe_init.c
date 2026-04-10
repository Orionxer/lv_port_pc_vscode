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
#include "lvgl.h"
#include "beken_ui.h"
#include "custom_func.h"
#include "event_runtime.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Event callback for Setting_coffe_button_1 - handles all events
 * @param e LVGL event object
 */
void Setting_coffe_button_1_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        navigate_to_screen(&bk_lv_tool_ui.Home, LV_SCR_LOAD_ANIM_OVER_RIGHT, 300, 0, false, init_page_Home);
    }
}

/**
 * @brief Event callback for Setting_coffe_obj_3 - handles all events
 * @param e LVGL event object
 */
void Setting_coffe_obj_3_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        navigate_to_screen(&bk_lv_tool_ui.Setting_temp, LV_SCR_LOAD_ANIM_NONE, 300, 0, false, init_page_Setting_temp);
    }
}

/**
 * @brief Event callback for Setting_coffe_obj_4 - handles all events
 * @param e LVGL event object
 */
void Setting_coffe_obj_4_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        navigate_to_screen(&bk_lv_tool_ui.Setting_mat, LV_SCR_LOAD_ANIM_NONE, 300, 0, false, init_page_Setting_mat);
    }
}

/**
 * @brief Event callback for Setting_coffe_obj_5 - handles all events
 * @param e LVGL event object
 */
void Setting_coffe_obj_5_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        navigate_to_screen(&bk_lv_tool_ui.Setting_sys, LV_SCR_LOAD_ANIM_NONE, 300, 0, false, init_page_Setting_sys);
    }
}

/*
 * @brief: init page Setting_coffe
 */
void init_page_Setting_coffe(bk_lv_ui_t *bk_ui)
{
    if (bk_ui->Setting_coffe != NULL && lv_obj_is_valid(bk_ui->Setting_coffe)) {
        destroy_page_Setting_coffe(bk_ui);
    }
    

    bk_ui->Setting_coffe = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(bk_ui->Setting_coffe, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_size(bk_ui->Setting_coffe, 800, 480);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe, lv_color_hex(0x795548), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_obj_1 = lv_obj_create(bk_ui->Setting_coffe);
    lv_obj_set_x(bk_ui->Setting_coffe_obj_1, 0);
    lv_obj_set_y(bk_ui->Setting_coffe_obj_1, 0);
    lv_obj_set_width(bk_ui->Setting_coffe_obj_1, 180);
    lv_obj_set_height(bk_ui->Setting_coffe_obj_1, 480);
    lv_obj_remove_flag(bk_ui->Setting_coffe_obj_1, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_1, lv_color_hex(0xff9800), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_1, 59, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_1, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_obj_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_obj_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_1, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_1, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_1, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_1, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_1, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_image_1 = lv_image_create(bk_ui->Setting_coffe_obj_1);
    lv_image_set_src(bk_ui->Setting_coffe_image_1, &setting_32x32_RGB565A8_NONE);
    lv_image_set_pivot(bk_ui->Setting_coffe_image_1, 50, 50);
    lv_image_set_rotation(bk_ui->Setting_coffe_image_1, 0);
    lv_obj_set_x(bk_ui->Setting_coffe_image_1, 14);
    lv_obj_set_y(bk_ui->Setting_coffe_image_1, 14);
    lv_obj_set_width(bk_ui->Setting_coffe_image_1, 32);
    lv_obj_set_height(bk_ui->Setting_coffe_image_1, 32);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_image_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_image_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_image_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_image_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_image_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_image_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_image_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_image_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(bk_ui->Setting_coffe_image_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(bk_ui->Setting_coffe_image_1, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(bk_ui->Setting_coffe_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_label_1 = lv_label_create(bk_ui->Setting_coffe_obj_1);
    lv_label_set_text(bk_ui->Setting_coffe_label_1, "设置");
    lv_label_set_long_mode(bk_ui->Setting_coffe_label_1, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_coffe_label_1, 48);
    lv_obj_set_y(bk_ui->Setting_coffe_label_1, 20);
    lv_obj_set_width(bk_ui->Setting_coffe_label_1, 60);
    lv_obj_set_height(bk_ui->Setting_coffe_label_1, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_label_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_label_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_coffe_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_coffe_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_coffe_label_1, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_coffe_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_coffe_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_label_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_button_1 = lv_btn_create(bk_ui->Setting_coffe_obj_1);
    bk_ui->Setting_coffe_button_1_label = lv_label_create(bk_ui->Setting_coffe_button_1);
    lv_label_set_text(bk_ui->Setting_coffe_button_1_label, "关闭");
    lv_label_set_long_mode(bk_ui->Setting_coffe_button_1_label, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_align(bk_ui->Setting_coffe_button_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_x(bk_ui->Setting_coffe_button_1, 0);
    lv_obj_set_y(bk_ui->Setting_coffe_button_1, 440);
    lv_obj_set_width(bk_ui->Setting_coffe_button_1, 180);
    lv_obj_set_height(bk_ui->Setting_coffe_button_1, 40);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_button_1, lv_color_hex(0x2d75b9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_button_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_button_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_button_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_button_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_button_1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_button_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_coffe_button_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_coffe_button_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_coffe_button_1, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_coffe_button_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_coffe_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_button_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_button_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Setting_coffe_button_1, Setting_coffe_button_1_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Setting_coffe_obj_2 = lv_obj_create(bk_ui->Setting_coffe_obj_1);
    lv_obj_set_x(bk_ui->Setting_coffe_obj_2, 15);
    lv_obj_set_y(bk_ui->Setting_coffe_obj_2, 75);
    lv_obj_set_width(bk_ui->Setting_coffe_obj_2, 150);
    lv_obj_set_height(bk_ui->Setting_coffe_obj_2, 40);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_2, lv_color_hex(0xff5722), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_2, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_2, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_2, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_2, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_obj_2, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_obj_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_2, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_2, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_2, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_2, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_2, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_2, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_image_2 = lv_image_create(bk_ui->Setting_coffe_obj_2);
    lv_image_set_src(bk_ui->Setting_coffe_image_2, &coffee_setting_24x24_RGB565A8_NONE);
    lv_image_set_pivot(bk_ui->Setting_coffe_image_2, 50, 50);
    lv_image_set_rotation(bk_ui->Setting_coffe_image_2, 0);
    lv_obj_set_x(bk_ui->Setting_coffe_image_2, 5);
    lv_obj_set_y(bk_ui->Setting_coffe_image_2, 7);
    lv_obj_set_width(bk_ui->Setting_coffe_image_2, 24);
    lv_obj_set_height(bk_ui->Setting_coffe_image_2, 24);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_image_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_image_2, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_image_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_image_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_image_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_image_2, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_image_2, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_image_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(bk_ui->Setting_coffe_image_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(bk_ui->Setting_coffe_image_2, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(bk_ui->Setting_coffe_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_label_2 = lv_label_create(bk_ui->Setting_coffe_obj_2);
    lv_label_set_text(bk_ui->Setting_coffe_label_2, "咖啡设置");
    lv_label_set_long_mode(bk_ui->Setting_coffe_label_2, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_coffe_label_2, 31);
    lv_obj_set_y(bk_ui->Setting_coffe_label_2, 10);
    lv_obj_set_width(bk_ui->Setting_coffe_label_2, 76);
    lv_obj_set_height(bk_ui->Setting_coffe_label_2, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_label_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_label_2, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_label_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_label_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_label_2, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_coffe_label_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_coffe_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_coffe_label_2, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_coffe_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_coffe_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_label_2, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_obj_3 = lv_obj_create(bk_ui->Setting_coffe_obj_1);
    lv_obj_set_x(bk_ui->Setting_coffe_obj_3, 15);
    lv_obj_set_y(bk_ui->Setting_coffe_obj_3, 125);
    lv_obj_set_width(bk_ui->Setting_coffe_obj_3, 150);
    lv_obj_set_height(bk_ui->Setting_coffe_obj_3, 40);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_3, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_3, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_3, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_obj_3, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_obj_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_3, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_3, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_3, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_3, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_3, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_3, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Setting_coffe_obj_3, Setting_coffe_obj_3_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Setting_coffe_image_3 = lv_image_create(bk_ui->Setting_coffe_obj_3);
    lv_image_set_src(bk_ui->Setting_coffe_image_3, &temperature_setting_24x24_RGB565A8_NONE);
    lv_image_set_pivot(bk_ui->Setting_coffe_image_3, 50, 50);
    lv_image_set_rotation(bk_ui->Setting_coffe_image_3, 0);
    lv_obj_set_x(bk_ui->Setting_coffe_image_3, 3);
    lv_obj_set_y(bk_ui->Setting_coffe_image_3, 8);
    lv_obj_set_width(bk_ui->Setting_coffe_image_3, 24);
    lv_obj_set_height(bk_ui->Setting_coffe_image_3, 24);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_image_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_image_3, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_image_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_image_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_image_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_image_3, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_image_3, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_image_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(bk_ui->Setting_coffe_image_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(bk_ui->Setting_coffe_image_3, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(bk_ui->Setting_coffe_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_label_3 = lv_label_create(bk_ui->Setting_coffe_obj_3);
    lv_label_set_text(bk_ui->Setting_coffe_label_3, "温度控制");
    lv_label_set_long_mode(bk_ui->Setting_coffe_label_3, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_coffe_label_3, 31);
    lv_obj_set_y(bk_ui->Setting_coffe_label_3, 10);
    lv_obj_set_width(bk_ui->Setting_coffe_label_3, 76);
    lv_obj_set_height(bk_ui->Setting_coffe_label_3, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_label_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_label_3, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_label_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_label_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_label_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_label_3, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_coffe_label_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_coffe_label_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_coffe_label_3, &lv_font_ali_15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_coffe_label_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_coffe_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_label_3, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_label_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_obj_4 = lv_obj_create(bk_ui->Setting_coffe_obj_1);
    lv_obj_set_x(bk_ui->Setting_coffe_obj_4, 15);
    lv_obj_set_y(bk_ui->Setting_coffe_obj_4, 175);
    lv_obj_set_width(bk_ui->Setting_coffe_obj_4, 150);
    lv_obj_set_height(bk_ui->Setting_coffe_obj_4, 40);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_4, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_4, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_4, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_obj_4, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_obj_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_4, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_4, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_4, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_4, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_4, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_4, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_4, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_4, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_4, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Setting_coffe_obj_4, Setting_coffe_obj_4_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Setting_coffe_image_4 = lv_image_create(bk_ui->Setting_coffe_obj_4);
    lv_image_set_src(bk_ui->Setting_coffe_image_4, &maintenance_setting_20x20_RGB565A8_NONE);
    lv_image_set_pivot(bk_ui->Setting_coffe_image_4, 50, 50);
    lv_image_set_rotation(bk_ui->Setting_coffe_image_4, 0);
    lv_obj_set_x(bk_ui->Setting_coffe_image_4, 5);
    lv_obj_set_y(bk_ui->Setting_coffe_image_4, 10);
    lv_obj_set_width(bk_ui->Setting_coffe_image_4, 20);
    lv_obj_set_height(bk_ui->Setting_coffe_image_4, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_image_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_image_4, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_image_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_image_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_image_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_image_4, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_image_4, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_image_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(bk_ui->Setting_coffe_image_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(bk_ui->Setting_coffe_image_4, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(bk_ui->Setting_coffe_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_label_4 = lv_label_create(bk_ui->Setting_coffe_obj_4);
    lv_label_set_text(bk_ui->Setting_coffe_label_4, "维护保养");
    lv_label_set_long_mode(bk_ui->Setting_coffe_label_4, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_coffe_label_4, 31);
    lv_obj_set_y(bk_ui->Setting_coffe_label_4, 10);
    lv_obj_set_width(bk_ui->Setting_coffe_label_4, 76);
    lv_obj_set_height(bk_ui->Setting_coffe_label_4, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_label_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_label_4, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_label_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_label_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_label_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_label_4, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_coffe_label_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_coffe_label_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_coffe_label_4, &lv_font_ali_15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_coffe_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_coffe_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_label_4, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_label_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_obj_5 = lv_obj_create(bk_ui->Setting_coffe_obj_1);
    lv_obj_set_x(bk_ui->Setting_coffe_obj_5, 15);
    lv_obj_set_y(bk_ui->Setting_coffe_obj_5, 230);
    lv_obj_set_width(bk_ui->Setting_coffe_obj_5, 150);
    lv_obj_set_height(bk_ui->Setting_coffe_obj_5, 40);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_5, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_5, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_5, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_obj_5, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_obj_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_5, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_5, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_5, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_5, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_5, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_5, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_5, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_5, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_5, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Setting_coffe_obj_5, Setting_coffe_obj_5_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Setting_coffe_image_5 = lv_image_create(bk_ui->Setting_coffe_obj_5);
    lv_image_set_src(bk_ui->Setting_coffe_image_5, &setting_32x32_RGB565A8_NONE);
    lv_image_set_pivot(bk_ui->Setting_coffe_image_5, 50, 50);
    lv_image_set_rotation(bk_ui->Setting_coffe_image_5, 0);
    lv_obj_set_x(bk_ui->Setting_coffe_image_5, -3);
    lv_obj_set_y(bk_ui->Setting_coffe_image_5, 4);
    lv_obj_set_width(bk_ui->Setting_coffe_image_5, 32);
    lv_obj_set_height(bk_ui->Setting_coffe_image_5, 32);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_image_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_image_5, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_image_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_image_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_image_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_image_5, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_image_5, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_image_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(bk_ui->Setting_coffe_image_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(bk_ui->Setting_coffe_image_5, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(bk_ui->Setting_coffe_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_label_5 = lv_label_create(bk_ui->Setting_coffe_obj_5);
    lv_label_set_text(bk_ui->Setting_coffe_label_5, "系统设置");
    lv_label_set_long_mode(bk_ui->Setting_coffe_label_5, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_coffe_label_5, 31);
    lv_obj_set_y(bk_ui->Setting_coffe_label_5, 10);
    lv_obj_set_width(bk_ui->Setting_coffe_label_5, 76);
    lv_obj_set_height(bk_ui->Setting_coffe_label_5, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_label_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_label_5, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_label_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_label_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_label_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_label_5, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_coffe_label_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_coffe_label_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_coffe_label_5, &lv_font_ali_15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_coffe_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_coffe_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_label_5, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_label_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_obj_8 = lv_obj_create(bk_ui->Setting_coffe);
    lv_obj_set_x(bk_ui->Setting_coffe_obj_8, 180);
    lv_obj_set_y(bk_ui->Setting_coffe_obj_8, 0);
    lv_obj_set_width(bk_ui->Setting_coffe_obj_8, 620);
    lv_obj_set_height(bk_ui->Setting_coffe_obj_8, 480);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_8, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_8, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_8, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_8, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_8, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_obj_8, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_obj_8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_8, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_8, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_8, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_8, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_8, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_8, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_8, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_8, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_8, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_obj_7 = lv_obj_create(bk_ui->Setting_coffe_obj_8);
    lv_obj_set_x(bk_ui->Setting_coffe_obj_7, 20);
    lv_obj_set_y(bk_ui->Setting_coffe_obj_7, 20);
    lv_obj_set_width(bk_ui->Setting_coffe_obj_7, 553);
    lv_obj_set_height(bk_ui->Setting_coffe_obj_7, 40);
    lv_obj_remove_flag(bk_ui->Setting_coffe_obj_7, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_7, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_7, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_7, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_7, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_7, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_obj_7, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_obj_7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_7, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_7, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_7, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_7, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_7, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_7, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_7, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_7, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_7, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_label_6 = lv_label_create(bk_ui->Setting_coffe_obj_7);
    lv_label_set_text(bk_ui->Setting_coffe_label_6, "咖啡浓度");
    lv_label_set_long_mode(bk_ui->Setting_coffe_label_6, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_coffe_label_6, 0);
    lv_obj_set_y(bk_ui->Setting_coffe_label_6, 0);
    lv_obj_set_width(bk_ui->Setting_coffe_label_6, 553);
    lv_obj_set_height(bk_ui->Setting_coffe_label_6, 22);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_label_6, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_label_6, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_label_6, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_label_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_label_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_label_6, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_coffe_label_6, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_coffe_label_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_coffe_label_6, &lv_font_ali_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_coffe_label_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_coffe_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_label_6, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_label_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_line_1 = lv_line_create(bk_ui->Setting_coffe_obj_7);
    static lv_point_precise_t Setting_coffe_line_1_points[] = {
        { 0, 0 },
        { 553, 0 }
    };
    lv_line_set_points(bk_ui->Setting_coffe_line_1, Setting_coffe_line_1_points, 2);
    lv_line_set_y_invert(bk_ui->Setting_coffe_line_1, false);
    lv_obj_set_x(bk_ui->Setting_coffe_line_1, 0);
    lv_obj_set_y(bk_ui->Setting_coffe_line_1, 30);
    lv_obj_set_width(bk_ui->Setting_coffe_line_1, 553);
    lv_obj_set_height(bk_ui->Setting_coffe_line_1, 100);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_line_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_line_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_line_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(bk_ui->Setting_coffe_line_1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(bk_ui->Setting_coffe_line_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(bk_ui->Setting_coffe_line_1, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(bk_ui->Setting_coffe_line_1, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_slider_1 = lv_slider_create(bk_ui->Setting_coffe_obj_8);
    lv_slider_set_range(bk_ui->Setting_coffe_slider_1, 0, 100);
    lv_slider_set_value(bk_ui->Setting_coffe_slider_1, 30, LV_ANIM_OFF);
    lv_slider_set_mode(bk_ui->Setting_coffe_slider_1, LV_SLIDER_MODE_NORMAL);
    lv_obj_set_x(bk_ui->Setting_coffe_slider_1, 26);
    lv_obj_set_y(bk_ui->Setting_coffe_slider_1, 91);
    lv_obj_set_width(bk_ui->Setting_coffe_slider_1, 550);
    lv_obj_set_height(bk_ui->Setting_coffe_slider_1, 10);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_slider_1, lv_color_hex(0xc0c0c0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_slider_1, 99, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_slider_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_slider_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_slider_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_slider_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_slider_1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_slider_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_slider_1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_slider_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(bk_ui->Setting_coffe_slider_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(bk_ui->Setting_coffe_slider_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(bk_ui->Setting_coffe_slider_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_slider_1, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_slider_1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_slider_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_slider_1, lv_color_hex(0xffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_slider_1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_slider_1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_slider_1, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_slider_1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_slider_1, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_slider_1, lv_color_hex(0xffffff), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_slider_1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_slider_1, LV_GRAD_DIR_NONE, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_slider_1, lv_color_hex(0xffffff), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_slider_1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_slider_1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_slider_1, LV_BORDER_SIDE_FULL, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_slider_1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_slider_1, false, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_slider_1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_slider_1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_slider_1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_slider_1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_slider_1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_slider_1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_slider_1, lv_color_hex(0x1e7fcf), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_slider_1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_slider_1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_slider_1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_slider_1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_slider_1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_label_7 = lv_label_create(bk_ui->Setting_coffe_obj_8);
    lv_label_set_text(bk_ui->Setting_coffe_label_7, "淡");
    lv_label_set_long_mode(bk_ui->Setting_coffe_label_7, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_coffe_label_7, 29);
    lv_obj_set_y(bk_ui->Setting_coffe_label_7, 106);
    lv_obj_set_width(bk_ui->Setting_coffe_label_7, 60);
    lv_obj_set_height(bk_ui->Setting_coffe_label_7, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_label_7, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_label_7, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_label_7, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_label_7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_label_7, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_label_7, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_coffe_label_7, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_coffe_label_7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_coffe_label_7, &lv_font_ali_15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_coffe_label_7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_coffe_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_label_7, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_label_7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_label_8 = lv_label_create(bk_ui->Setting_coffe_obj_8);
    lv_label_set_text(bk_ui->Setting_coffe_label_8, "浓");
    lv_label_set_long_mode(bk_ui->Setting_coffe_label_8, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_coffe_label_8, 513);
    lv_obj_set_y(bk_ui->Setting_coffe_label_8, 109);
    lv_obj_set_width(bk_ui->Setting_coffe_label_8, 60);
    lv_obj_set_height(bk_ui->Setting_coffe_label_8, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_label_8, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_label_8, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_label_8, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_label_8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_label_8, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_label_8, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_coffe_label_8, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_coffe_label_8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_coffe_label_8, &lv_font_ali_15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_coffe_label_8, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_coffe_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_label_8, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_label_8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_obj_9 = lv_obj_create(bk_ui->Setting_coffe_obj_8);
    lv_obj_set_x(bk_ui->Setting_coffe_obj_9, 20);
    lv_obj_set_y(bk_ui->Setting_coffe_obj_9, 170);
    lv_obj_set_width(bk_ui->Setting_coffe_obj_9, 553);
    lv_obj_set_height(bk_ui->Setting_coffe_obj_9, 40);
    lv_obj_remove_flag(bk_ui->Setting_coffe_obj_9, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_9, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_9, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_9, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_9, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_9, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_obj_9, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_obj_9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_obj_9, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_obj_9, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_obj_9, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_obj_9, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_obj_9, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_obj_9, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_obj_9, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_obj_9, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_obj_9, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_label_9 = lv_label_create(bk_ui->Setting_coffe_obj_9);
    lv_label_set_text(bk_ui->Setting_coffe_label_9, "预磨咖啡量");
    lv_label_set_long_mode(bk_ui->Setting_coffe_label_9, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_coffe_label_9, 0);
    lv_obj_set_y(bk_ui->Setting_coffe_label_9, 0);
    lv_obj_set_width(bk_ui->Setting_coffe_label_9, 553);
    lv_obj_set_height(bk_ui->Setting_coffe_label_9, 22);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_label_9, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_label_9, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_label_9, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_label_9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_label_9, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_label_9, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_coffe_label_9, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_coffe_label_9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_coffe_label_9, &lv_font_ali_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_coffe_label_9, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_coffe_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_label_9, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_label_9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_line_2 = lv_line_create(bk_ui->Setting_coffe_obj_9);
    static lv_point_precise_t Setting_coffe_line_2_points[] = {
        { 0, 0 },
        { 553, 0 }
    };
    lv_line_set_points(bk_ui->Setting_coffe_line_2, Setting_coffe_line_2_points, 2);
    lv_line_set_y_invert(bk_ui->Setting_coffe_line_2, false);
    lv_obj_set_x(bk_ui->Setting_coffe_line_2, 0);
    lv_obj_set_y(bk_ui->Setting_coffe_line_2, 30);
    lv_obj_set_width(bk_ui->Setting_coffe_line_2, 553);
    lv_obj_set_height(bk_ui->Setting_coffe_line_2, 100);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_line_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_line_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_line_2, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(bk_ui->Setting_coffe_line_2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(bk_ui->Setting_coffe_line_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(bk_ui->Setting_coffe_line_2, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(bk_ui->Setting_coffe_line_2, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_coffe_dropdown_1 = lv_dropdown_create(bk_ui->Setting_coffe_obj_8);
    lv_obj_set_x(bk_ui->Setting_coffe_dropdown_1, 26);
    lv_obj_set_y(bk_ui->Setting_coffe_dropdown_1, 210);
    lv_obj_set_width(bk_ui->Setting_coffe_dropdown_1, 547);
    lv_obj_set_height(bk_ui->Setting_coffe_dropdown_1, 35);
    lv_dropdown_set_options(bk_ui->Setting_coffe_dropdown_1, "Light\nStandard\nHeavy");
    bk_ui->Setting_coffe_dropdown_1_list = lv_dropdown_get_list(bk_ui->Setting_coffe_dropdown_1);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_dropdown_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_dropdown_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_dropdown_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_dropdown_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_dropdown_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_dropdown_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_coffe_dropdown_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_coffe_dropdown_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_coffe_dropdown_1, &lv_font_montserrat_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_coffe_dropdown_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_coffe_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_dropdown_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_dropdown_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_dropdown_1_list, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_dropdown_1_list, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_dropdown_1_list, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_dropdown_1_list, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_dropdown_1_list, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_dropdown_1_list, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_dropdown_1_list, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_coffe_dropdown_1_list, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_coffe_dropdown_1_list, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_coffe_dropdown_1_list, &lv_font_montserrat_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_coffe_dropdown_1_list, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_coffe_dropdown_1_list, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_coffe_dropdown_1_list, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_dropdown_1_list, lv_color_hex(0xff5722), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_dropdown_1_list, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_dropdown_1_list, LV_GRAD_DIR_NONE, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_coffe_dropdown_1_list, lv_color_hex(0xffffff), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_coffe_dropdown_1_list, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_coffe_dropdown_1_list, LV_BORDER_SIDE_FULL, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_coffe_dropdown_1_list, false, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_coffe_dropdown_1_list, lv_color_hex(0x673ab7), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_coffe_dropdown_1_list, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_coffe_dropdown_1_list, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_coffe_dropdown_1_list, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    lv_obj_update_layout(bk_ui->Setting_coffe);
}

/*
 * @brief: destroy page Setting_coffe
 */
void destroy_page_Setting_coffe(bk_lv_ui_t *bk_ui)
{
    if (bk_ui == NULL) {
        return;
    }
    
    if (bk_ui->Setting_coffe != NULL) {
        lv_obj_del(bk_ui->Setting_coffe);
        bk_ui->Setting_coffe = NULL;
    }
}