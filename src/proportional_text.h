#ifndef ZOIDS_SAGA_PROPORTIONAL_TEXT_H
#define ZOIDS_SAGA_PROPORTIONAL_TEXT_H

#include "text.h"

typedef struct {
    u16 code;
    u8 left;
    u8 width;
    u8 advance;
    signed char shift;
} LatinMetric;

typedef struct {
    u32 codes;
    signed char adjustment;
    u8 reserved[3];
} LatinPair;

extern const LatinMetric latin_metrics[];
extern const u32 latin_metric_count;
extern const LatinPair latin_pairs[];
extern const u32 latin_pair_count;
extern u8 *text_tile_buffer;
extern u8 text_tile_usage[192];

int proportional_fits(u8 window, const u16 *codes, unsigned count, unsigned reserve);
void proportional_emit(u8 window, u16 code);
void proportional_pad(u8 window, u8 pixels);
void proportional_keyboard_glyph(u8 window, u16 code);
void proportional_release(u8 window);
int proportional_window_callback(u8 window, u8 command, u8 high, u8 low);
int original_window_callback(u8 window, u8 command, u8 high, u8 low);

#endif
