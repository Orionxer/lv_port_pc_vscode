#include "watch_ui.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846f
#endif

#define PI_F     ((float)M_PI)
#define TWO_PI_F (2.0f * PI_F)

#define COLOR_HOUR lv_color_make(0xff, 0xff, 0xff)
#define COLOR_MIN  lv_color_make(0xb4, 0xff, 0x29)
#define COLOR_SEC  lv_color_make(0xff, 0x5e, 0x00)
#define COLOR_BG   lv_color_make(0x03, 0x03, 0x03)

#define ANIM_SPEED 1.5f

typedef struct {
    lv_obj_t *screen;
    lv_obj_t *watch_obj;
    lv_timer_t *anim_timer;
    bool locked;
    float t_raw;
    float t;
    uint32_t last_ms;
    uint32_t sec_tick_ref;
    int last_tm_sec;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t day;
} watch_ui_t;

static watch_ui_t g_watch_ui = {
    .last_tm_sec = -1,
    .hour = 10,
    .minute = 10,
    .second = 30,
    .day = 29,
};

static void draw_watch_cb(lv_event_t *e);
static void on_click_cb(lv_event_t *e);
static void anim_timer_cb(lv_timer_t *timer);
static void draw_dial_layer(lv_layer_t *layer,
                            float wcx,
                            float wcy,
                            float radius,
                            float max_val,
                            float value,
                            lv_color_t color,
                            float t,
                            bool is_hour,
                            float label_radius,
                            int32_t hand_w);
static void draw_line_f(lv_layer_t *layer,
                        float x1,
                        float y1,
                        float x2,
                        float y2,
                        lv_color_t color,
                        int32_t width,
                        lv_opa_t opa);
static void draw_dot_f(lv_layer_t *layer, float cx, float cy, float r, lv_color_t color, lv_opa_t opa);
static float draw_label_left(lv_layer_t *layer,
                             float tx,
                             float ty_mid,
                             const char *text,
                             lv_color_t color,
                             const lv_font_t *font,
                             lv_opa_t opa);
static void draw_label_center(lv_layer_t *layer,
                              float tx,
                              float ty,
                              const char *text,
                              lv_color_t color,
                              const lv_font_t *font,
                              lv_opa_t opa,
                              int32_t area_w);
static lv_opa_t spotlight_opa(float global_a, float t);
static float ease_in_out_cubic(float x);

void init_watch_time(uint8_t hour, uint8_t minute, uint8_t second)
{
    g_watch_ui.hour = hour % 24;
    g_watch_ui.minute = minute % 60;
    g_watch_ui.second = second % 60;
}

void init_watch_day(uint8_t day)
{
    g_watch_ui.day = day < 1 ? 1 : (day > 31 ? 31 : day);
}

