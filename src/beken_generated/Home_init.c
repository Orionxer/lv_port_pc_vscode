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
 * @brief Event callback for Home_obj_1 - handles all events
 * @param e LVGL event object
 */
void Home_obj_1_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        lv_obj_set_style_border_color(bk_ui->Home_obj_1, lv_color_hex(0xff5722), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(bk_ui->Home_obj_4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(bk_ui->Home_obj_5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(bk_ui->Home_obj_6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_remove_state(bk_ui->Home_button_1, lv_obj_get_state(bk_ui->Home_button_1));
        lv_obj_add_state(bk_ui->Home_button_1, LV_STATE_EDITED);
        
    }
}

/**
 * @brief Event callback for Home_obj_4 - handles all events
 * @param e LVGL event object
 */
void Home_obj_4_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        lv_obj_set_style_border_color(bk_ui->Home_obj_4, lv_color_hex(0xFF5722), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(bk_ui->Home_obj_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(bk_ui->Home_obj_5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(bk_ui->Home_obj_6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_remove_state(bk_ui->Home_button_1, lv_obj_get_state(bk_ui->Home_button_1));
        lv_obj_add_state(bk_ui->Home_button_1, LV_STATE_EDITED);
        
    }
}

/**
 * @brief Event callback for Home_obj_5 - handles all events
 * @param e LVGL event object
 */
void Home_obj_5_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        lv_obj_set_style_border_color(bk_ui->Home_obj_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(bk_ui->Home_obj_4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(bk_ui->Home_obj_5, lv_color_hex(0xFF5722), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(bk_ui->Home_obj_6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_remove_state(bk_ui->Home_button_1, lv_obj_get_state(bk_ui->Home_button_1));
        lv_obj_add_state(bk_ui->Home_button_1, LV_STATE_EDITED);
        
    }
}

/**
 * @brief Event callback for Home_obj_6 - handles all events
 * @param e LVGL event object
 */
void Home_obj_6_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        lv_obj_set_style_border_color(bk_ui->Home_obj_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(bk_ui->Home_obj_4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(bk_ui->Home_obj_5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(bk_ui->Home_obj_6, lv_color_hex(0xFF5722), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(bk_ui->Home_obj_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_remove_state(bk_ui->Home_button_1, lv_obj_get_state(bk_ui->Home_button_1));
        lv_obj_add_state(bk_ui->Home_button_1, LV_STATE_EDITED);
        
    }
}

/**
 * @brief Event callback for Home_button_1 - handles all events
 * @param e LVGL event object
 */
void Home_button_1_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        navigate_to_screen(&bk_lv_tool_ui.Make, LV_SCR_LOAD_ANIM_OVER_TOP, 300, 0, false, init_page_Make);
    }
}

/**
 * @brief Event callback for Home_image_1 - handles all events
 * @param e LVGL event object
 */
void Home_image_1_event_cb(lv_event_t *e)
{
    bk_lv_ui_t *bk_ui = &bk_lv_tool_ui;   
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        navigate_to_screen(&bk_lv_tool_ui.Setting_coffe, LV_SCR_LOAD_ANIM_OVER_LEFT, 300, 0, false, init_page_Setting_coffe);
    }
}

/*
 * @brief: init page Home
 */
void init_page_Home(bk_lv_ui_t *bk_ui)
{
    if (bk_ui->Home != NULL && lv_obj_is_valid(bk_ui->Home)) {
        destroy_page_Home(bk_ui);
    }
    

    bk_ui->Home = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(bk_ui->Home, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_size(bk_ui->Home, 800, 480);
    lv_obj_set_style_bg_color(bk_ui->Home, lv_color_hex(0x795548), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Home_label_1 = lv_label_create(bk_ui->Home);
    lv_label_set_text(bk_ui->Home_label_1, "智能咖啡机");
    lv_label_set_long_mode(bk_ui->Home_label_1, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Home_label_1, 283);
    lv_obj_set_y(bk_ui->Home_label_1, 29);
    lv_obj_set_width(bk_ui->Home_label_1, 236);
    lv_obj_set_height(bk_ui->Home_label_1, 51);
    lv_obj_set_style_bg_color(bk_ui->Home_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_label_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_label_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Home_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Home_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Home_label_1, &lv_font_ali_36, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Home_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Home_label_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Home_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Home_label_2 = lv_label_create(bk_ui->Home);
    lv_label_set_text(bk_ui->Home_label_2, "选择您喜欢的咖啡，开始制作");
    lv_label_set_long_mode(bk_ui->Home_label_2, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Home_label_2, 261);
    lv_obj_set_y(bk_ui->Home_label_2, 76);
    lv_obj_set_width(bk_ui->Home_label_2, 282);
    lv_obj_set_height(bk_ui->Home_label_2, 42);
    lv_obj_set_style_bg_color(bk_ui->Home_label_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_label_2, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_label_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_label_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_label_2, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Home_label_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Home_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Home_label_2, &lv_font_ali_17, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Home_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Home_label_2, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Home_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Home_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Home_obj_3 = lv_obj_create(bk_ui->Home);
    lv_obj_set_flex_flow(bk_ui->Home_obj_3, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(bk_ui->Home_obj_3, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_x(bk_ui->Home_obj_3, 52);
    lv_obj_set_y(bk_ui->Home_obj_3, 135);
    lv_obj_set_width(bk_ui->Home_obj_3, 695);
    lv_obj_set_height(bk_ui->Home_obj_3, 177);
    lv_obj_set_style_bg_color(bk_ui->Home_obj_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_obj_3, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_obj_3, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_obj_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_obj_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_obj_3, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Home_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Home_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Home_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Home_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Home_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Home_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Home_obj_3, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Home_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Home_obj_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Home_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Home_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Home_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Home_obj_3, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_obj_3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_obj_3, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_obj_3, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_obj_3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_obj_3, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_obj_3, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_obj_3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_obj_3, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    bk_ui->Home_obj_1 = lv_obj_create(bk_ui->Home_obj_3);
    lv_obj_set_x(bk_ui->Home_obj_1, 0);
    lv_obj_set_y(bk_ui->Home_obj_1, 0);
    lv_obj_set_width(bk_ui->Home_obj_1, 160);
    lv_obj_set_height(bk_ui->Home_obj_1, 160);
    lv_obj_remove_flag(bk_ui->Home_obj_1, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(bk_ui->Home_obj_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_obj_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(bk_ui->Home_obj_1, &espresso_ARGB8888, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(bk_ui->Home_obj_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(bk_ui->Home_obj_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_obj_1, lv_color_hex(0xff5722), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_obj_1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_obj_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_obj_1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_obj_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Home_obj_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Home_obj_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Home_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Home_obj_1, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_obj_1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_obj_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_obj_1, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_obj_1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_obj_1, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_obj_1, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_obj_1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_obj_1, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Home_obj_1, Home_obj_1_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Home_label_3 = lv_label_create(bk_ui->Home_obj_1);
    lv_label_set_text(bk_ui->Home_label_3, "意式浓缩");
    lv_label_set_long_mode(bk_ui->Home_label_3, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Home_label_3, 26);
    lv_obj_set_y(bk_ui->Home_label_3, 128);
    lv_obj_set_width(bk_ui->Home_label_3, 104);
    lv_obj_set_height(bk_ui->Home_label_3, 25);
    lv_obj_set_style_bg_color(bk_ui->Home_label_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_label_3, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_label_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_label_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_label_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_label_3, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Home_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Home_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Home_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Home_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Home_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Home_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Home_label_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Home_label_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Home_label_3, &lv_font_ali_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Home_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Home_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Home_label_3, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Home_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Home_label_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Home_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Home_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Home_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Home_obj_4 = lv_obj_create(bk_ui->Home_obj_3);
    lv_obj_set_x(bk_ui->Home_obj_4, 20);
    lv_obj_set_y(bk_ui->Home_obj_4, 20);
    lv_obj_set_width(bk_ui->Home_obj_4, 160);
    lv_obj_set_height(bk_ui->Home_obj_4, 160);
    lv_obj_remove_flag(bk_ui->Home_obj_4, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(bk_ui->Home_obj_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_obj_4, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(bk_ui->Home_obj_4, &cappuccino_ARGB8888, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(bk_ui->Home_obj_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(bk_ui->Home_obj_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_obj_4, lv_color_hex(0xff5722), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_obj_4, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_obj_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_obj_4, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_obj_4, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Home_obj_4, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Home_obj_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Home_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Home_obj_4, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_obj_4, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_obj_4, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_obj_4, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_obj_4, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_obj_4, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_obj_4, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_obj_4, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_obj_4, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Home_obj_4, Home_obj_4_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Home_label_4 = lv_label_create(bk_ui->Home_obj_4);
    lv_label_set_text(bk_ui->Home_label_4, "卡布奇诺");
    lv_label_set_long_mode(bk_ui->Home_label_4, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Home_label_4, 26);
    lv_obj_set_y(bk_ui->Home_label_4, 128);
    lv_obj_set_width(bk_ui->Home_label_4, 104);
    lv_obj_set_height(bk_ui->Home_label_4, 25);
    lv_obj_set_style_bg_color(bk_ui->Home_label_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_label_4, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_label_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_label_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_label_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_label_4, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Home_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Home_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Home_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Home_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Home_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Home_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Home_label_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Home_label_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Home_label_4, &lv_font_ali_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Home_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Home_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Home_label_4, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Home_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Home_label_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Home_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Home_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Home_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Home_obj_5 = lv_obj_create(bk_ui->Home_obj_3);
    lv_obj_set_x(bk_ui->Home_obj_5, 20);
    lv_obj_set_y(bk_ui->Home_obj_5, 20);
    lv_obj_set_width(bk_ui->Home_obj_5, 160);
    lv_obj_set_height(bk_ui->Home_obj_5, 160);
    lv_obj_remove_flag(bk_ui->Home_obj_5, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(bk_ui->Home_obj_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_obj_5, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(bk_ui->Home_obj_5, &macchiato_ARGB8888, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(bk_ui->Home_obj_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(bk_ui->Home_obj_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_obj_5, lv_color_hex(0xff5722), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_obj_5, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_obj_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_obj_5, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_obj_5, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Home_obj_5, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Home_obj_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Home_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Home_obj_5, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_obj_5, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_obj_5, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_obj_5, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_obj_5, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_obj_5, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_obj_5, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_obj_5, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_obj_5, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Home_obj_5, Home_obj_5_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Home_label_5 = lv_label_create(bk_ui->Home_obj_5);
    lv_label_set_text(bk_ui->Home_label_5, "玛奇朵");
    lv_label_set_long_mode(bk_ui->Home_label_5, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Home_label_5, 26);
    lv_obj_set_y(bk_ui->Home_label_5, 128);
    lv_obj_set_width(bk_ui->Home_label_5, 104);
    lv_obj_set_height(bk_ui->Home_label_5, 25);
    lv_obj_set_style_bg_color(bk_ui->Home_label_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_label_5, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_label_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_label_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_label_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_label_5, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Home_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Home_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Home_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Home_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Home_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Home_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Home_label_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Home_label_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Home_label_5, &lv_font_ali_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Home_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Home_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Home_label_5, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Home_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Home_label_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Home_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Home_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Home_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Home_obj_6 = lv_obj_create(bk_ui->Home_obj_3);
    lv_obj_set_x(bk_ui->Home_obj_6, 40);
    lv_obj_set_y(bk_ui->Home_obj_6, 40);
    lv_obj_set_width(bk_ui->Home_obj_6, 160);
    lv_obj_set_height(bk_ui->Home_obj_6, 160);
    lv_obj_remove_flag(bk_ui->Home_obj_6, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(bk_ui->Home_obj_6, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_obj_6, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(bk_ui->Home_obj_6, &latte_ARGB8888, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(bk_ui->Home_obj_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(bk_ui->Home_obj_6, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_obj_6, lv_color_hex(0xff5722), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_obj_6, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_obj_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_obj_6, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_obj_6, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Home_obj_6, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Home_obj_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Home_obj_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bk_ui->Home_obj_6, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_obj_6, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_obj_6, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_obj_6, lv_color_hex(0xffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_obj_6, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_obj_6, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_obj_6, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_obj_6, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_obj_6, false, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Home_obj_6, Home_obj_6_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Home_label_6 = lv_label_create(bk_ui->Home_obj_6);
    lv_label_set_text(bk_ui->Home_label_6, "拿铁");
    lv_label_set_long_mode(bk_ui->Home_label_6, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_x(bk_ui->Home_label_6, 26);
    lv_obj_set_y(bk_ui->Home_label_6, 128);
    lv_obj_set_width(bk_ui->Home_label_6, 104);
    lv_obj_set_height(bk_ui->Home_label_6, 25);
    lv_obj_set_style_bg_color(bk_ui->Home_label_6, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_label_6, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_label_6, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_label_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_label_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_label_6, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(bk_ui->Home_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(bk_ui->Home_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(bk_ui->Home_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(bk_ui->Home_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(bk_ui->Home_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(bk_ui->Home_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Home_label_6, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Home_label_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Home_label_6, &lv_font_ali_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Home_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Home_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Home_label_6, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Home_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Home_label_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Home_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Home_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Home_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->Home_button_1 = lv_btn_create(bk_ui->Home);
    bk_ui->Home_button_1_label = lv_label_create(bk_ui->Home_button_1);
    lv_label_set_text(bk_ui->Home_button_1_label, "开始制作");
    lv_label_set_long_mode(bk_ui->Home_button_1_label, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_align(bk_ui->Home_button_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_x(bk_ui->Home_button_1, 342);
    lv_obj_set_y(bk_ui->Home_button_1, 373);
    lv_obj_set_width(bk_ui->Home_button_1, 120);
    lv_obj_set_height(bk_ui->Home_button_1, 40);
    lv_obj_add_state(bk_ui->Home_button_1, LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(bk_ui->Home_button_1, lv_color_hex(0xFF5722), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_button_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_button_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_button_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_button_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_button_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_button_1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_button_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bk_ui->Home_button_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(bk_ui->Home_button_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(bk_ui->Home_button_1, &lv_font_ali_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(bk_ui->Home_button_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(bk_ui->Home_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Home_button_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Home_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Home_button_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Home_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Home_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Home_button_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Home_button_1, Home_button_1_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Home_image_1 = lv_image_create(bk_ui->Home);
    lv_image_set_src(bk_ui->Home_image_1, &setting_32x32_RGB565A8_NONE);
    lv_image_set_pivot(bk_ui->Home_image_1, 50, 50);
    lv_image_set_rotation(bk_ui->Home_image_1, 0);
    lv_obj_set_x(bk_ui->Home_image_1, 746);
    lv_obj_set_y(bk_ui->Home_image_1, 14);
    lv_obj_set_width(bk_ui->Home_image_1, 32);
    lv_obj_set_height(bk_ui->Home_image_1, 32);
    lv_obj_add_flag(bk_ui->Home_image_1, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_bg_color(bk_ui->Home_image_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_image_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_image_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_image_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_image_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_image_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Home_image_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Home_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Home_image_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Home_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Home_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Home_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(bk_ui->Home_image_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(bk_ui->Home_image_1, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(bk_ui->Home_image_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(bk_ui->Home_image_1, Home_image_1_event_cb, LV_EVENT_ALL, NULL);

    bk_ui->Home_image_2 = lv_image_create(bk_ui->Home);
    lv_image_set_pivot(bk_ui->Home_image_2, 50, 50);
    lv_image_set_rotation(bk_ui->Home_image_2, 0);
    lv_obj_set_x(bk_ui->Home_image_2, 94);
    lv_obj_set_y(bk_ui->Home_image_2, 355);
    lv_obj_set_width(bk_ui->Home_image_2, 100);
    lv_obj_set_height(bk_ui->Home_image_2, 100);
    lv_obj_set_style_bg_color(bk_ui->Home_image_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->Home_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->Home_image_2, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->Home_image_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->Home_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->Home_image_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->Home_image_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->Home_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->Home_image_2, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->Home_image_2, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->Home_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->Home_image_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->Home_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->Home_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->Home_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(bk_ui->Home_image_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(bk_ui->Home_image_2, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(bk_ui->Home_image_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_update_layout(bk_ui->Home);
}

/*
 * @brief: destroy page Home
 */
void destroy_page_Home(bk_lv_ui_t *bk_ui)
{
    if (bk_ui == NULL) {
        return;
    }
    
    if (bk_ui->Home != NULL) {
        lv_obj_del(bk_ui->Home);
        bk_ui->Home = NULL;
    }
}