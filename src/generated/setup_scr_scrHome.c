/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



int scrHome_digital_clockTime_min_value = 24;
int scrHome_digital_clockTime_hour_value = 12;
int scrHome_digital_clockTime_sec_value = 50;
void setup_scr_scrHome(lv_ui *ui)
{
    //Write codes scrHome
    ui->scrHome = lv_obj_create(NULL);
    lv_obj_set_size(ui->scrHome, 480, 272);
    lv_obj_set_scrollbar_mode(ui->scrHome, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrHome, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrHome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->scrHome, &_main_Screen_RGB565A8_480x272, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->scrHome, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->scrHome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_labelAirTemp
    ui->scrHome_labelAirTemp = lv_label_create(ui->scrHome);
    lv_obj_set_pos(ui->scrHome_labelAirTemp, 23, 64);
    lv_obj_set_size(ui->scrHome_labelAirTemp, 45, 41);
    lv_label_set_text(ui->scrHome_labelAirTemp, "26");
    lv_label_set_long_mode(ui->scrHome_labelAirTemp, LV_LABEL_LONG_WRAP);

    //Write style for scrHome_labelAirTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_labelAirTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_labelAirTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_labelAirTemp, lv_color_hex(0x2b3b9b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_labelAirTemp, &lv_font_montserratMedium_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_labelAirTemp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_labelAirTemp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_labelAirTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_labelAirTemp, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_labelAirTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_labelAirTemp, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_labelAirTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_labelAirTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_labelAirTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_labelAirTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_labelOvenTemp
    ui->scrHome_labelOvenTemp = lv_label_create(ui->scrHome);
    lv_obj_set_pos(ui->scrHome_labelOvenTemp, 12, 172);
    lv_obj_set_size(ui->scrHome_labelOvenTemp, 89, 42);
    lv_label_set_text(ui->scrHome_labelOvenTemp, "234");
    lv_label_set_long_mode(ui->scrHome_labelOvenTemp, LV_LABEL_LONG_WRAP);

    //Write style for scrHome_labelOvenTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_labelOvenTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_labelOvenTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_labelOvenTemp, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_labelOvenTemp, &lv_font_montserratMedium_45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_labelOvenTemp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_labelOvenTemp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_labelOvenTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_labelOvenTemp, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_labelOvenTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_labelOvenTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_labelOvenTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_labelOvenTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_labelOvenTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_labelOvenTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_imgLight
    ui->scrHome_imgLight = lv_image_create(ui->scrHome);
    lv_obj_set_pos(ui->scrHome_imgLight, 159, 70);
    lv_obj_set_size(ui->scrHome_imgLight, 165, 83);
    lv_obj_add_flag(ui->scrHome_imgLight, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrHome_imgLight, &_hood_menu_light_RGB565A8_165x83);
    lv_image_set_pivot(ui->scrHome_imgLight, 50,50);
    lv_image_set_rotation(ui->scrHome_imgLight, 0);

    //Write style for scrHome_imgLight, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrHome_imgLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrHome_imgLight, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_imgFan
    ui->scrHome_imgFan = lv_image_create(ui->scrHome);
    lv_obj_set_pos(ui->scrHome_imgFan, 97, 15);
    lv_obj_set_size(ui->scrHome_imgFan, 20, 20);
    lv_obj_add_flag(ui->scrHome_imgFan, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrHome_imgFan, &_aircon_menu_fan_1_RGB565A8_20x20);
    lv_image_set_pivot(ui->scrHome_imgFan, 10,10);
    lv_image_set_rotation(ui->scrHome_imgFan, 0);

    //Write style for scrHome_imgFan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrHome_imgFan, 119, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scrHome_imgFan, lv_color_hex(0x00a8ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrHome_imgFan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_labelFanSt
    ui->scrHome_labelFanSt = lv_label_create(ui->scrHome);
    lv_obj_set_pos(ui->scrHome_labelFanSt, 279, 19);
    lv_obj_set_size(ui->scrHome_labelFanSt, 26, 23);
    lv_label_set_text(ui->scrHome_labelFanSt, "Low");
    lv_label_set_long_mode(ui->scrHome_labelFanSt, LV_LABEL_LONG_WRAP);

    //Write style for scrHome_labelFanSt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_labelFanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_labelFanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_labelFanSt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_labelFanSt, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_labelFanSt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_labelFanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_labelFanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_labelFanSt, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_labelFanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_labelFanSt, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_labelFanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_labelFanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_labelFanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_labelFanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_labelLightSt
    ui->scrHome_labelLightSt = lv_label_create(ui->scrHome);
    lv_obj_set_pos(ui->scrHome_labelLightSt, 257, 19);
    lv_obj_set_size(ui->scrHome_labelLightSt, 26, 23);
    lv_label_set_text(ui->scrHome_labelLightSt, "On");
    lv_label_set_long_mode(ui->scrHome_labelLightSt, LV_LABEL_LONG_WRAP);

    //Write style for scrHome_labelLightSt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_labelLightSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_labelLightSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_labelLightSt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_labelLightSt, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_labelLightSt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_labelLightSt, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_labelLightSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_labelLightSt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_labelLightSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_labelLightSt, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_labelLightSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_labelLightSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_labelLightSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_labelLightSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_labelFanMode
    ui->scrHome_labelFanMode = lv_label_create(ui->scrHome);
    lv_obj_set_pos(ui->scrHome_labelFanMode, 106, 91);
    lv_obj_set_size(ui->scrHome_labelFanMode, 29, 20);
    lv_label_set_text(ui->scrHome_labelFanMode, "Low");
    lv_label_set_long_mode(ui->scrHome_labelFanMode, LV_LABEL_LONG_WRAP);

    //Write style for scrHome_labelFanMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_labelFanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_labelFanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_labelFanMode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_labelFanMode, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_labelFanMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_labelFanMode, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_labelFanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_labelFanMode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_labelFanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_labelFanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_labelFanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_labelFanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_labelFanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_labelFanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_btnOven
    ui->scrHome_btnOven = lv_button_create(ui->scrHome);
    lv_obj_set_pos(ui->scrHome_btnOven, 196, 167);
    lv_obj_set_size(ui->scrHome_btnOven, 89, 92);
    ui->scrHome_btnOven_label = lv_label_create(ui->scrHome_btnOven);
    lv_label_set_text(ui->scrHome_btnOven_label, "");
    lv_label_set_long_mode(ui->scrHome_btnOven_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrHome_btnOven_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrHome_btnOven, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrHome_btnOven_label, LV_PCT(100));

    //Write style for scrHome_btnOven, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrHome_btnOven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrHome_btnOven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_btnOven, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_btnOven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_btnOven, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_btnOven, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_btnOven, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_btnOven, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_btnHood
    ui->scrHome_btnHood = lv_button_create(ui->scrHome);
    lv_obj_set_pos(ui->scrHome_btnHood, 182, 4);
    lv_obj_set_size(ui->scrHome_btnHood, 121, 72);
    ui->scrHome_btnHood_label = lv_label_create(ui->scrHome_btnHood);
    lv_label_set_text(ui->scrHome_btnHood_label, "");
    lv_label_set_long_mode(ui->scrHome_btnHood_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrHome_btnHood_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrHome_btnHood, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrHome_btnHood_label, LV_PCT(100));

    //Write style for scrHome_btnHood, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrHome_btnHood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrHome_btnHood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_btnHood, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_btnHood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_btnHood, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_btnHood, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_btnHood, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_btnHood, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_btnAircon
    ui->scrHome_btnAircon = lv_button_create(ui->scrHome);
    lv_obj_set_pos(ui->scrHome_btnAircon, 23, 11);
    lv_obj_set_size(ui->scrHome_btnAircon, 112, 38);
    ui->scrHome_btnAircon_label = lv_label_create(ui->scrHome_btnAircon);
    lv_label_set_text(ui->scrHome_btnAircon_label, "");
    lv_label_set_long_mode(ui->scrHome_btnAircon_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrHome_btnAircon_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrHome_btnAircon, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrHome_btnAircon_label, LV_PCT(100));

    //Write style for scrHome_btnAircon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrHome_btnAircon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrHome_btnAircon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_btnAircon, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_btnAircon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_btnAircon, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_btnAircon, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_btnAircon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_btnAircon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_label_name
    ui->scrHome_label_name = lv_label_create(ui->scrHome);
    lv_obj_set_pos(ui->scrHome_label_name, 40, 124);
    lv_obj_set_size(ui->scrHome_label_name, 122, 16);
    lv_label_set_text(ui->scrHome_label_name, "Smart Appliance");
    lv_label_set_long_mode(ui->scrHome_label_name, LV_LABEL_LONG_WRAP);

    //Write style for scrHome_label_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_label_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_label_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_label_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_label_name, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_label_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_label_name, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_label_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_label_name, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_label_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_label_name, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_label_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_label_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_label_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_label_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_digital_clockTime
    static bool scrHome_digital_clockTime_timer_enabled = false;
    ui->scrHome_digital_clockTime = lv_label_create(ui->scrHome);
    lv_obj_set_pos(ui->scrHome_digital_clockTime, 362, 32);
    lv_obj_set_size(ui->scrHome_digital_clockTime, 92, 39);
    lv_label_set_text(ui->scrHome_digital_clockTime, "12:24");
    if (!scrHome_digital_clockTime_timer_enabled) {
        lv_timer_create(scrHome_digital_clockTime_timer, 1000, NULL);
        scrHome_digital_clockTime_timer_enabled = true;
    }

    //Write style for scrHome_digital_clockTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->scrHome_digital_clockTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_digital_clockTime, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_digital_clockTime, &lv_font_arial_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_digital_clockTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_digital_clockTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_digital_clockTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_digital_clockTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_digital_clockTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_digital_clockTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_digital_clockTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_digital_clockTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_digital_clockTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_img_logo
    ui->scrHome_img_logo = lv_image_create(ui->scrHome);
    lv_obj_set_pos(ui->scrHome_img_logo, 356, 203);
    lv_obj_set_size(ui->scrHome_img_logo, 98, 33);
    lv_obj_add_flag(ui->scrHome_img_logo, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrHome_img_logo, &_nxp_logo_RGB565A8_98x33);
    lv_image_set_pivot(ui->scrHome_img_logo, 50,50);
    lv_image_set_rotation(ui->scrHome_img_logo, 0);

    //Write style for scrHome_img_logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrHome_img_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrHome_img_logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scrHome.


    //Update current screen layout.
    lv_obj_update_layout(ui->scrHome);

    //Init events for screen.
    events_init_scrHome(ui);
}
