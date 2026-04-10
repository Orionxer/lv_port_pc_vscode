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
 * @brief Event callback for Make_pause_btn - handles all events
 * @param e LVGL event object
 */
void Make_pause_btn_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        lv_obj_set_flag(bk_ui->Make_continue_btn, LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLL_MOMENTUM, true);
        lv_obj_set_flag(bk_ui->Make_continue_btn, LV_OBJ_FLAG_OVERFLOW_VISIBLE | LV_OBJ_FLAG_FLEX_IN_NEW_TRACK | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_SCROLL_ONE | LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS | LV_OBJ_FLAG_SCROLLABLE, false);
        
        lv_obj_set_flag(bk_ui->Make_pause_btn, LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_HIDDEN, true);
        lv_obj_set_flag(bk_ui->Make_pause_btn, LV_OBJ_FLAG_OVERFLOW_VISIBLE | LV_OBJ_FLAG_FLEX_IN_NEW_TRACK | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_SCROLL_ONE | LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS | LV_OBJ_FLAG_SCROLLABLE, false);
        
        lv_obj_set_flag(bk_ui->Make_animimg_1, LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_HIDDEN, true);
        lv_obj_set_flag(bk_ui->Make_animimg_1, LV_OBJ_FLAG_OVERFLOW_VISIBLE | LV_OBJ_FLAG_FLEX_IN_NEW_TRACK | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SCROLL_ONE | LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS, false);
        
        lv_obj_set_flag(bk_ui->Make_image_1, LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLL_MOMENTUM, true);
        lv_obj_set_flag(bk_ui->Make_image_1, LV_OBJ_FLAG_OVERFLOW_VISIBLE | LV_OBJ_FLAG_FLEX_IN_NEW_TRACK | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_SCROLL_ONE | LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS, false);
        
        lv_label_set_text(bk_ui->Make_label_1, "制作已暂停");
        
    }
}

/**
 * @brief Event callback for Make_continue_btn - handles all events
 * @param e LVGL event object
 */
void Make_continue_btn_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        lv_obj_set_flag(bk_ui->Make_pause_btn, LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLL_MOMENTUM, true);
        lv_obj_set_flag(bk_ui->Make_pause_btn, LV_OBJ_FLAG_OVERFLOW_VISIBLE | LV_OBJ_FLAG_FLEX_IN_NEW_TRACK | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_SCROLL_ONE | LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS | LV_OBJ_FLAG_SCROLLABLE, false);
        
        lv_obj_set_flag(bk_ui->Make_continue_btn, LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_HIDDEN, true);
        lv_obj_set_flag(bk_ui->Make_continue_btn, LV_OBJ_FLAG_OVERFLOW_VISIBLE | LV_OBJ_FLAG_FLEX_IN_NEW_TRACK | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_SCROLL_ONE | LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS | LV_OBJ_FLAG_SCROLLABLE, false);
        
        lv_obj_set_flag(bk_ui->Make_image_1, LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_HIDDEN, true);
        lv_obj_set_flag(bk_ui->Make_image_1, LV_OBJ_FLAG_OVERFLOW_VISIBLE | LV_OBJ_FLAG_FLEX_IN_NEW_TRACK | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SCROLL_ONE | LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS, false);
        
        lv_animimg_start(bk_ui->Make_animimg_1);
        lv_obj_set_flag(bk_ui->Make_animimg_1, LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLL_MOMENTUM, true);
        lv_obj_set_flag(bk_ui->Make_animimg_1, LV_OBJ_FLAG_OVERFLOW_VISIBLE | LV_OBJ_FLAG_FLEX_IN_NEW_TRACK | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_SCROLL_ONE | LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS, false);
        
        lv_label_set_text(bk_ui->Make_label_1, "正在为您制作，请耐心等待...");
        
    }
}

/**
 * @brief Event callback for Make_obj_1 - handles all events
 * @param e LVGL event object
 */
void Make_obj_1_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        navigate_to_screen(&bk_lv_tool_ui.Home, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 250, 0, false, init_page_Home);
    }
}

/*
 * @brief: init page Make
 */