void watch_ui_init(void)
{
    g_watch_ui.screen = lv_obj_create(NULL);
    lv_obj_remove_style_all(g_watch_ui.screen);
    lv_obj_set_size(g_watch_ui.screen, WATCH_SCREEN_WIDTH, WATCH_SCREEN_HEIGHT);
    lv_obj_set_style_bg_color(g_watch_ui.screen, COLOR_BG, 0);
    lv_obj_set_style_bg_opa(g_watch_ui.screen, LV_OPA_COVER, 0);

    g_watch_ui.watch_obj = lv_obj_create(g_watch_ui.screen);
    lv_obj_remove_style_all(g_watch_ui.watch_obj);
    lv_obj_set_size(g_watch_ui.watch_obj, LV_PCT(100), LV_PCT(100));
    lv_obj_set_pos(g_watch_ui.watch_obj, 0, 0);
    lv_obj_set_style_bg_opa(g_watch_ui.watch_obj, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(g_watch_ui.watch_obj, 0, 0);
    lv_obj_set_style_pad_all(g_watch_ui.watch_obj, 0, 0);
    lv_obj_clear_flag(g_watch_ui.watch_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(g_watch_ui.watch_obj, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(g_watch_ui.watch_obj, draw_watch_cb, LV_EVENT_DRAW_MAIN, NULL);
    lv_obj_add_event_cb(g_watch_ui.watch_obj, on_click_cb, LV_EVENT_CLICKED, NULL);

    g_watch_ui.last_ms = lv_tick_get();
    g_watch_ui.sec_tick_ref = g_watch_ui.last_ms;
    g_watch_ui.anim_timer = lv_timer_create(anim_timer_cb, 16, NULL);

    lv_screen_load(g_watch_ui.screen);
}

static void draw_watch_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target_obj(e);
    lv_layer_t *layer = lv_event_get_layer(e);
    if(layer == NULL) {
        return;
    }

    lv_area_t obj_area;
    lv_obj_get_coords(obj, &obj_area);

    float scr_cx = ((float)obj_area.x1 + (float)obj_area.x2) / 2.0f;
    float scr_cy = ((float)obj_area.y1 + (float)obj_area.y2) / 2.0f;
    float w = (float)lv_area_get_width(&obj_area);
    float h = (float)lv_area_get_height(&obj_area);
    float min_dim = w < h ? w : h;
    float anim_t = g_watch_ui.t;

    float radius_h = min_dim * 0.192f;
    float radius_m = min_dim * 0.336f;
    float radius_s = min_dim * 0.48f;
    float major_tick_l = 10.0f;
    float label_gap = 14.0f;
    float cam_scale = 1.0f + 0.45f * anim_t;
    float cam_x_w = -(radius_m * 1.3f) * anim_t;
    float wcx = scr_cx + cam_scale * cam_x_w;
    float wcy = scr_cy;

    radius_h *= cam_scale;
    radius_m *= cam_scale;
    radius_s *= cam_scale;
    major_tick_l *= cam_scale;
    label_gap *= cam_scale;

    time_t now_t = time(NULL);
    struct tm *now = localtime(&now_t);
    int tm_hour = now != NULL ? now->tm_hour : (int)g_watch_ui.hour;
    int tm_min = now != NULL ? now->tm_min : (int)g_watch_ui.minute;
    int tm_sec = now != NULL ? now->tm_sec : (int)g_watch_ui.second;

    if(tm_sec != g_watch_ui.last_tm_sec) {
        g_watch_ui.sec_tick_ref = lv_tick_get();
        g_watch_ui.last_tm_sec = tm_sec;
    }

    float ms_frac = (float)(lv_tick_get() - g_watch_ui.sec_tick_ref) / 1000.0f;
    if(ms_frac < 0.0f) {
        ms_frac = 0.0f;
    }
    if(ms_frac > 1.0f) {
        ms_frac = 1.0f;
    }

    float value_sec = (float)tm_sec + ms_frac;
    float value_min = (float)tm_min + value_sec / 60.0f;
    float value_hour = (float)(tm_hour % 12) + value_min / 60.0f;

    draw_dial_layer(layer,
                    wcx,
                    wcy,
                    radius_h,
                    12.0f,
                    value_hour,
                    COLOR_HOUR,
                    anim_t,
                    true,
                    radius_h - major_tick_l - label_gap,
                    6);
    draw_dial_layer(layer,
                    wcx,
                    wcy,
                    radius_m,
                    60.0f,
                    value_min,
                    COLOR_MIN,
                    anim_t,
                    false,
                    (radius_h + radius_m - major_tick_l) / 2.0f,
                    4);
    draw_dial_layer(layer,
                    wcx,
                    wcy,
                    radius_s,
                    60.0f,
                    value_sec,
                    COLOR_SEC,
                    anim_t,
                    false,
                    (radius_m + radius_s - major_tick_l) / 2.0f,
                    2);

    if(anim_t > 0.01f) {
        lv_opa_t hud_opa = (lv_opa_t)(anim_t * anim_t * (float)LV_OPA_COVER);
        lv_color_t white = lv_color_white();
        float hud_x = wcx + radius_h - 20.0f * cam_scale;
        float hud_w = radius_s - radius_h + 40.0f * cam_scale;
        float hud_h = 36.0f * cam_scale;
        float hud_y = wcy - hud_h / 2.0f;
        float corner = 8.0f * cam_scale;

        draw_line_f(layer, hud_x + corner, hud_y, hud_x, hud_y, white, 1, hud_opa);
        draw_line_f(layer, hud_x, hud_y, hud_x, hud_y + corner, white, 1, hud_opa);
        draw_line_f(layer, hud_x + corner, hud_y + hud_h, hud_x, hud_y + hud_h, white, 1, hud_opa);
        draw_line_f(layer, hud_x, hud_y + hud_h, hud_x, hud_y + hud_h - corner, white, 1, hud_opa);
        draw_line_f(layer, hud_x + hud_w - corner, hud_y, hud_x + hud_w, hud_y, white, 1, hud_opa);
        draw_line_f(layer, hud_x + hud_w, hud_y, hud_x + hud_w, hud_y + corner, white, 1, hud_opa);
        draw_line_f(layer, hud_x + hud_w - corner, hud_y + hud_h, hud_x + hud_w, hud_y + hud_h, white, 1, hud_opa);
        draw_line_f(layer, hud_x + hud_w, hud_y + hud_h, hud_x + hud_w, hud_y + hud_h - corner, white, 1,
                    hud_opa);

        float text_start_x = hud_x + hud_w + 20.0f * cam_scale;
        float text_end_x = text_start_x + 130.0f * cam_scale;
        float laser_left = wcx - radius_h * 0.5f;

        for(int i = 0; i < 14; i++) {
            float fa = (float)i / 14.0f;
            float fb = (float)(i + 1) / 14.0f;
            float fc = (fa + fb) * 0.5f;
            float bright;

            if(fc < 0.3f) {
                bright = fc / 0.3f * 0.8f;
            }
            else if(fc < 0.8f) {
                bright = 0.8f;
            }
            else {
                bright = (1.0f - fc) / 0.2f * 0.8f;
            }

            lv_opa_t line_opa = (lv_opa_t)(bright * anim_t * (float)LV_OPA_COVER);
            draw_line_f(layer,
                        laser_left + fa * (text_end_x - laser_left),
                        wcy,
                        laser_left + fb * (text_end_x - laser_left),
                        wcy,
                        white,
                        1,
                        line_opa);
        }

        const lv_font_t *big_font = &lv_font_montserrat_28;
        float ty_mid = wcy - (float)big_font->line_height / 2.0f - 2.0f;
        char str_h[4];
        char str_m[4];
        char str_s[4];
        snprintf(str_h, sizeof(str_h), "%02d", tm_hour);
        snprintf(str_m, sizeof(str_m), "%02d", tm_min);
        snprintf(str_s, sizeof(str_s), "%02d", tm_sec);

        float cur_x = text_start_x;
        cur_x = draw_label_left(layer, cur_x, ty_mid, str_h, COLOR_HOUR, big_font, hud_opa) + 4.0f;
        cur_x = draw_label_left(layer, cur_x, ty_mid, ":", white, big_font, (lv_opa_t)(0.45f * LV_OPA_COVER)) + 4.0f;
        cur_x = draw_label_left(layer, cur_x, ty_mid, str_m, COLOR_MIN, big_font, hud_opa) + 4.0f;
        cur_x = draw_label_left(layer, cur_x, ty_mid, ":", white, big_font, (lv_opa_t)(0.45f * LV_OPA_COVER)) + 4.0f;
        draw_label_left(layer, cur_x, ty_mid, str_s, COLOR_SEC, big_font, hud_opa);
    }

    draw_dot_f(layer, wcx, wcy, 5.0f, COLOR_SEC, LV_OPA_COVER);
    draw_dot_f(layer, wcx, wcy, 2.0f, lv_color_black(), LV_OPA_COVER);
}

static void draw_dial_layer(lv_layer_t *layer,
                            float wcx,
                            float wcy,
                            float radius,
                            float max_val,
                            float value,
                            lv_color_t color,
                            float t,
                            bool is_hour,
                            float label_radius,
                            int32_t hand_w)
{
    float native_value_ang = value / max_val * TWO_PI_F - PI_F / 2.0f;
    float dial_rot = -native_value_ang * t;
    float hand_ang = native_value_ang * (1.0f - t);

    for(int i = 0; i < 60; i++) {
        bool is_major = (i % 5) == 0;
        float native_a = (float)i / 60.0f * TWO_PI_F - PI_F / 2.0f;
        float global_a = native_a + dial_rot;
        float tick_l = is_major ? 10.0f : 4.0f;
        int32_t tick_w = is_major ? 2 : 1;
        lv_opa_t tick_opa = spotlight_opa(global_a, t);

        draw_line_f(layer,
                    wcx + radius * cosf(global_a),
                    wcy + radius * sinf(global_a),
                    wcx + (radius - tick_l) * cosf(global_a),
                    wcy + (radius - tick_l) * sinf(global_a),
                    color,
                    tick_w,
                    tick_opa);

        if(is_major) {
            float tx = wcx + label_radius * cosf(global_a);
            float ty = wcy + label_radius * sinf(global_a);
            char buf[8];

            if(is_hour) {
                int val = i / 5;
                snprintf(buf, sizeof(buf), "%d", val == 0 ? 12 : val);
            }
            else {
                snprintf(buf, sizeof(buf), "%02d", i);
            }

            draw_label_center(layer,
                              tx,
                              ty,
                              buf,
                              color,
                              is_hour ? &lv_font_montserrat_16 : &lv_font_montserrat_14,
                              tick_opa,
                              is_hour ? 24 : 22);
        }
    }

    draw_line_f(layer,
                wcx,
                wcy,
                wcx + radius * cosf(hand_ang),
                wcy + radius * sinf(hand_ang),
                color,
                hand_w,
                LV_OPA_COVER);
}

static void draw_line_f(lv_layer_t *layer,
                        float x1,
                        float y1,
                        float x2,
                        float y2,
                        lv_color_t color,
                        int32_t width,
                        lv_opa_t opa)
{
    if(opa < 2) {
        return;
    }

    lv_draw_line_dsc_t dsc;
    lv_draw_line_dsc_init(&dsc);
    dsc.base.layer = layer;
    dsc.color = color;
    dsc.width = width;
    dsc.round_start = 1;
    dsc.round_end = 1;
    dsc.opa = opa;
    dsc.p1.x = roundf(x1);
    dsc.p1.y = roundf(y1);
    dsc.p2.x = roundf(x2);
    dsc.p2.y = roundf(y2);
    lv_draw_line(layer, &dsc);
}

static void draw_dot_f(lv_layer_t *layer, float cx, float cy, float r, lv_color_t color, lv_opa_t opa)
{
    if(opa < 2) {
        return;
    }

    int32_t ir = (int32_t)roundf(r);
    lv_area_t area = {
        .x1 = (int32_t)roundf(cx) - ir,
        .y1 = (int32_t)roundf(cy) - ir,
        .x2 = (int32_t)roundf(cx) + ir,
        .y2 = (int32_t)roundf(cy) + ir,
    };
    lv_draw_rect_dsc_t dsc;
    lv_draw_rect_dsc_init(&dsc);
    dsc.base.layer = layer;
    dsc.bg_color = color;
    dsc.bg_opa = opa;
    dsc.radius = LV_RADIUS_CIRCLE;
    dsc.border_width = 0;
    lv_draw_rect(layer, &dsc, &area);
}

static float draw_label_left(lv_layer_t *layer,
                             float tx,
                             float ty_mid,
                             const char *text,
                             lv_color_t color,
                             const lv_font_t *font,
                             lv_opa_t opa)
{
    if(opa < 2) {
        return tx;
    }

    int32_t tw = lv_text_get_width(text, (uint32_t)strlen(text), font, 0);
    int32_t th = font->line_height;
    lv_area_t area = {
        .x1 = (int32_t)roundf(tx),
        .y1 = (int32_t)roundf(ty_mid - (float)th / 2.0f),
        .x2 = (int32_t)roundf(tx + (float)tw + 2.0f),
        .y2 = (int32_t)roundf(ty_mid + (float)th / 2.0f),
    };
    lv_draw_label_dsc_t dsc;
    lv_draw_label_dsc_init(&dsc);
    dsc.base.layer = layer;
    dsc.text = text;
    dsc.text_length = (uint32_t)strlen(text);
    dsc.text_local = true;
    dsc.color = color;
    dsc.font = font;
    dsc.align = LV_TEXT_ALIGN_LEFT;
    dsc.opa = opa;
    lv_draw_label(layer, &dsc, &area);

    return tx + (float)tw;
}

static void draw_label_center(lv_layer_t *layer,
                              float tx,
                              float ty,
                              const char *text,
                              lv_color_t color,
                              const lv_font_t *font,
                              lv_opa_t opa,
                              int32_t area_w)
{
    if(opa < 2) {
        return;
    }

    int32_t th = font->line_height;
    lv_area_t area = {
        .x1 = (int32_t)roundf(tx - (float)area_w / 2.0f),
        .y1 = (int32_t)roundf(ty - (float)th / 2.0f),
        .x2 = (int32_t)roundf(tx + (float)area_w / 2.0f),
        .y2 = (int32_t)roundf(ty + (float)th / 2.0f),
    };
    lv_draw_label_dsc_t dsc;
    lv_draw_label_dsc_init(&dsc);
    dsc.base.layer = layer;
    dsc.text = text;
    dsc.text_length = (uint32_t)strlen(text);
    dsc.text_local = true;
    dsc.color = color;
    dsc.font = font;
    dsc.align = LV_TEXT_ALIGN_CENTER;
    dsc.opa = opa;
    lv_draw_label(layer, &dsc, &area);
}

static lv_opa_t spotlight_opa(float global_a, float t)
{
    if(t < 0.01f) {
        return LV_OPA_COVER;
    }

    float norm_a = fmodf(global_a, TWO_PI_F);
    if(norm_a < 0.0f) {
        norm_a += TWO_PI_F;
    }
    if(norm_a > PI_F) {
        norm_a = TWO_PI_F - norm_a;
    }

    float falloff = fmaxf(0.0f, 1.0f - norm_a / (PI_F / 3.0f));
    float focus_opa = (1.0f - t) + (0.15f + 0.85f * falloff) * t;
    return (lv_opa_t)(focus_opa * (float)LV_OPA_COVER);
}

static float ease_in_out_cubic(float x)
{
    if(x < 0.5f) {
        return 4.0f * x * x * x;
    }

    float f = -2.0f * x + 2.0f;
    return 1.0f - f * f * f / 2.0f;
}

static void anim_timer_cb(lv_timer_t *timer)
{
    (void)timer;

    uint32_t now_ms = lv_tick_get();
    uint32_t dt_raw = now_ms - g_watch_ui.last_ms;
    g_watch_ui.last_ms = now_ms;

    float dt_s = (float)dt_raw / 1000.0f;
    if(dt_s > 0.05f) {
        dt_s = 0.05f;
    }

    float target = g_watch_ui.locked ? 1.0f : 0.0f;
    if(target > g_watch_ui.t_raw) {
        g_watch_ui.t_raw += ANIM_SPEED * dt_s;
    }
    else {
        g_watch_ui.t_raw -= ANIM_SPEED * dt_s;
    }

    if(g_watch_ui.t_raw > 1.0f) {
        g_watch_ui.t_raw = 1.0f;
    }
    if(g_watch_ui.t_raw < 0.0f) {
        g_watch_ui.t_raw = 0.0f;
    }

    g_watch_ui.t = ease_in_out_cubic(g_watch_ui.t_raw);

    if(g_watch_ui.watch_obj != NULL) {
        lv_obj_invalidate(g_watch_ui.watch_obj);
    }
}

static void on_click_cb(lv_event_t *e)
{
    (void)e;
    g_watch_ui.locked = !g_watch_ui.locked;
}
