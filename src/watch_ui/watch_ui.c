#include "watch_ui.h"

#include <math.h>
#include <stdint.h>

#define WATCH_FACE_SIZE 240
#define WATCH_CENTER    (WATCH_FACE_SIZE / 2)

#ifndef M_PI
    #define M_PI 3.1415926f
#endif

typedef struct {
    lv_obj_t *screen;
    lv_obj_t *face;
    lv_obj_t *hour_hand;
    lv_obj_t *minute_hand;
    lv_obj_t *second_hand;
    lv_obj_t *time_label;
    lv_obj_t *day_label;
    lv_point_precise_t hour_points[2];
    lv_point_precise_t minute_points[2];
    lv_point_precise_t second_points[2];
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t day;
} watch_ui_t;

static watch_ui_t g_watch_ui = {
    .hour = 10,
    .minute = 10,
    .second = 30,
    .day = 29,
};

void init_watch_time(uint8_t hour, uint8_t minute, uint8_t second)
{
    g_watch_ui.hour = hour % 24;
    g_watch_ui.minute = minute % 60;
    g_watch_ui.second = second % 60;
}

void init_watch_day(uint8_t day)
{
    g_watch_ui.day = day < 1 ? 1 : (day > 31 ? 31 : day);

    if(g_watch_ui.day_label != NULL) {
        lv_label_set_text_fmt(g_watch_ui.day_label, "%u", (unsigned int)g_watch_ui.day);
    }
}

static void style_plain_obj(lv_obj_t *obj);
static void create_bezel(lv_obj_t *parent);
static void create_dial(lv_obj_t *parent);
static void create_markers(lv_obj_t *parent);
static void create_hour_numbers(lv_obj_t *parent);
static void create_minute_numbers(lv_obj_t *parent);
static void create_centered_label(lv_obj_t *parent, const char *text, int radius, int angle_deg,
                                  const lv_font_t *font, lv_color_t color, int width, int height);
static void create_branding(lv_obj_t *parent);
static void create_hands(lv_obj_t *parent);
static void update_hands(void);
static void timer_cb(lv_timer_t *timer);
static int polar_x(int radius, int angle_deg);
static int polar_y(int radius, int angle_deg);

void watch_ui_init(void)
{
    g_watch_ui.screen = lv_obj_create(NULL);
    lv_obj_remove_style_all(g_watch_ui.screen);
    lv_obj_set_size(g_watch_ui.screen, WATCH_SCREEN_WIDTH, WATCH_SCREEN_HEIGHT);
    lv_obj_set_style_bg_color(g_watch_ui.screen, lv_color_hex(0x050607), 0);
    lv_obj_set_style_bg_opa(g_watch_ui.screen, LV_OPA_COVER, 0);

    g_watch_ui.face = lv_obj_create(g_watch_ui.screen);
    style_plain_obj(g_watch_ui.face);
    lv_obj_set_size(g_watch_ui.face, WATCH_FACE_SIZE, WATCH_FACE_SIZE);
    lv_obj_align(g_watch_ui.face, LV_ALIGN_TOP_MID, 0, 40);
    lv_obj_set_style_bg_color(g_watch_ui.face, lv_color_hex(0x07110d), 0);
    lv_obj_set_style_radius(g_watch_ui.face, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(g_watch_ui.face, true, 0);

    create_bezel(g_watch_ui.face);
    create_dial(g_watch_ui.face);
    create_markers(g_watch_ui.face);
    create_minute_numbers(g_watch_ui.face);
    create_hour_numbers(g_watch_ui.face);
    create_branding(g_watch_ui.face);
    create_hands(g_watch_ui.face);
    update_hands();

    lv_timer_create(timer_cb, 1000, NULL);
    lv_screen_load(g_watch_ui.screen);
}

static void style_plain_obj(lv_obj_t *obj)
{
    lv_obj_remove_style_all(obj);
    lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);
    lv_obj_set_style_border_width(obj, 0, 0);
    lv_obj_set_style_pad_all(obj, 0, 0);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
}

