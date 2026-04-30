# Minimal Music Player Design

## Overview

This project implements a minimal landscape music player for a `320x240` LVGL display.

The UI is split into two panels:

- Left panel: scrollable song list and volume entry button.
- Right panel: current song information, seek control, time labels, and playback controls.

The implementation lives in `src/player_ui/` and is wired into the build through `src/player_ui/player_ui.cmake`.

## Screen And Layout

- Screen size: `320x240`.
- Left panel width: `128`.
- Right panel width: `192`.
- Background uses a dark, restrained Apple Music-inspired style.
- No decorative elements beyond the required player controls.

## Left Song List

The left panel contains a scrollable song list above the volume button.

- Song count: `8`.
- Each list item displays only the song title.
- Artist names are not shown in the left list.
- List item size: `96x34`.
- List item spacing: `38px`.
- Song title font: `lv_font_montserrat_16`.
- Song title alignment: `LV_ALIGN_LEFT_MID`.
- Song title height: `LV_SIZE_CONTENT`, so the label itself is vertically centered rather than drawing inside a tall label.
- The selected song item uses a brighter background.
- The list is vertically scrollable and hides the scrollbar.

When changing songs from the right-side previous/next buttons, the selected item is automatically scrolled into view with:

```c
lv_obj_scroll_to_view(g_player_ui.song_buttons[g_player_ui.current_song], LV_ANIM_ON);
```

## Right Player Panel

The right panel displays:

- Current song title.
- Current artist name.
- Seek slider.
- Elapsed time label.
- Remaining time label.
- Previous, play/pause, and next buttons.

The song metadata comes from the local `g_songs` array:

- `title`
- `artist`
- `duration_sec`

Changing the current song refreshes the right panel through `update_song_view()`.

## Progress Slider

The progress control uses `lv_slider`, not `lv_bar`, so it can be touched and dragged.

- Size: `148x13`.
- Knob is hidden.
- The bar is thick enough for touch interaction.
- The elapsed and remaining time labels update while dragging.
- On release, the slider value is committed to `progress_sec`.
- While the user is dragging, the timer does not advance the progress value.

Important interaction behavior:

- `LV_EVENT_PRESSED`: enter seeking mode.
- `LV_EVENT_VALUE_CHANGED`: preview the time labels.
- `LV_EVENT_RELEASED` / `LV_EVENT_PRESS_LOST`: commit the seek value.

## Playback Controls

The player has three circular white buttons:

- Previous.
- Play / pause.
- Next.

The buttons use LVGL symbols from the built-in symbol font.

Behavior:

- Play/pause toggles `playing`.
- Previous wraps from the first song to the last song.
- Next wraps from the last song to the first song.
- Previous/next reset progress to `0`.
- Previous/next refresh the right panel and left selected list item.
- Previous/next also trigger list auto-scroll when the selected item is outside the visible range.

## Volume Entry Button

The left bottom volume control is a circular white button.

- Size: `42x42`.
- Uses `LV_SYMBOL_VOLUME_MAX`.
- Opens the volume popup.

This button remains fixed and does not scroll with the song list.

## Volume Popup

The volume popup opens from the volume button.

Popup behavior:

- Uses a full-screen semi-transparent overlay.
- Popup is centered.
- Clicking outside the popup closes it.
- Clicking inside the popup does not close it.

Popup contents:

- Current volume percentage label.
- Thick horizontal volume slider.
- White volume icon without a background.

The popup size is `190x132`.

## Volume Slider

The volume control uses `lv_slider`.

- Range: `0-100`.
- Size: `150x18`.
- Knob is hidden.
- Thick bar improves touch usability.
- Updates the percentage label and volume icon on `LV_EVENT_VALUE_CHANGED`.

## Volume Icon

The popup volume icon is displayed below the slider.

Current design:

- No background.
- Icon color: white.
- Fixed position.
- Updating the volume only changes the icon text.
- No centering or relayout is performed when the icon changes.

The icon has three states:

- `0%`: `LV_SYMBOL_MUTE`
- `1-50%`: `LV_SYMBOL_VOLUME_MID`
- `51-100%`: `LV_SYMBOL_VOLUME_MAX`

The fixed label layout prevents visual jumping when the icon changes.

## Build Integration

The player module follows the same build pattern as other UI modules:

- `src/player_ui/player_ui.c`
- `src/player_ui/player_ui.h`
- `src/player_ui/player_ui.cmake`

`CMakeLists.txt` includes `player_ui.cmake`, adds the include directory, and appends `${PLAYER_UI_SOURCES}` to `MAIN_SOURCES`.

`src/main.c` initializes SDL with:

```c
sdl_hal_init(PLAYER_SCREEN_WIDTH, PLAYER_SCREEN_HEIGHT);
```

Then it loads the UI with:

```c
player_ui_init();
```

## Verification

The current implementation has been validated with:

```sh
cd build && make -j16 && cd ..
```

Short runtime checks were also performed with:

```sh
timeout 3 ./bin/main
```

The runtime command may print LVGL assert/performance warnings depending on `lv_conf.h`; these warnings are unrelated to the player UI behavior.
