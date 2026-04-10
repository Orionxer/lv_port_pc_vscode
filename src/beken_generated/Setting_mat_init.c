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
 * @brief Event callback for Setting_mat_button_1 - handles all events
 * @param e LVGL event object
 */
void Setting_mat_button_1_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        navigate_to_screen(&bk_lv_tool_ui.Home, LV_SCR_LOAD_ANIM_OVER_RIGHT, 300, 0, false, init_page_Home);
    }
}

/**
 * @brief Event callback for Setting_mat_obj_2 - handles all events
 * @param e LVGL event object
 */
void Setting_mat_obj_2_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        navigate_to_screen(&bk_lv_tool_ui.Setting_coffe, LV_SCR_LOAD_ANIM_NONE, 300, 0, false, init_page_Setting_coffe);
    }
}

/**
 * @brief Event callback for Setting_mat_obj_3 - handles all events
 * @param e LVGL event object
 */
void Setting_mat_obj_3_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        navigate_to_screen(&bk_lv_tool_ui.Setting_temp, LV_SCR_LOAD_ANIM_NONE, 300, 0, false, init_page_Setting_temp);
    }
}

/**
 * @brief Event callback for Setting_mat_obj_5 - handles all events
 * @param e LVGL event object
 */
void Setting_mat_obj_5_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        navigate_to_screen(&bk_lv_tool_ui.Setting_sys, LV_SCR_LOAD_ANIM_NONE, 300, 0, false, init_page_Setting_sys);
    }
}

/**
 * @brief Event callback for Setting_mat_start - handles all events
 * @param e LVGL event object
 */
void Setting_mat_start_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        lv_obj_set_flag(bk_ui->Setting_mat_spinner_1, LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLL_MOMENTUM, true);
        lv_obj_set_flag(bk_ui->Setting_mat_spinner_1, LV_OBJ_FLAG_OVERFLOW_VISIBLE | LV_OBJ_FLAG_FLEX_IN_NEW_TRACK | LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_SCROLL_ONE | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS | LV_OBJ_FLAG_SCROLLABLE, false);
        
        lv_obj_set_flag(bk_ui->Setting_mat_start, LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_HIDDEN, true);
        lv_obj_set_flag(bk_ui->Setting_mat_start, LV_OBJ_FLAG_OVERFLOW_VISIBLE | LV_OBJ_FLAG_FLEX_IN_NEW_TRACK | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_SCROLL_ONE | LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS | LV_OBJ_FLAG_SCROLLABLE, false);
        
        lv_obj_set_flag(bk_ui->Setting_mat_stop, LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLL_MOMENTUM, true);
        lv_obj_set_flag(bk_ui->Setting_mat_stop, LV_OBJ_FLAG_OVERFLOW_VISIBLE | LV_OBJ_FLAG_FLEX_IN_NEW_TRACK | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_SCROLL_ONE | LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS | LV_OBJ_FLAG_SCROLLABLE, false);
        
        lv_label_set_text(bk_ui->Setting_mat_label_8, "咖啡机自动清洗中...");
        
    }
}

/**
 * @brief Event callback for Setting_mat_stop - handles all events
 * @param e LVGL event object
 */
void Setting_mat_stop_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        lv_obj_set_flag(bk_ui->Setting_mat_start, LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLL_MOMENTUM, true);
        lv_obj_set_flag(bk_ui->Setting_mat_start, LV_OBJ_FLAG_OVERFLOW_VISIBLE | LV_OBJ_FLAG_FLEX_IN_NEW_TRACK | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_SCROLL_ONE | LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS | LV_OBJ_FLAG_SCROLLABLE, false);
        
        lv_obj_set_flag(bk_ui->Setting_mat_spinner_1, LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_HIDDEN, true);
        lv_obj_set_flag(bk_ui->Setting_mat_spinner_1, LV_OBJ_FLAG_OVERFLOW_VISIBLE | LV_OBJ_FLAG_FLEX_IN_NEW_TRACK | LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SCROLL_ONE | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS | LV_OBJ_FLAG_SCROLLABLE, false);
        
        lv_obj_set_flag(bk_ui->Setting_mat_stop, LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_HIDDEN, true);
        lv_obj_set_flag(bk_ui->Setting_mat_stop, LV_OBJ_FLAG_OVERFLOW_VISIBLE | LV_OBJ_FLAG_FLEX_IN_NEW_TRACK | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_SCROLL_ONE | LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS | LV_OBJ_FLAG_SCROLLABLE, false);
        
        lv_label_set_text(bk_ui->Setting_mat_label_8, "自动清洁后将自动冲洗");
        
    }
}

/*
 * @brief: init page Setting_mat
 */