static void create_bezel(lv_obj_t *parent)
{
    lv_obj_t *outer = lv_obj_create(parent);
    style_plain_obj(outer);
    lv_obj_set_size(outer, 236, 236);
    lv_obj_center(outer);
    lv_obj_set_style_radius(outer, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(outer, lv_color_hex(0x003b26), 0);
    lv_obj_set_style_border_width(outer, 4, 0);
    lv_obj_set_style_border_color(outer, lv_color_hex(0xd2c17a), 0);

    lv_obj_t *inner = lv_obj_create(parent);
    style_plain_obj(inner);
    lv_obj_set_size(inner, 178, 178);
    lv_obj_center(inner);
    lv_obj_set_style_radius(inner, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(inner, lv_color_hex(0x030504), 0);
    lv_obj_set_style_border_width(inner, 2, 0);
    lv_obj_set_style_border_color(inner, lv_color_hex(0x173f2c), 0);
}

static void create_dial(lv_obj_t *parent)
{
    lv_obj_t *dial = lv_obj_create(parent);
    style_plain_obj(dial);
    lv_obj_set_size(dial, 188, 188);
    lv_obj_center(dial);
    lv_obj_set_style_radius(dial, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(dial, lv_color_hex(0x050505), 0);
    lv_obj_set_style_border_width(dial, 1, 0);
    lv_obj_set_style_border_color(dial, lv_color_hex(0x1e2d24), 0);
}

static void create_markers(lv_obj_t *parent)
{
    for(int minute = 0; minute < 60; minute++) {
        int angle = minute * 6 - 90;
        lv_obj_t *tick = lv_obj_create(parent);
        style_plain_obj(tick);
        lv_obj_set_size(tick, 2, 2);
        lv_obj_set_pos(tick, polar_x(89, angle) - 1, polar_y(89, angle) - 1);
        lv_obj_set_style_bg_color(tick, lv_color_hex(0xd6d6c8), 0);
        lv_obj_set_style_radius(tick, LV_RADIUS_CIRCLE, 0);
    }
}

static void create_hour_numbers(lv_obj_t *parent)
{
    static const char *hour_text[] = {
        "12", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"
    };

    for(int hour = 1; hour <= 12; hour++) {
        int angle = hour * 30 - 90;
        int text_index = hour % 12;
        create_centered_label(parent, hour_text[text_index], 76, angle,
                              &lv_font_montserrat_12, lv_color_hex(0xf4f1df), 22, 14);
    }
}

static void create_minute_numbers(lv_obj_t *parent)
{
    static const char *minute_text[] = {
        "5", "10", "15", "20", "25", "30", "35", "40", "45", "50", "55", "60"
    };

    for(int i = 0; i < 12; i++) {
        int minute = (i + 1) * 5;
        int angle = minute * 6 - 90;
        create_centered_label(parent, minute_text[i], 103, angle,
                              &lv_font_montserrat_12, lv_color_hex(0xd2c17a), 22, 14);
    }
}

static void create_centered_label(lv_obj_t *parent, const char *text, int radius, int angle_deg,
                                  const lv_font_t *font, lv_color_t color, int width, int height)
{
    lv_obj_t *label = lv_label_create(parent);
    lv_label_set_text(label, text);
    lv_label_set_long_mode(label, LV_LABEL_LONG_CLIP);
    lv_obj_set_size(label, width, height);
    lv_obj_set_pos(label, polar_x(radius, angle_deg) - width / 2, polar_y(radius, angle_deg) - height / 2);
    lv_obj_set_style_text_color(label, color, 0);
    lv_obj_set_style_text_font(label, font, 0);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_clear_flag(label, LV_OBJ_FLAG_SCROLLABLE);
}

static void create_branding(lv_obj_t *parent)
{
    lv_obj_t *title = lv_label_create(parent);
    lv_label_set_text(title, "SUBMARINER");
    lv_obj_set_style_text_color(title, lv_color_hex(0xf4f1df), 0);
    lv_obj_set_style_text_font(title, &lv_font_montserrat_12, 0);
    lv_obj_align(title, LV_ALIGN_CENTER, 0, -24);

    lv_obj_t *depth = lv_label_create(parent);
    lv_label_set_text(depth, "Fake Rolex");
    lv_obj_set_style_text_color(depth, lv_color_hex(0xd2c17a), 0);
    lv_obj_set_style_text_font(depth, &lv_font_montserrat_12, 0);
    lv_obj_align(depth, LV_ALIGN_CENTER, 0, 31);

    lv_obj_t *date = lv_obj_create(parent);
    style_plain_obj(date);
    lv_obj_set_size(date, 27, 20);
    lv_obj_align(date, LV_ALIGN_RIGHT_MID, -56, 0);
    lv_obj_set_style_bg_color(date, lv_color_hex(0xf6f2dd), 0);
    lv_obj_set_style_radius(date, 3, 0);

    g_watch_ui.day_label = lv_label_create(date);
    lv_label_set_text_fmt(g_watch_ui.day_label, "%u", (unsigned int)g_watch_ui.day);
    lv_obj_set_style_text_color(g_watch_ui.day_label, lv_color_hex(0x101010), 0);
    lv_obj_set_style_text_font(g_watch_ui.day_label, &lv_font_montserrat_14, 0);
    lv_obj_center(g_watch_ui.day_label);

    g_watch_ui.time_label = NULL;
}

static void create_hands(lv_obj_t *parent)
{
    g_watch_ui.hour_hand = lv_line_create(parent);
    lv_obj_remove_style_all(g_watch_ui.hour_hand);
    lv_obj_set_size(g_watch_ui.hour_hand, WATCH_FACE_SIZE, WATCH_FACE_SIZE);
    lv_obj_set_style_line_color(g_watch_ui.hour_hand, lv_color_hex(0xf4f1df), 0);
    lv_obj_set_style_line_width(g_watch_ui.hour_hand, 7, 0);
    lv_obj_set_style_line_rounded(g_watch_ui.hour_hand, true, 0);

    g_watch_ui.minute_hand = lv_line_create(parent);
    lv_obj_remove_style_all(g_watch_ui.minute_hand);
    lv_obj_set_size(g_watch_ui.minute_hand, WATCH_FACE_SIZE, WATCH_FACE_SIZE);
    lv_obj_set_style_line_color(g_watch_ui.minute_hand, lv_color_hex(0xf4f1df), 0);
    lv_obj_set_style_line_width(g_watch_ui.minute_hand, 5, 0);
    lv_obj_set_style_line_rounded(g_watch_ui.minute_hand, true, 0);

    g_watch_ui.second_hand = lv_line_create(parent);
    lv_obj_remove_style_all(g_watch_ui.second_hand);
    lv_obj_set_size(g_watch_ui.second_hand, WATCH_FACE_SIZE, WATCH_FACE_SIZE);
    lv_obj_set_style_line_color(g_watch_ui.second_hand, lv_color_hex(0xd42424), 0);
    lv_obj_set_style_line_width(g_watch_ui.second_hand, 2, 0);
    lv_obj_set_style_line_rounded(g_watch_ui.second_hand, true, 0);

    lv_obj_t *cap = lv_obj_create(parent);
    style_plain_obj(cap);
    lv_obj_set_size(cap, 14, 14);
    lv_obj_center(cap);
    lv_obj_set_style_radius(cap, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(cap, lv_color_hex(0xd2c17a), 0);
    lv_obj_set_style_border_width(cap, 3, 0);
    lv_obj_set_style_border_color(cap, lv_color_hex(0xf4f1df), 0);
}

static void update_hands(void)
{
    int second_angle = g_watch_ui.second * 6 - 90;
    int minute_angle = g_watch_ui.minute * 6 + g_watch_ui.second / 10 - 90;
    int hour_angle = (g_watch_ui.hour % 12) * 30 + g_watch_ui.minute / 2 - 90;

    g_watch_ui.hour_points[0].x = WATCH_CENTER;
    g_watch_ui.hour_points[0].y = WATCH_CENTER;
    g_watch_ui.hour_points[1].x = polar_x(50, hour_angle);
    g_watch_ui.hour_points[1].y = polar_y(50, hour_angle);
    lv_line_set_points(g_watch_ui.hour_hand, g_watch_ui.hour_points, 2);

    g_watch_ui.minute_points[0].x = WATCH_CENTER;
    g_watch_ui.minute_points[0].y = WATCH_CENTER;
    g_watch_ui.minute_points[1].x = polar_x(70, minute_angle);
    g_watch_ui.minute_points[1].y = polar_y(70, minute_angle);
    lv_line_set_points(g_watch_ui.minute_hand, g_watch_ui.minute_points, 2);

    g_watch_ui.second_points[0].x = polar_x(18, second_angle + 180);
    g_watch_ui.second_points[0].y = polar_y(18, second_angle + 180);
    g_watch_ui.second_points[1].x = polar_x(82, second_angle);
    g_watch_ui.second_points[1].y = polar_y(82, second_angle);
    lv_line_set_points(g_watch_ui.second_hand, g_watch_ui.second_points, 2);

    if(g_watch_ui.time_label != NULL) {
        lv_label_set_text_fmt(g_watch_ui.time_label, "%02u:%02u:%02u",
                              (unsigned int)g_watch_ui.hour,
                              (unsigned int)g_watch_ui.minute,
                              (unsigned int)g_watch_ui.second);
    }
}

static void timer_cb(lv_timer_t *timer)
{
    (void)timer;

    g_watch_ui.second++;
    if(g_watch_ui.second >= 60) {
        g_watch_ui.second = 0;
        g_watch_ui.minute++;
    }

    if(g_watch_ui.minute >= 60) {
        g_watch_ui.minute = 0;
        g_watch_ui.hour = (g_watch_ui.hour + 1) % 24;
    }

    update_hands();
}

static int polar_x(int radius, int angle_deg)
{
    double angle_rad = (double)angle_deg * M_PI / 180.0;
    return WATCH_CENTER + (int)lrint(cos(angle_rad) * radius);
}

static int polar_y(int radius, int angle_deg)
{
    double angle_rad = (double)angle_deg * M_PI / 180.0;
    return WATCH_CENTER + (int)lrint(sin(angle_rad) * radius);
}
