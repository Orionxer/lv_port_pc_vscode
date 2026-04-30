#include "player_ui.h"
#include "player_audio.h"

#include <stdint.h>

#define INITIAL_PROGRESS_SEC 1
#define INITIAL_VOLUME 62
#define SONG_COUNT 5

typedef struct {
    const char *title;
    const char *artist;
    const char *pcm_path;
} song_t;

static const song_t g_songs[SONG_COUNT] = {
    { "Life In The Fast Lane", "Eagles", "music/output/Eagles_Life_In_The_Fast_Lane.pcm" },
    { "Hotel California Solo", "Eagles", "music/output/Hotel_California_Guitar_Solo.pcm" },
    { "Don't Look Back In Anger", "Oasis", "music/output/Oasis_Dont_Look_Back_In_Anger.pcm" },
    { "The Great Gig In The Sky", "Pink Floyd", "music/output/Pink_Floyd_The_Great_Gig_In_The_Sky.pcm" },
    { "The Only Way I Can Love You", "Suede", "music/output/Suede_The_Only_Way_I_Can_Love_You.pcm" },
};

typedef struct {
    lv_obj_t *screen;
    lv_obj_t *song_list;
    lv_obj_t *song_buttons[SONG_COUNT];
    lv_obj_t *title_label;
    lv_obj_t *artist_label;
    lv_obj_t *progress_slider;
    lv_obj_t *elapsed_label;
    lv_obj_t *remain_label;
    lv_obj_t *play_label;
    lv_obj_t *volume_overlay;
    lv_obj_t *volume_slider;
    lv_obj_t *volume_label;
    lv_obj_t *volume_icon;
    lv_obj_t *volume_icon_label;
    lv_timer_t *progress_timer;
    uint16_t progress_sec;
    uint8_t current_song;
    uint8_t volume;
    bool playing;
    bool seeking;
} player_ui_t;

static player_ui_t g_player_ui = {
    .progress_sec = INITIAL_PROGRESS_SEC,
    .volume = INITIAL_VOLUME,
    .playing = true,
};

static void style_clear_obj(lv_obj_t *obj);
static void style_text(lv_obj_t *label, const lv_font_t *font, lv_color_t color, lv_text_align_t align);
static lv_obj_t *create_icon_button(lv_obj_t *parent, const char *symbol, int32_t size);
static void style_slider(lv_obj_t *slider, int32_t knob_size);
static void create_left_panel(lv_obj_t *parent);
static void create_player_panel(lv_obj_t *parent);
static void create_volume_popup(void);
static void close_volume_popup(void);
static void update_song_view(void);
static void update_song_selection(void);
static void update_progress_view(uint16_t progress_sec, bool update_slider);
static void load_current_song(bool play);
static void update_volume_label(void);
static void update_volume_icon(void);
static void progress_timer_cb(lv_timer_t *timer);
static void song_event_cb(lv_event_t *event);
static void progress_slider_event_cb(lv_event_t *event);
static void play_event_cb(lv_event_t *event);
static void prev_event_cb(lv_event_t *event);
static void next_event_cb(lv_event_t *event);
static void volume_button_event_cb(lv_event_t *event);
static void volume_overlay_event_cb(lv_event_t *event);
static void volume_slider_event_cb(lv_event_t *event);

void player_ui_init(void)
{
    g_player_ui.screen = lv_obj_create(NULL);
    lv_obj_remove_style_all(g_player_ui.screen);
    lv_obj_set_size(g_player_ui.screen, PLAYER_SCREEN_WIDTH, PLAYER_SCREEN_HEIGHT);
    lv_obj_set_style_bg_color(g_player_ui.screen, lv_color_hex(0x08090d), 0);
    lv_obj_set_style_bg_opa(g_player_ui.screen, LV_OPA_COVER, 0);
    lv_obj_clear_flag(g_player_ui.screen, LV_OBJ_FLAG_SCROLLABLE);

    create_left_panel(g_player_ui.screen);
    create_player_panel(g_player_ui.screen);
    player_audio_init();
    player_audio_set_volume(g_player_ui.volume);
    load_current_song(g_player_ui.playing);

    g_player_ui.progress_timer = lv_timer_create(progress_timer_cb, 1000, NULL);
    lv_screen_load(g_player_ui.screen);
}

