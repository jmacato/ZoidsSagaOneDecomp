#ifndef ZOIDS_SAGA_TEXT_H
#define ZOIDS_SAGA_TEXT_H

#include "types.h"

typedef int (*WindowCallback)(u8 window, u8 command, u8 high, u8 low);

typedef struct {
    u16 first;
    u16 count;
    const u8 *tiles;
} FontRange;

typedef struct {
    u8 id;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u8 columns;
    u8 unknown06;
    u8 style;
    u8 palette;
    u8 flags;
    u8 cursor_x;
    u8 cursor_y;
    u8 unknown0c;
    u8 unknown0d;
    u8 active;
    u8 unknown0f;
    WindowCallback callback;
    u8 glyph_slots[0x340];
} TextWindow;

typedef char TextWindowSizeCheck[sizeof(TextWindow) == 0x354 ? 1 : -1];

extern TextWindow text_windows[8];
extern const FontRange font_ranges[111];
extern u8 font_current_range;
extern u8 font_glyph_buffer[0x3000];
extern const u8 font_missing_upper[32];
extern const u8 font_missing_lower[32];
extern u8 text_tile_usage[];
extern u16 window_tilemap[];
extern u16 window_tile_offset;
extern u16 window_input_flags;
extern TextWindow *text_current_window;
extern u16 *window_screen_tilemap;

u8 font_find_range(u16 code);
const u8 *font_get_glyph(u16 code);
const u8 *script_get_entry(u16 index);
int script_interpret(const u8 *script);
int script_run_table(const u8 **table, u32 index_word);
void dispatch_window_callback(u8 window, u8 command, u8 high, u8 low);
void window_write_tile(u16 x, u16 y, u16 tile, u8 flip);
void window_emit_character(u8 window, u16 character);
void window_release_glyphs(u8 window);
void window_release_cell(u8 window, u16 x, u16 y, u32 unused3, u32 unused4, u8 *slots);
void window_close(u8 window);
void window_clear_selection(u8 window);
int window_initialize(u8 window, u8 style, u8 x, u8 y, u8 width, u8 height, u8 flags);
int window_render_callback(u8 window, u8 command, u8 high, u8 low);
void window_play_sound(u8 window, u8 sound);
void window_draw_continue(u8 window);
void window_clear_continue(u8 window);
void window_clear_screen(void);
void window_clear_tilemap(void);
void window_reset(void);
void window_draw_frame(u8 window, u16 x, u16 y, u8 width, u8 height);
void window_draw_selection(u8 window);
u16 window_adjust_number(u16 value, u16 direction, u8 digit, u8 width);
void window_draw_direction(u8 window, u16 direction, u8 erase);
void window_refresh_directions(u8 window, u8 mode);
void window_print_number(u8 window, u16 value, u8 width, u8 format);
void window_commit(void);
void window_scroll_glyphs(u8 window);
void window_draw_glyphs(u8 window, u16 x, u16 y, u8 width, u8 height);
void window_load_portrait(u8 window, u16 portrait, u8 expression);
void window_load_overlay_portrait(u16 portrait, u8 expression);
void window_noop(void);

#endif