void init_page_Make(bk_lv_ui_t *bk_ui)
{
    if (bk_ui->Make != NULL && lv_obj_is_valid(bk_ui->Make)) {
        destroy_page_Make(bk_ui);
    }
    

    bk_ui->Make = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(bk_ui->Make, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_size(bk_ui->Make, 800, 480);
    lv_obj_set_style_bg_color(bk_ui->Make, lv_color_hex(0x795548), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Make, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Make, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Make_animimg_1 = lv_animimg_create(bk_ui->Make);
    static const void * Make_animimg_1_imgs[] = {
        &p_0_269x286_RGB565A8_NONE,
        &p_17_269x286_RGB565A8_NONE,
        &p_33_269x286_RGB565A8_NONE,
        &p_50_269x286_RGB565A8_NONE,
        &p_67_269x286_RGB565A8_NONE,
        &p_83_269x286_RGB565A8_NONE,
        &p_100_269x286_RGB565A8_NONE
    };
    lv_animimg_set_src(bk_ui->Make_animimg_1, Make_animimg_1_imgs, 7);
    lv_animimg_set_duration(bk_ui->Make_animimg_1, 2000 * 7);
    lv_animimg_set_repeat_count(bk_ui->Make_animimg_1, -1);
    lv_animimg_start(bk_ui->Make_animimg_1);
    lv_obj_set_x(bk_ui->Make_animimg_1, 263);
    lv_obj_set_y(bk_ui->Make_animimg_1, 41);
    lv_obj_set_width(bk_ui->Make_animimg_1, 269);
    lv_obj_set_height(bk_ui->Make_animimg_1, 286);
    lv_obj_set_style_bg_color(bk_ui->Make_animimg_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Make_animimg_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Make_animimg_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Make_animimg_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Make_animimg_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Make_animimg_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Make_animimg_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Make_animimg_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Make_animimg_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Make_animimg_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Make_animimg_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Make_animimg_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Make_animimg_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Make_animimg_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Make_animimg_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Make_pause_btn = lv_btn_create(bk_ui->Make);
    bk_ui->Make_pause_btn_label = lv_label_create(bk_ui->Make_pause_btn);
    lv_label_set_text(bk_ui->Make_pause_btn_label, "暂停制作");
    lv_label_set_long_mode(bk_ui->Make_pause_btn_label, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_align(bk_ui->Make_pause_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_x(bk_ui->Make_pause_btn, 338);
    lv_obj_set_y(bk_ui->Make_pause_btn, 397);
    lv_obj_set_width(bk_ui->Make_pause_btn, 120);
    lv_obj_set_height(bk_ui->Make_pause_btn, 40);
    lv_obj_set_style_bg_color(bk_ui->Make_pause_btn, lv_color_hex(0x2d75b9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Make_pause_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Make_pause_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Make_pause_btn, lv_color_hex(0xff9800), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Make_pause_btn, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Make_pause_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Make_pause_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Make_pause_btn, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Make_pause_btn, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Make_pause_btn, lv_color_hex(0xff9800), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Make_pause_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Make_pause_btn, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Make_pause_btn, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Make_pause_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Make_pause_btn, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Make_pause_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Make_pause_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Make_pause_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Make_pause_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Make_pause_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Make_pause_btn, Make_pause_btn_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Make_label_1 = lv_label_create(bk_ui->Make);
    lv_label_set_text(bk_ui->Make_label_1, "正在为您制作，请耐心等待...");
    lv_label_set_long_mode(bk_ui->Make_label_1, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Make_label_1, 282);
    lv_obj_set_y(bk_ui->Make_label_1, 307);
    lv_obj_set_width(bk_ui->Make_label_1, 228);
    lv_obj_set_height(bk_ui->Make_label_1, 20);
    lv_obj_set_style_bg_color(bk_ui->Make_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Make_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Make_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Make_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Make_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Make_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Make_label_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Make_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Make_label_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Make_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Make_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Make_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Make_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Make_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Make_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Make_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Make_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Make_label_1, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Make_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Make_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Make_label_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Make_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Make_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Make_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Make_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Make_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Make_continue_btn = lv_btn_create(bk_ui->Make);
    bk_ui->Make_continue_btn_label = lv_label_create(bk_ui->Make_continue_btn);
    lv_label_set_text(bk_ui->Make_continue_btn_label, "继续制作");
    lv_label_set_long_mode(bk_ui->Make_continue_btn_label, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_align(bk_ui->Make_continue_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_x(bk_ui->Make_continue_btn, 337);
    lv_obj_set_y(bk_ui->Make_continue_btn, 398);
    lv_obj_set_width(bk_ui->Make_continue_btn, 120);
    lv_obj_set_height(bk_ui->Make_continue_btn, 40);
    lv_obj_add_flag(bk_ui->Make_continue_btn, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(bk_ui->Make_continue_btn, LV_OBJ_FLAG_SCROLL_ELASTIC);
    lv_obj_set_style_bg_color(bk_ui->Make_continue_btn, lv_color_hex(0xF44336), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Make_continue_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Make_continue_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Make_continue_btn, lv_color_hex(0xff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Make_continue_btn, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Make_continue_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Make_continue_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Make_continue_btn, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Make_continue_btn, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Make_continue_btn, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Make_continue_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Make_continue_btn, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Make_continue_btn, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Make_continue_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Make_continue_btn, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Make_continue_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Make_continue_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Make_continue_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Make_continue_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Make_continue_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Make_continue_btn, Make_continue_btn_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Make_image_1 = lv_image_create(bk_ui->Make);
    lv_image_set_src(bk_ui->Make_image_1, &p_0_269x286_RGB565A8_NONE);
    lv_image_set_pivot(bk_ui->Make_image_1, 50, 50);
    lv_image_set_rotation(bk_ui->Make_image_1, 0);
    lv_obj_set_x(bk_ui->Make_image_1, 263);
    lv_obj_set_y(bk_ui->Make_image_1, 41);
    lv_obj_set_width(bk_ui->Make_image_1, 269);
    lv_obj_set_height(bk_ui->Make_image_1, 286);
    lv_obj_add_flag(bk_ui->Make_image_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_bg_color(bk_ui->Make_image_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Make_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Make_image_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Make_image_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Make_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Make_image_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Make_image_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Make_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Make_image_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Make_image_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Make_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Make_image_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Make_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Make_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Make_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(bk_ui->Make_image_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(bk_ui->Make_image_1, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(bk_ui->Make_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Make_obj_1 = lv_obj_create(bk_ui->Make);
    lv_obj_set_flex_flow(bk_ui->Make_obj_1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(bk_ui->Make_obj_1, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_x(bk_ui->Make_obj_1, 29);
    lv_obj_set_y(bk_ui->Make_obj_1, 25);
    lv_obj_set_width(bk_ui->Make_obj_1, 94);
    lv_obj_set_height(bk_ui->Make_obj_1, 38);
    lv_obj_set_style_bg_color(bk_ui->Make_obj_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Make_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Make_obj_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Make_obj_1, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Make_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Make_obj_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Make_obj_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Make_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Make_obj_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Make_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Make_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Make_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Make_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Make_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Make_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Make_obj_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Make_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Make_obj_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Make_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Make_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Make_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Make_obj_1, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Make_obj_1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Make_obj_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Make_obj_1, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Make_obj_1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Make_obj_1, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Make_obj_1, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Make_obj_1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Make_obj_1, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Make_obj_1, Make_obj_1_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Make_image_2 = lv_image_create(bk_ui->Make_obj_1);
    lv_image_set_src(bk_ui->Make_image_2, &down_white_20x20_RGB565A8_NONE);
    lv_image_set_pivot(bk_ui->Make_image_2, 50, 50);
    lv_image_set_rotation(bk_ui->Make_image_2, 0);
    lv_obj_set_x(bk_ui->Make_image_2, 0);
    lv_obj_set_y(bk_ui->Make_image_2, 0);
    lv_obj_set_width(bk_ui->Make_image_2, 20);
    lv_obj_set_height(bk_ui->Make_image_2, 20);
    lv_obj_set_style_bg_color(bk_ui->Make_image_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Make_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Make_image_2, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Make_image_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Make_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Make_image_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Make_image_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Make_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Make_image_2, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Make_image_2, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Make_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Make_image_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Make_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Make_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Make_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(bk_ui->Make_image_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(bk_ui->Make_image_2, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(bk_ui->Make_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Make_label_2 = lv_label_create(bk_ui->Make_obj_1);
    lv_label_set_text(bk_ui->Make_label_2, "Back");
    lv_label_set_long_mode(bk_ui->Make_label_2, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Make_label_2, 32);
    lv_obj_set_y(bk_ui->Make_label_2, 4);
    lv_obj_set_width(bk_ui->Make_label_2, 60);
    lv_obj_set_height(bk_ui->Make_label_2, 20);
    lv_obj_set_style_bg_color(bk_ui->Make_label_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Make_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Make_label_2, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Make_label_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Make_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Make_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Make_label_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Make_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Make_label_2, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Make_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Make_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Make_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Make_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Make_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Make_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Make_label_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Make_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Make_label_2, &lv_font_montserrat_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Make_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Make_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Make_label_2, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Make_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Make_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Make_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Make_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Make_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_update_layout(bk_ui->Make);
}

/*
 * @brief: destroy page Make
 */
void destroy_page_Make(bk_lv_ui_t *bk_ui)
{
    if (bk_ui == NULL) {
        return;
    }
    
    if (bk_ui->Make != NULL) {
        lv_obj_del(bk_ui->Make);
        bk_ui->Make = NULL;
    }
}