static void style_clear_obj(lv_obj_t *obj)
{
    lv_obj_remove_style_all(obj);
    lv_obj_set_style_bg_opa(obj, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(obj, 0, 0);
    lv_obj_set_style_pad_all(obj, 0, 0);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
}

static void style_text(lv_obj_t *label, const lv_font_t *font, lv_color_t color, lv_text_align_t align)
{
    lv_obj_set_style_text_font(label, font, 0);
    lv_obj_set_style_text_color(label, color, 0);
    lv_obj_set_style_text_align(label, align, 0);
    lv_obj_set_style_text_letter_space(label, 0, 0);
    lv_obj_clear_flag(label, LV_OBJ_FLAG_SCROLLABLE);
}

static lv_obj_t *create_icon_button(lv_obj_t *parent, const char *symbol, int32_t size)
{
    lv_obj_t *button = lv_button_create(parent);
    lv_obj_remove_style_all(button);
    lv_obj_set_size(button, size, size);
    lv_obj_set_style_radius(button, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(button, lv_color_hex(0xf6f6f7), 0);
    lv_obj_set_style_bg_opa(button, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(button, lv_color_hex(0xd9d9de), LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(button, 0, 0);
    lv_obj_clear_flag(button, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t *label = lv_label_create(button);
    lv_label_set_text(label, symbol);
    style_text(label, &lv_font_montserrat_18, lv_color_hex(0x101116), LV_TEXT_ALIGN_CENTER);
    lv_obj_center(label);

    return button;
}

static void style_slider(lv_obj_t *slider, int32_t knob_size)
{
    lv_obj_remove_style_all(slider);
    lv_obj_set_style_radius(slider, LV_RADIUS_CIRCLE, LV_PART_MAIN);
    lv_obj_set_style_bg_color(slider, lv_color_hex(0x3a3b43), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(slider, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_radius(slider, LV_RADIUS_CIRCLE, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(slider, lv_color_hex(0xfc3c44), LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(slider, LV_OPA_COVER, LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(slider, LV_OPA_TRANSP, LV_PART_KNOB);
    lv_obj_set_style_border_width(slider, 0, LV_PART_KNOB);
    lv_obj_set_style_pad_all(slider, 0, LV_PART_KNOB);
    lv_obj_clear_flag(slider, LV_OBJ_FLAG_SCROLLABLE);
}

static void create_left_panel(lv_obj_t *parent)
{
    lv_obj_t *panel = lv_obj_create(parent);
    style_clear_obj(panel);
    lv_obj_set_size(panel, 128, PLAYER_SCREEN_HEIGHT);
    lv_obj_align(panel, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_style_bg_opa(panel, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(panel, lv_color_hex(0x111217), 0);
    lv_obj_set_style_pad_left(panel, 18, 0);
    lv_obj_set_style_pad_right(panel, 14, 0);

    lv_obj_t *list = lv_obj_create(panel);
    lv_obj_remove_style_all(list);
    lv_obj_set_size(list, 96, 162);
    lv_obj_align(list, LV_ALIGN_TOP_LEFT, 0, 10);
    lv_obj_set_style_bg_opa(list, LV_OPA_TRANSP, 0);
    lv_obj_set_scroll_dir(list, LV_DIR_VER);
    lv_obj_set_scrollbar_mode(list, LV_SCROLLBAR_MODE_OFF);
    g_player_ui.song_list = list;

    for(uint8_t i = 0; i < SONG_COUNT; i++) {
        lv_obj_t *button = lv_button_create(list);
        lv_obj_remove_style_all(button);
        lv_obj_set_size(button, 96, 34);
        lv_obj_align(button, LV_ALIGN_TOP_LEFT, 0, i * 38);
        lv_obj_set_style_radius(button, 7, 0);
        lv_obj_set_style_bg_opa(button, LV_OPA_COVER, 0);
        lv_obj_set_style_bg_color(button, lv_color_hex(0x191a21), 0);
        lv_obj_set_style_bg_color(button, lv_color_hex(0x262730), LV_STATE_PRESSED);
        lv_obj_clear_flag(button, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_add_event_cb(button, song_event_cb, LV_EVENT_CLICKED, (void *)(uintptr_t)i);
        g_player_ui.song_buttons[i] = button;

        lv_obj_t *title = lv_label_create(button);
        lv_label_set_text(title, g_songs[i].title);
        lv_label_set_long_mode(title, LV_LABEL_LONG_CLIP);
        lv_obj_set_width(title, 84);
        lv_obj_set_height(title, LV_SIZE_CONTENT);
        lv_obj_align(title, LV_ALIGN_LEFT_MID, 6, 0);
        style_text(title, &lv_font_montserrat_16, lv_color_hex(0xffffff), LV_TEXT_ALIGN_LEFT);
    }

    lv_obj_t *volume = create_icon_button(panel, LV_SYMBOL_VOLUME_MAX, 42);
    lv_obj_align(volume, LV_ALIGN_BOTTOM_LEFT, 0, -18);
    lv_obj_add_event_cb(volume, volume_button_event_cb, LV_EVENT_CLICKED, NULL);
}

static void create_player_panel(lv_obj_t *parent)
{
    lv_obj_t *panel = lv_obj_create(parent);
    style_clear_obj(panel);
    lv_obj_set_size(panel, 192, PLAYER_SCREEN_HEIGHT);
    lv_obj_align(panel, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_set_style_bg_opa(panel, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(panel, lv_color_hex(0x181920), 0);
    lv_obj_set_style_pad_left(panel, 22, 0);
    lv_obj_set_style_pad_right(panel, 22, 0);

    g_player_ui.title_label = lv_label_create(panel);
    lv_label_set_long_mode(g_player_ui.title_label, LV_LABEL_LONG_CLIP);
    lv_obj_set_size(g_player_ui.title_label, 148, 24);
    lv_obj_align(g_player_ui.title_label, LV_ALIGN_TOP_LEFT, 0, 34);
    style_text(g_player_ui.title_label, &lv_font_montserrat_18, lv_color_hex(0xffffff), LV_TEXT_ALIGN_LEFT);

    g_player_ui.artist_label = lv_label_create(panel);
    lv_label_set_long_mode(g_player_ui.artist_label, LV_LABEL_LONG_CLIP);
    lv_obj_set_size(g_player_ui.artist_label, 148, 18);
    lv_obj_align(g_player_ui.artist_label, LV_ALIGN_TOP_LEFT, 0, 61);
    style_text(g_player_ui.artist_label, &lv_font_montserrat_12, lv_color_hex(0xa1a2aa), LV_TEXT_ALIGN_LEFT);

    g_player_ui.progress_slider = lv_slider_create(panel);
    style_slider(g_player_ui.progress_slider, 18);
    lv_obj_set_size(g_player_ui.progress_slider, 148, 13);
    lv_obj_align(g_player_ui.progress_slider, LV_ALIGN_TOP_LEFT, 0, 101);
    lv_obj_add_event_cb(g_player_ui.progress_slider, progress_slider_event_cb, LV_EVENT_ALL, NULL);

    g_player_ui.elapsed_label = lv_label_create(panel);
    lv_obj_set_size(g_player_ui.elapsed_label, 50, 16);
    lv_obj_align(g_player_ui.elapsed_label, LV_ALIGN_TOP_LEFT, 0, 120);
    style_text(g_player_ui.elapsed_label, &lv_font_montserrat_12, lv_color_hex(0x8e8f98), LV_TEXT_ALIGN_LEFT);

    g_player_ui.remain_label = lv_label_create(panel);
    lv_obj_set_size(g_player_ui.remain_label, 58, 16);
    lv_obj_align(g_player_ui.remain_label, LV_ALIGN_TOP_RIGHT, 0, 120);
    style_text(g_player_ui.remain_label, &lv_font_montserrat_12, lv_color_hex(0x8e8f98), LV_TEXT_ALIGN_RIGHT);

    lv_obj_t *prev = create_icon_button(panel, LV_SYMBOL_PREV, 36);
    lv_obj_align(prev, LV_ALIGN_BOTTOM_LEFT, 2, -34);
    lv_obj_add_event_cb(prev, prev_event_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_t *play = create_icon_button(panel, LV_SYMBOL_PAUSE, 46);
    lv_obj_align(play, LV_ALIGN_BOTTOM_MID, 0, -29);
    g_player_ui.play_label = lv_obj_get_child(play, 0);
    lv_obj_add_event_cb(play, play_event_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_t *next = create_icon_button(panel, LV_SYMBOL_NEXT, 36);
    lv_obj_align(next, LV_ALIGN_BOTTOM_RIGHT, -2, -34);
    lv_obj_add_event_cb(next, next_event_cb, LV_EVENT_CLICKED, NULL);
}

static void create_volume_popup(void)
{
    if(g_player_ui.volume_overlay != NULL) {
        return;
    }

    g_player_ui.volume_overlay = lv_obj_create(g_player_ui.screen);
    lv_obj_remove_style_all(g_player_ui.volume_overlay);
    lv_obj_set_size(g_player_ui.volume_overlay, PLAYER_SCREEN_WIDTH, PLAYER_SCREEN_HEIGHT);
    lv_obj_center(g_player_ui.volume_overlay);
    lv_obj_set_style_bg_color(g_player_ui.volume_overlay, lv_color_hex(0x000000), 0);
    lv_obj_set_style_bg_opa(g_player_ui.volume_overlay, LV_OPA_40, 0);
    lv_obj_add_flag(g_player_ui.volume_overlay, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(g_player_ui.volume_overlay, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_event_cb(g_player_ui.volume_overlay, volume_overlay_event_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_t *popup = lv_obj_create(g_player_ui.volume_overlay);
    lv_obj_remove_style_all(popup);
    lv_obj_set_size(popup, 190, 132);
    lv_obj_center(popup);
    lv_obj_set_style_radius(popup, 8, 0);
    lv_obj_set_style_bg_color(popup, lv_color_hex(0x22232b), 0);
    lv_obj_set_style_bg_opa(popup, LV_OPA_COVER, 0);
    lv_obj_set_style_border_width(popup, 1, 0);
    lv_obj_set_style_border_color(popup, lv_color_hex(0x3a3b44), 0);
    lv_obj_clear_flag(popup, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(popup, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(popup, LV_OBJ_FLAG_EVENT_BUBBLE);

    g_player_ui.volume_slider = lv_slider_create(popup);
    style_slider(g_player_ui.volume_slider, 24);
    lv_obj_set_size(g_player_ui.volume_slider, 150, 18);
    lv_obj_align(g_player_ui.volume_slider, LV_ALIGN_TOP_MID, 0, 38);
    lv_slider_set_range(g_player_ui.volume_slider, 0, 100);
    lv_slider_set_value(g_player_ui.volume_slider, g_player_ui.volume, LV_ANIM_OFF);
    lv_obj_add_event_cb(g_player_ui.volume_slider, volume_slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    g_player_ui.volume_label = lv_label_create(popup);
    lv_obj_set_size(g_player_ui.volume_label, 70, 18);
    lv_obj_align(g_player_ui.volume_label, LV_ALIGN_TOP_MID, 0, 12);
    style_text(g_player_ui.volume_label, &lv_font_montserrat_14, lv_color_hex(0xffffff), LV_TEXT_ALIGN_CENTER);

    lv_obj_t *icon = lv_obj_create(popup);
    lv_obj_remove_style_all(icon);
    lv_obj_set_size(icon, 42, 42);
    lv_obj_align(icon, LV_ALIGN_BOTTOM_MID, 0, -10);
    lv_obj_set_style_bg_opa(icon, LV_OPA_TRANSP, 0);
    lv_obj_clear_flag(icon, LV_OBJ_FLAG_SCROLLABLE);
    g_player_ui.volume_icon = icon;

    g_player_ui.volume_icon_label = lv_label_create(icon);
    lv_label_set_long_mode(g_player_ui.volume_icon_label, LV_LABEL_LONG_CLIP);
    lv_obj_set_size(g_player_ui.volume_icon_label, 26, 22);
    lv_obj_align(g_player_ui.volume_icon_label, LV_ALIGN_LEFT_MID, 8, 0);
    style_text(g_player_ui.volume_icon_label, &lv_font_montserrat_18, lv_color_hex(0xffffff), LV_TEXT_ALIGN_LEFT);

    update_volume_label();
}

static void close_volume_popup(void)
{
    if(g_player_ui.volume_overlay != NULL) {
        lv_obj_delete(g_player_ui.volume_overlay);
        g_player_ui.volume_overlay = NULL;
        g_player_ui.volume_slider = NULL;
        g_player_ui.volume_label = NULL;
        g_player_ui.volume_icon = NULL;
        g_player_ui.volume_icon_label = NULL;
    }
}

static void update_song_view(void)
{
    const song_t *song = &g_songs[g_player_ui.current_song];
    uint32_t duration = player_audio_get_duration();

    lv_label_set_text(g_player_ui.title_label, song->title);
    lv_label_set_text(g_player_ui.artist_label, song->artist);
    lv_slider_set_range(g_player_ui.progress_slider, 0, duration);
    update_progress_view(g_player_ui.progress_sec, true);
    update_song_selection();
}

static void update_song_selection(void)
{
    for(uint8_t i = 0; i < SONG_COUNT; i++) {
        lv_color_t color = i == g_player_ui.current_song ? lv_color_hex(0x30313b) : lv_color_hex(0x191a21);
        lv_obj_set_style_bg_color(g_player_ui.song_buttons[i], color, 0);
    }

    lv_obj_scroll_to_view(g_player_ui.song_buttons[g_player_ui.current_song], LV_ANIM_ON);
}

static void update_progress_view(uint16_t progress_sec, bool update_slider)
{
    uint16_t duration = (uint16_t)player_audio_get_duration();
    uint16_t elapsed = progress_sec > duration ? duration : progress_sec;
    uint16_t remain = duration - elapsed;

    if(update_slider) {
        lv_slider_set_value(g_player_ui.progress_slider, elapsed, LV_ANIM_OFF);
    }
    lv_label_set_text_fmt(g_player_ui.elapsed_label, "%u:%02u",
                          (unsigned int)(elapsed / 60),
                          (unsigned int)(elapsed % 60));
    lv_label_set_text_fmt(g_player_ui.remain_label, "-%u:%02u",
                          (unsigned int)(remain / 60),
                          (unsigned int)(remain % 60));
}

static void load_current_song(bool play)
{
    const song_t *song = &g_songs[g_player_ui.current_song];

    if(player_audio_load(song->pcm_path)) {
        player_audio_set_volume(g_player_ui.volume);
        player_audio_seek(g_player_ui.progress_sec);
        player_audio_set_playing(play);
    }
    else {
        g_player_ui.playing = false;
        g_player_ui.progress_sec = 0;
        lv_label_set_text(g_player_ui.play_label, LV_SYMBOL_PLAY);
    }

    update_song_view();
}

static void update_volume_label(void)
{
    if(g_player_ui.volume_label != NULL) {
        lv_label_set_text_fmt(g_player_ui.volume_label, "%u%%", (unsigned int)g_player_ui.volume);
    }

    update_volume_icon();
}

static void update_volume_icon(void)
{
    const char *symbol = LV_SYMBOL_VOLUME_MAX;

    if(g_player_ui.volume == 0) {
        symbol = LV_SYMBOL_MUTE;
    }
    else if(g_player_ui.volume <= 50) {
        symbol = LV_SYMBOL_VOLUME_MID;
    }
    else {
        symbol = LV_SYMBOL_VOLUME_MAX;
    }

    if(g_player_ui.volume_icon_label != NULL) {
        lv_label_set_text(g_player_ui.volume_icon_label, symbol);
    }
}

static void progress_timer_cb(lv_timer_t *timer)
{
    (void)timer;

    if(!g_player_ui.playing || g_player_ui.seeking) {
        return;
    }

    g_player_ui.progress_sec = (uint16_t)player_audio_get_position();
    if(!player_audio_is_playing() && g_player_ui.progress_sec >= player_audio_get_duration()) {
        g_player_ui.playing = false;
        lv_label_set_text(g_player_ui.play_label, LV_SYMBOL_PLAY);
    }

    if(g_player_ui.progress_sec > player_audio_get_duration()) {
        g_player_ui.progress_sec = 0;
    }

    update_progress_view(g_player_ui.progress_sec, true);
}

static void song_event_cb(lv_event_t *event)
{
    uint8_t song_index = (uint8_t)(uintptr_t)lv_event_get_user_data(event);

    if(song_index >= SONG_COUNT) {
        return;
    }

    g_player_ui.current_song = song_index;
    g_player_ui.progress_sec = 0;
    g_player_ui.playing = true;
    lv_label_set_text(g_player_ui.play_label, LV_SYMBOL_PAUSE);
    load_current_song(true);
}

static void progress_slider_event_cb(lv_event_t *event)
{
    lv_event_code_t code = lv_event_get_code(event);
    lv_obj_t *slider = lv_event_get_target(event);
    uint16_t value = (uint16_t)lv_slider_get_value(slider);

    if(code == LV_EVENT_PRESSED) {
        g_player_ui.seeking = true;
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        update_progress_view(value, false);
    }
    else if(code == LV_EVENT_RELEASED || code == LV_EVENT_PRESS_LOST) {
        g_player_ui.progress_sec = value;
        player_audio_seek(g_player_ui.progress_sec);
        player_audio_set_playing(g_player_ui.playing);
        g_player_ui.seeking = false;
        update_progress_view(g_player_ui.progress_sec, true);
    }
}

static void play_event_cb(lv_event_t *event)
{
    (void)event;

    g_player_ui.playing = !g_player_ui.playing;
    if(g_player_ui.playing && player_audio_get_duration() > 0 &&
       player_audio_get_position() >= player_audio_get_duration()) {
        g_player_ui.progress_sec = 0;
        player_audio_seek(0);
        update_progress_view(g_player_ui.progress_sec, true);
    }

    player_audio_set_playing(g_player_ui.playing);
    lv_label_set_text(g_player_ui.play_label, g_player_ui.playing ? LV_SYMBOL_PAUSE : LV_SYMBOL_PLAY);
}

static void prev_event_cb(lv_event_t *event)
{
    (void)event;

    if(g_player_ui.current_song == 0) {
        g_player_ui.current_song = SONG_COUNT - 1;
    }
    else {
        g_player_ui.current_song--;
    }

    g_player_ui.progress_sec = 0;
    g_player_ui.playing = true;
    lv_label_set_text(g_player_ui.play_label, LV_SYMBOL_PAUSE);
    load_current_song(true);
}

static void next_event_cb(lv_event_t *event)
{
    (void)event;

    g_player_ui.current_song = (g_player_ui.current_song + 1) % SONG_COUNT;
    g_player_ui.progress_sec = 0;
    g_player_ui.playing = true;
    lv_label_set_text(g_player_ui.play_label, LV_SYMBOL_PAUSE);
    load_current_song(true);
}

static void volume_button_event_cb(lv_event_t *event)
{
    (void)event;

    create_volume_popup();
}

static void volume_overlay_event_cb(lv_event_t *event)
{
    if(lv_event_get_target(event) == g_player_ui.volume_overlay) {
        close_volume_popup();
    }
}

static void volume_slider_event_cb(lv_event_t *event)
{
    lv_obj_t *slider = lv_event_get_target(event);

    g_player_ui.volume = (uint8_t)lv_slider_get_value(slider);
    player_audio_set_volume(g_player_ui.volume);
    update_volume_label();
}