void init_page_Setting_mat(bk_lv_ui_t *bk_ui)
{
    if (bk_ui->Setting_mat != NULL && lv_obj_is_valid(bk_ui->Setting_mat)) {
        destroy_page_Setting_mat(bk_ui);
    }
    

    bk_ui->Setting_mat = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(bk_ui->Setting_mat, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_size(bk_ui->Setting_mat, 800, 480);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat, lv_color_hex(0x795548), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_obj_1 = lv_obj_create(bk_ui->Setting_mat);
    lv_obj_set_x(bk_ui->Setting_mat_obj_1, 0);
    lv_obj_set_y(bk_ui->Setting_mat_obj_1, 0);
    lv_obj_set_width(bk_ui->Setting_mat_obj_1, 180);
    lv_obj_set_height(bk_ui->Setting_mat_obj_1, 480);
    lv_obj_remove_flag(bk_ui->Setting_mat_obj_1, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_1, lv_color_hex(0xff9800), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_1, 59, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_1, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_obj_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_obj_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_1, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_1, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_1, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_1, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_1, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_image_1 = lv_image_create(bk_ui->Setting_mat_obj_1);
    lv_image_set_src(bk_ui->Setting_mat_image_1, &setting_32x32_RGB565A8_NONE);
    lv_image_set_pivot(bk_ui->Setting_mat_image_1, 50, 50);
    lv_image_set_rotation(bk_ui->Setting_mat_image_1, 0);
    lv_obj_set_x(bk_ui->Setting_mat_image_1, 14);
    lv_obj_set_y(bk_ui->Setting_mat_image_1, 14);
    lv_obj_set_width(bk_ui->Setting_mat_image_1, 32);
    lv_obj_set_height(bk_ui->Setting_mat_image_1, 32);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_image_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_image_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_image_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_image_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_image_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_image_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_image_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_image_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(bk_ui->Setting_mat_image_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(bk_ui->Setting_mat_image_1, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(bk_ui->Setting_mat_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_1 = lv_label_create(bk_ui->Setting_mat_obj_1);
    lv_label_set_text(bk_ui->Setting_mat_label_1, "设置");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_1, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_1, 48);
    lv_obj_set_y(bk_ui->Setting_mat_label_1, 20);
    lv_obj_set_width(bk_ui->Setting_mat_label_1, 60);
    lv_obj_set_height(bk_ui->Setting_mat_label_1, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_1, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_button_1 = lv_btn_create(bk_ui->Setting_mat_obj_1);
    bk_ui->Setting_mat_button_1_label = lv_label_create(bk_ui->Setting_mat_button_1);
    lv_label_set_text(bk_ui->Setting_mat_button_1_label, "关闭");
    lv_label_set_long_mode(bk_ui->Setting_mat_button_1_label, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_align(bk_ui->Setting_mat_button_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_x(bk_ui->Setting_mat_button_1, 0);
    lv_obj_set_y(bk_ui->Setting_mat_button_1, 440);
    lv_obj_set_width(bk_ui->Setting_mat_button_1, 180);
    lv_obj_set_height(bk_ui->Setting_mat_button_1, 40);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_button_1, lv_color_hex(0x2d75b9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_button_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_button_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_button_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_button_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_button_1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_button_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_button_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_button_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_button_1, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_button_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_button_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_button_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Setting_mat_button_1, Setting_mat_button_1_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Setting_mat_obj_2 = lv_obj_create(bk_ui->Setting_mat_obj_1);
    lv_obj_set_x(bk_ui->Setting_mat_obj_2, 15);
    lv_obj_set_y(bk_ui->Setting_mat_obj_2, 75);
    lv_obj_set_width(bk_ui->Setting_mat_obj_2, 150);
    lv_obj_set_height(bk_ui->Setting_mat_obj_2, 40);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_2, lv_color_hex(0xff5722), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_2, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_2, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_2, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_2, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_obj_2, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_obj_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_obj_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_2, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_2, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_2, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_2, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_2, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_2, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Setting_mat_obj_2, Setting_mat_obj_2_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Setting_mat_image_2 = lv_image_create(bk_ui->Setting_mat_obj_2);
    lv_image_set_src(bk_ui->Setting_mat_image_2, &coffee_setting_24x24_RGB565A8_NONE);
    lv_image_set_pivot(bk_ui->Setting_mat_image_2, 50, 50);
    lv_image_set_rotation(bk_ui->Setting_mat_image_2, 0);
    lv_obj_set_x(bk_ui->Setting_mat_image_2, 5);
    lv_obj_set_y(bk_ui->Setting_mat_image_2, 7);
    lv_obj_set_width(bk_ui->Setting_mat_image_2, 24);
    lv_obj_set_height(bk_ui->Setting_mat_image_2, 24);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_image_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_image_2, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_image_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_image_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_image_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_image_2, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_image_2, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_image_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(bk_ui->Setting_mat_image_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(bk_ui->Setting_mat_image_2, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(bk_ui->Setting_mat_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_2 = lv_label_create(bk_ui->Setting_mat_obj_2);
    lv_label_set_text(bk_ui->Setting_mat_label_2, "咖啡设置");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_2, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_2, 31);
    lv_obj_set_y(bk_ui->Setting_mat_label_2, 10);
    lv_obj_set_width(bk_ui->Setting_mat_label_2, 76);
    lv_obj_set_height(bk_ui->Setting_mat_label_2, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_2, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_2, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_2, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_2, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_obj_3 = lv_obj_create(bk_ui->Setting_mat_obj_1);
    lv_obj_set_x(bk_ui->Setting_mat_obj_3, 15);
    lv_obj_set_y(bk_ui->Setting_mat_obj_3, 125);
    lv_obj_set_width(bk_ui->Setting_mat_obj_3, 150);
    lv_obj_set_height(bk_ui->Setting_mat_obj_3, 40);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_3, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_3, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_3, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_obj_3, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_obj_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_3, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_3, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_3, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_3, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_3, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_3, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Setting_mat_obj_3, Setting_mat_obj_3_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Setting_mat_image_3 = lv_image_create(bk_ui->Setting_mat_obj_3);
    lv_image_set_src(bk_ui->Setting_mat_image_3, &temperature_setting_24x24_RGB565A8_NONE);
    lv_image_set_pivot(bk_ui->Setting_mat_image_3, 50, 50);
    lv_image_set_rotation(bk_ui->Setting_mat_image_3, 0);
    lv_obj_set_x(bk_ui->Setting_mat_image_3, 3);
    lv_obj_set_y(bk_ui->Setting_mat_image_3, 8);
    lv_obj_set_width(bk_ui->Setting_mat_image_3, 24);
    lv_obj_set_height(bk_ui->Setting_mat_image_3, 24);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_image_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_image_3, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_image_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_image_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_image_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_image_3, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_image_3, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_image_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(bk_ui->Setting_mat_image_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(bk_ui->Setting_mat_image_3, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(bk_ui->Setting_mat_image_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_3 = lv_label_create(bk_ui->Setting_mat_obj_3);
    lv_label_set_text(bk_ui->Setting_mat_label_3, "温度控制");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_3, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_3, 31);
    lv_obj_set_y(bk_ui->Setting_mat_label_3, 10);
    lv_obj_set_width(bk_ui->Setting_mat_label_3, 76);
    lv_obj_set_height(bk_ui->Setting_mat_label_3, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_3, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_3, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_3, &lv_font_ali_15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_3, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_obj_4 = lv_obj_create(bk_ui->Setting_mat_obj_1);
    lv_obj_set_x(bk_ui->Setting_mat_obj_4, 15);
    lv_obj_set_y(bk_ui->Setting_mat_obj_4, 175);
    lv_obj_set_width(bk_ui->Setting_mat_obj_4, 150);
    lv_obj_set_height(bk_ui->Setting_mat_obj_4, 40);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_4, lv_color_hex(0xff5722), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_4, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_4, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_4, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_4, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_obj_4, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_obj_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_4, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_4, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_4, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_4, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_4, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_4, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_4, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_4, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_4, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_image_4 = lv_image_create(bk_ui->Setting_mat_obj_4);
    lv_image_set_src(bk_ui->Setting_mat_image_4, &maintenance_setting_20x20_RGB565A8_NONE);
    lv_image_set_pivot(bk_ui->Setting_mat_image_4, 50, 50);
    lv_image_set_rotation(bk_ui->Setting_mat_image_4, 0);
    lv_obj_set_x(bk_ui->Setting_mat_image_4, 5);
    lv_obj_set_y(bk_ui->Setting_mat_image_4, 10);
    lv_obj_set_width(bk_ui->Setting_mat_image_4, 20);
    lv_obj_set_height(bk_ui->Setting_mat_image_4, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_image_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_image_4, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_image_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_image_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_image_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_image_4, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_image_4, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_image_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(bk_ui->Setting_mat_image_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(bk_ui->Setting_mat_image_4, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(bk_ui->Setting_mat_image_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_4 = lv_label_create(bk_ui->Setting_mat_obj_4);
    lv_label_set_text(bk_ui->Setting_mat_label_4, "维护保养");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_4, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_4, 31);
    lv_obj_set_y(bk_ui->Setting_mat_label_4, 10);
    lv_obj_set_width(bk_ui->Setting_mat_label_4, 76);
    lv_obj_set_height(bk_ui->Setting_mat_label_4, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_4, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_4, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_4, &lv_font_ali_15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_4, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_obj_5 = lv_obj_create(bk_ui->Setting_mat_obj_1);
    lv_obj_set_x(bk_ui->Setting_mat_obj_5, 15);
    lv_obj_set_y(bk_ui->Setting_mat_obj_5, 230);
    lv_obj_set_width(bk_ui->Setting_mat_obj_5, 150);
    lv_obj_set_height(bk_ui->Setting_mat_obj_5, 40);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_5, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_5, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_5, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_obj_5, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_obj_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_5, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_5, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_5, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_5, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_5, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_5, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_5, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_5, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_5, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Setting_mat_obj_5, Setting_mat_obj_5_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Setting_mat_image_5 = lv_image_create(bk_ui->Setting_mat_obj_5);
    lv_image_set_src(bk_ui->Setting_mat_image_5, &setting_32x32_RGB565A8_NONE);
    lv_image_set_pivot(bk_ui->Setting_mat_image_5, 50, 50);
    lv_image_set_rotation(bk_ui->Setting_mat_image_5, 0);
    lv_obj_set_x(bk_ui->Setting_mat_image_5, -3);
    lv_obj_set_y(bk_ui->Setting_mat_image_5, 4);
    lv_obj_set_width(bk_ui->Setting_mat_image_5, 32);
    lv_obj_set_height(bk_ui->Setting_mat_image_5, 32);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_image_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_image_5, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_image_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_image_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_image_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_image_5, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_image_5, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_image_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(bk_ui->Setting_mat_image_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(bk_ui->Setting_mat_image_5, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(bk_ui->Setting_mat_image_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_5 = lv_label_create(bk_ui->Setting_mat_obj_5);
    lv_label_set_text(bk_ui->Setting_mat_label_5, "系统设置");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_5, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_5, 31);
    lv_obj_set_y(bk_ui->Setting_mat_label_5, 10);
    lv_obj_set_width(bk_ui->Setting_mat_label_5, 76);
    lv_obj_set_height(bk_ui->Setting_mat_label_5, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_5, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_5, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_5, &lv_font_ali_15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_5, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_obj_6 = lv_obj_create(bk_ui->Setting_mat);
    lv_obj_set_x(bk_ui->Setting_mat_obj_6, 180);
    lv_obj_set_y(bk_ui->Setting_mat_obj_6, 0);
    lv_obj_set_width(bk_ui->Setting_mat_obj_6, 620);
    lv_obj_set_height(bk_ui->Setting_mat_obj_6, 480);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_6, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_6, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_6, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_6, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_obj_6, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_obj_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_6, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_6, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_6, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_6, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_6, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_6, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_6, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_6, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_6, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_obj_7 = lv_obj_create(bk_ui->Setting_mat_obj_6);
    lv_obj_set_x(bk_ui->Setting_mat_obj_7, 20);
    lv_obj_set_y(bk_ui->Setting_mat_obj_7, 20);
    lv_obj_set_width(bk_ui->Setting_mat_obj_7, 553);
    lv_obj_set_height(bk_ui->Setting_mat_obj_7, 40);
    lv_obj_remove_flag(bk_ui->Setting_mat_obj_7, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_7, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_7, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_7, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_7, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_7, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_obj_7, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_obj_7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_obj_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_7, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_7, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_7, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_7, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_7, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_7, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_7, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_7, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_7, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_6 = lv_label_create(bk_ui->Setting_mat_obj_7);
    lv_label_set_text(bk_ui->Setting_mat_label_6, "自动清洁");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_6, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_6, 0);
    lv_obj_set_y(bk_ui->Setting_mat_label_6, 0);
    lv_obj_set_width(bk_ui->Setting_mat_label_6, 553);
    lv_obj_set_height(bk_ui->Setting_mat_label_6, 22);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_6, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_6, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_6, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_6, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_6, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_6, &lv_font_ali_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_6, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_line_1 = lv_line_create(bk_ui->Setting_mat_obj_7);
    static lv_point_precise_t Setting_mat_line_1_points[] = {
        { 0, 0 },
        { 553, 0 }
    };
    lv_line_set_points(bk_ui->Setting_mat_line_1, Setting_mat_line_1_points, 2);
    lv_line_set_y_invert(bk_ui->Setting_mat_line_1, false);
    lv_obj_set_x(bk_ui->Setting_mat_line_1, 0);
    lv_obj_set_y(bk_ui->Setting_mat_line_1, 30);
    lv_obj_set_width(bk_ui->Setting_mat_line_1, 553);
    lv_obj_set_height(bk_ui->Setting_mat_line_1, 100);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_line_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_line_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_line_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(bk_ui->Setting_mat_line_1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(bk_ui->Setting_mat_line_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(bk_ui->Setting_mat_line_1, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(bk_ui->Setting_mat_line_1, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_obj_9 = lv_obj_create(bk_ui->Setting_mat_obj_6);
    lv_obj_set_x(bk_ui->Setting_mat_obj_9, 20);
    lv_obj_set_y(bk_ui->Setting_mat_obj_9, 159);
    lv_obj_set_width(bk_ui->Setting_mat_obj_9, 553);
    lv_obj_set_height(bk_ui->Setting_mat_obj_9, 40);
    lv_obj_remove_flag(bk_ui->Setting_mat_obj_9, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_9, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_9, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_9, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_9, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_9, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_obj_9, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_obj_9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_obj_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_9, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_9, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_9, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_9, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_9, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_9, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_9, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_9, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_9, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_9 = lv_label_create(bk_ui->Setting_mat_obj_9);
    lv_label_set_text(bk_ui->Setting_mat_label_9, "水质硬度");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_9, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_9, 0);
    lv_obj_set_y(bk_ui->Setting_mat_label_9, 0);
    lv_obj_set_width(bk_ui->Setting_mat_label_9, 553);
    lv_obj_set_height(bk_ui->Setting_mat_label_9, 22);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_9, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_9, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_9, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_9, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_9, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_9, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_9, &lv_font_ali_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_9, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_9, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_line_2 = lv_line_create(bk_ui->Setting_mat_obj_9);
    static lv_point_precise_t Setting_mat_line_2_points[] = {
        { 0, 0 },
        { 553, 0 }
    };
    lv_line_set_points(bk_ui->Setting_mat_line_2, Setting_mat_line_2_points, 2);
    lv_line_set_y_invert(bk_ui->Setting_mat_line_2, false);
    lv_obj_set_x(bk_ui->Setting_mat_line_2, 0);
    lv_obj_set_y(bk_ui->Setting_mat_line_2, 30);
    lv_obj_set_width(bk_ui->Setting_mat_line_2, 553);
    lv_obj_set_height(bk_ui->Setting_mat_line_2, 100);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_line_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_line_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_line_2, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(bk_ui->Setting_mat_line_2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(bk_ui->Setting_mat_line_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(bk_ui->Setting_mat_line_2, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(bk_ui->Setting_mat_line_2, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_obj_10 = lv_obj_create(bk_ui->Setting_mat_obj_6);
    lv_obj_set_x(bk_ui->Setting_mat_obj_10, 20);
    lv_obj_set_y(bk_ui->Setting_mat_obj_10, 279);
    lv_obj_set_width(bk_ui->Setting_mat_obj_10, 553);
    lv_obj_set_height(bk_ui->Setting_mat_obj_10, 40);
    lv_obj_remove_flag(bk_ui->Setting_mat_obj_10, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_10, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_10, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_10, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_10, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_10, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_obj_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_obj_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_obj_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_obj_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_obj_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_obj_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_obj_10, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_obj_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_obj_10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_obj_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_obj_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_obj_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_10, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_10, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_10, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_10, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_10, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_10, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_10, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_10, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_10, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_10 = lv_label_create(bk_ui->Setting_mat_obj_10);
    lv_label_set_text(bk_ui->Setting_mat_label_10, "使用统计");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_10, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_10, 0);
    lv_obj_set_y(bk_ui->Setting_mat_label_10, 0);
    lv_obj_set_width(bk_ui->Setting_mat_label_10, 553);
    lv_obj_set_height(bk_ui->Setting_mat_label_10, 22);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_10, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_10, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_10, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_10, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_10, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_10, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_10, &lv_font_ali_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_10, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_10, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_line_3 = lv_line_create(bk_ui->Setting_mat_obj_10);
    static lv_point_precise_t Setting_mat_line_3_points[] = {
        { 0, 0 },
        { 553, 0 }
    };
    lv_line_set_points(bk_ui->Setting_mat_line_3, Setting_mat_line_3_points, 2);
    lv_line_set_y_invert(bk_ui->Setting_mat_line_3, false);
    lv_obj_set_x(bk_ui->Setting_mat_line_3, 0);
    lv_obj_set_y(bk_ui->Setting_mat_line_3, 30);
    lv_obj_set_width(bk_ui->Setting_mat_line_3, 553);
    lv_obj_set_height(bk_ui->Setting_mat_line_3, 100);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_line_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_line_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_line_3, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(bk_ui->Setting_mat_line_3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(bk_ui->Setting_mat_line_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(bk_ui->Setting_mat_line_3, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(bk_ui->Setting_mat_line_3, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_obj_11 = lv_obj_create(bk_ui->Setting_mat_obj_6);
    lv_obj_set_flex_flow(bk_ui->Setting_mat_obj_11, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(bk_ui->Setting_mat_obj_11, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_x(bk_ui->Setting_mat_obj_11, 16);
    lv_obj_set_y(bk_ui->Setting_mat_obj_11, 334);
    lv_obj_set_width(bk_ui->Setting_mat_obj_11, 556);
    lv_obj_set_height(bk_ui->Setting_mat_obj_11, 121);
    lv_obj_remove_flag(bk_ui->Setting_mat_obj_11, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_11, lv_color_hex(0xffeb3b), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_11, 51, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_11, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_11, lv_color_hex(0xff5722), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_11, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_11, 38, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_11, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_11, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_11, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_obj_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_obj_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_obj_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_obj_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_obj_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_obj_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_obj_11, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_obj_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_obj_11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_obj_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_obj_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_obj_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_11, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_11, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_11, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_11, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_11, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_11, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_11, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_11, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_11, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_obj_12 = lv_obj_create(bk_ui->Setting_mat_obj_11);
    lv_obj_set_flex_flow(bk_ui->Setting_mat_obj_12, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(bk_ui->Setting_mat_obj_12, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_x(bk_ui->Setting_mat_obj_12, 0);
    lv_obj_set_y(bk_ui->Setting_mat_obj_12, 0);
    lv_obj_set_width(bk_ui->Setting_mat_obj_12, 550);
    lv_obj_set_height(bk_ui->Setting_mat_obj_12, 40);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_12, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_12, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_12, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_12, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_12, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_obj_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_obj_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_obj_12, 9, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_obj_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_obj_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_obj_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_obj_12, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_obj_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_obj_12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_obj_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_obj_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_obj_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_12, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_12, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_12, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_12, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_12, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_12, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_12, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_12, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_12, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_11 = lv_label_create(bk_ui->Setting_mat_obj_12);
    lv_label_set_text(bk_ui->Setting_mat_label_11, "已制作咖啡");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_11, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_11, 212);
    lv_obj_set_y(bk_ui->Setting_mat_label_11, 0);
    lv_obj_set_width(bk_ui->Setting_mat_label_11, 140);
    lv_obj_set_height(bk_ui->Setting_mat_label_11, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_11, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_11, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_11, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_11, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_11, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_11, lv_color_hex(0xffc107), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_11, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_11, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_11, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_12 = lv_label_create(bk_ui->Setting_mat_obj_12);
    lv_label_set_text(bk_ui->Setting_mat_label_12, "342杯");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_12, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_12, 232);
    lv_obj_set_y(bk_ui->Setting_mat_label_12, 20);
    lv_obj_set_width(bk_ui->Setting_mat_label_12, 60);
    lv_obj_set_height(bk_ui->Setting_mat_label_12, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_12, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_12, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_12, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_12, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_12, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_12, lv_color_hex(0xffeb3b), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_12, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_12, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_12, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_obj_13 = lv_obj_create(bk_ui->Setting_mat_obj_11);
    lv_obj_set_flex_flow(bk_ui->Setting_mat_obj_13, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(bk_ui->Setting_mat_obj_13, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_x(bk_ui->Setting_mat_obj_13, 20);
    lv_obj_set_y(bk_ui->Setting_mat_obj_13, 20);
    lv_obj_set_width(bk_ui->Setting_mat_obj_13, 550);
    lv_obj_set_height(bk_ui->Setting_mat_obj_13, 40);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_13, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_13, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_13, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_13, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_13, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_obj_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_obj_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_obj_13, 9, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_obj_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_obj_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_obj_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_obj_13, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_obj_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_obj_13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_obj_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_obj_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_obj_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_13, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_13, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_13, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_13, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_13, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_13, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_13, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_13, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_13, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_13 = lv_label_create(bk_ui->Setting_mat_obj_13);
    lv_label_set_text(bk_ui->Setting_mat_label_13, "距离除垢");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_13, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_13, 212);
    lv_obj_set_y(bk_ui->Setting_mat_label_13, 0);
    lv_obj_set_width(bk_ui->Setting_mat_label_13, 140);
    lv_obj_set_height(bk_ui->Setting_mat_label_13, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_13, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_13, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_13, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_13, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_13, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_13, lv_color_hex(0xffc107), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_13, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_13, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_13, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_14 = lv_label_create(bk_ui->Setting_mat_obj_13);
    lv_label_set_text(bk_ui->Setting_mat_label_14, "158杯");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_14, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_14, 232);
    lv_obj_set_y(bk_ui->Setting_mat_label_14, 20);
    lv_obj_set_width(bk_ui->Setting_mat_label_14, 60);
    lv_obj_set_height(bk_ui->Setting_mat_label_14, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_14, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_14, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_14, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_14, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_14, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_14, lv_color_hex(0xffeb3b), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_14, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_14, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_14, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_obj_14 = lv_obj_create(bk_ui->Setting_mat_obj_11);
    lv_obj_set_flex_flow(bk_ui->Setting_mat_obj_14, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(bk_ui->Setting_mat_obj_14, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_x(bk_ui->Setting_mat_obj_14, 0);
    lv_obj_set_y(bk_ui->Setting_mat_obj_14, 0);
    lv_obj_set_width(bk_ui->Setting_mat_obj_14, 550);
    lv_obj_set_height(bk_ui->Setting_mat_obj_14, 40);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_14, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_14, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_14, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_14, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_14, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_obj_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_obj_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_obj_14, 9, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_obj_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_obj_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_obj_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_obj_14, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_obj_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_obj_14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_obj_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_obj_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_obj_14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_14, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_14, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_14, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_14, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_14, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_14, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_14, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_14, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_14, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_15 = lv_label_create(bk_ui->Setting_mat_obj_14);
    lv_label_set_text(bk_ui->Setting_mat_label_15, "距离清洁");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_15, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_15, 212);
    lv_obj_set_y(bk_ui->Setting_mat_label_15, 0);
    lv_obj_set_width(bk_ui->Setting_mat_label_15, 140);
    lv_obj_set_height(bk_ui->Setting_mat_label_15, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_15, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_15, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_15, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_15, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_15, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_15, lv_color_hex(0xffc107), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_15, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_15, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_15, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_16 = lv_label_create(bk_ui->Setting_mat_obj_14);
    lv_label_set_text(bk_ui->Setting_mat_label_16, "28杯");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_16, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_16, 232);
    lv_obj_set_y(bk_ui->Setting_mat_label_16, 20);
    lv_obj_set_width(bk_ui->Setting_mat_label_16, 60);
    lv_obj_set_height(bk_ui->Setting_mat_label_16, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_16, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_16, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_16, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_16, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_16, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_16, lv_color_hex(0xffeb3b), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_16, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_16, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_16, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_dropdown_1 = lv_dropdown_create(bk_ui->Setting_mat_obj_6);
    lv_obj_set_x(bk_ui->Setting_mat_dropdown_1, 20);
    lv_obj_set_y(bk_ui->Setting_mat_dropdown_1, 206);
    lv_obj_set_width(bk_ui->Setting_mat_dropdown_1, 553);
    lv_obj_set_height(bk_ui->Setting_mat_dropdown_1, 35);
    lv_dropdown_set_options(bk_ui->Setting_mat_dropdown_1, "Soft  ( < 60 mg/L)\nMedium (60 - 120 mg/L)\nHard (> 120mg/L)");
    bk_ui->Setting_mat_dropdown_1_list = lv_dropdown_get_list(bk_ui->Setting_mat_dropdown_1);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_dropdown_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_dropdown_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_dropdown_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_dropdown_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_dropdown_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_dropdown_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_dropdown_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_dropdown_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_dropdown_1, &lv_font_montserrat_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_dropdown_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_dropdown_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_dropdown_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_dropdown_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_dropdown_1_list, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_dropdown_1_list, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_dropdown_1_list, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_dropdown_1_list, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_dropdown_1_list, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_dropdown_1_list, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_dropdown_1_list, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_dropdown_1_list, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_dropdown_1_list, &lv_font_montserrat_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_dropdown_1_list, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_dropdown_1_list, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_dropdown_1_list, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_dropdown_1_list, lv_color_hex(0xffffff), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_dropdown_1_list, LV_GRAD_DIR_NONE, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_dropdown_1_list, lv_color_hex(0xffffff), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_dropdown_1_list, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_dropdown_1_list, LV_BORDER_SIDE_FULL, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_dropdown_1_list, false, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_dropdown_1_list, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_dropdown_1_list, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_dropdown_1_list, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_obj_8 = lv_obj_create(bk_ui->Setting_mat);
    lv_obj_set_x(bk_ui->Setting_mat_obj_8, 203);
    lv_obj_set_y(bk_ui->Setting_mat_obj_8, 66);
    lv_obj_set_width(bk_ui->Setting_mat_obj_8, 552);
    lv_obj_set_height(bk_ui->Setting_mat_obj_8, 63);
    lv_obj_remove_flag(bk_ui->Setting_mat_obj_8, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_8, lv_color_hex(0x9e9e9e), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_8, 46, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_8, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_8, lv_color_hex(0x9e9e9e), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_8, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_8, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_8, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_8, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_8, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_obj_8, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_obj_8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_obj_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_obj_8, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_obj_8, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_obj_8, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_obj_8, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_obj_8, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_obj_8, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_obj_8, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_obj_8, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_obj_8, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_7 = lv_label_create(bk_ui->Setting_mat_obj_8);
    lv_label_set_text(bk_ui->Setting_mat_label_7, "自动清洁");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_7, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_7, 15);
    lv_obj_set_y(bk_ui->Setting_mat_label_7, 10);
    lv_obj_set_width(bk_ui->Setting_mat_label_7, 60);
    lv_obj_set_height(bk_ui->Setting_mat_label_7, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_7, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_7, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_7, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_7, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_7, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_7, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_7, &lv_font_ali_15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_7, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_label_8 = lv_label_create(bk_ui->Setting_mat_obj_8);
    lv_label_set_text(bk_ui->Setting_mat_label_8, "自动清洁后将自动冲洗");
    lv_label_set_long_mode(bk_ui->Setting_mat_label_8, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Setting_mat_label_8, 13);
    lv_obj_set_y(bk_ui->Setting_mat_label_8, 32);
    lv_obj_set_width(bk_ui->Setting_mat_label_8, 227);
    lv_obj_set_height(bk_ui->Setting_mat_label_8, 20);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_label_8, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_label_8, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_label_8, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_label_8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_label_8, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_label_8, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_label_8, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_label_8, 161, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_label_8, &lv_font_ali_15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_label_8, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_label_8, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_label_8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_label_8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_start = lv_btn_create(bk_ui->Setting_mat_obj_8);
    bk_ui->Setting_mat_start_label = lv_label_create(bk_ui->Setting_mat_start);
    lv_label_set_text(bk_ui->Setting_mat_start_label, "开始");
    lv_label_set_long_mode(bk_ui->Setting_mat_start_label, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_align(bk_ui->Setting_mat_start_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_x(bk_ui->Setting_mat_start, 439);
    lv_obj_set_y(bk_ui->Setting_mat_start, 11);
    lv_obj_set_width(bk_ui->Setting_mat_start, 100);
    lv_obj_set_height(bk_ui->Setting_mat_start, 40);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_start, lv_color_hex(0x2d75b9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_start, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_start, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_start, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_start, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_start, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_start, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_start, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_start, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_start, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_start, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_start, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_start, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_start, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_start, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_start, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_start, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_start, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_start, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_start, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Setting_mat_start, Setting_mat_start_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Setting_mat_spinner_1 = lv_spinner_create(bk_ui->Setting_mat_obj_8);
    lv_spinner_set_anim_params(bk_ui->Setting_mat_spinner_1, 2000, 50);
    lv_obj_set_x(bk_ui->Setting_mat_spinner_1, 428);
    lv_obj_set_y(bk_ui->Setting_mat_spinner_1, 15);
    lv_obj_set_width(bk_ui->Setting_mat_spinner_1, 30);
    lv_obj_set_height(bk_ui->Setting_mat_spinner_1, 30);
    lv_obj_add_flag(bk_ui->Setting_mat_spinner_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_spinner_1, lv_color_hex(0xeeeef6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_spinner_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_spinner_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Setting_mat_spinner_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Setting_mat_spinner_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Setting_mat_spinner_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Setting_mat_spinner_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Setting_mat_spinner_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Setting_mat_spinner_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_spinner_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_spinner_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_spinner_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_spinner_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_spinner_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_spinner_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(bk_ui->Setting_mat_spinner_1, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(bk_ui->Setting_mat_spinner_1, lv_color_hex(0xd5d6de), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(bk_ui->Setting_mat_spinner_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(bk_ui->Setting_mat_spinner_1, true, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(bk_ui->Setting_mat_spinner_1, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(bk_ui->Setting_mat_spinner_1, lv_color_hex(0xff5722), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(bk_ui->Setting_mat_spinner_1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(bk_ui->Setting_mat_spinner_1, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    bk_ui->Setting_mat_stop = lv_btn_create(bk_ui->Setting_mat_obj_8);
    bk_ui->Setting_mat_stop_label = lv_label_create(bk_ui->Setting_mat_stop);
    lv_label_set_text(bk_ui->Setting_mat_stop_label, "停止");
    lv_label_set_long_mode(bk_ui->Setting_mat_stop_label, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_align(bk_ui->Setting_mat_stop_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_x(bk_ui->Setting_mat_stop, 439);
    lv_obj_set_y(bk_ui->Setting_mat_stop, 11);
    lv_obj_set_width(bk_ui->Setting_mat_stop, 100);
    lv_obj_set_height(bk_ui->Setting_mat_stop, 40);
    lv_obj_add_flag(bk_ui->Setting_mat_stop, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_bg_color(bk_ui->Setting_mat_stop, lv_color_hex(0x2d75b9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Setting_mat_stop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Setting_mat_stop, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Setting_mat_stop, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Setting_mat_stop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Setting_mat_stop, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Setting_mat_stop, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Setting_mat_stop, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Setting_mat_stop, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Setting_mat_stop, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Setting_mat_stop, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Setting_mat_stop, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Setting_mat_stop, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Setting_mat_stop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Setting_mat_stop, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Setting_mat_stop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Setting_mat_stop, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Setting_mat_stop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Setting_mat_stop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Setting_mat_stop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Setting_mat_stop, Setting_mat_stop_event_cb, LV_EVENT_ALL, NULL);

    lv_obj_update_layout(bk_ui->Setting_mat);
}

/*
 * @brief: destroy page Setting_mat
 */
void destroy_page_Setting_mat(bk_lv_ui_t *bk_ui)
{
    if (bk_ui == NULL) {
        return;
    }
    
    if (bk_ui->Setting_mat != NULL) {
        lv_obj_del(bk_ui->Setting_mat);
        bk_ui->Setting_mat = NULL;
    }
}