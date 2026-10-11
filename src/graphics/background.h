#ifndef ZOIDS_SAGA_BACKGROUND_H
#define ZOIDS_SAGA_BACKGROUND_H

#include "types.h"

extern u16 background_tiles[0x1400];
extern u8 background_update;

void mark_background_update(u8 value);
s32 fill_background_rect(u16 tile, u8 width, u8 height, u8 stride, u8 x, u8 y, u16 tile_offset);
s32 copy_background_rect(const u16 *source, u8 width, u8 height, u8 stride, u8 x, u8 y, u16 tile_offset);
void copy_background_screen_rect(const u16 *source, u8 width, u8 height, u8 x, u8 y,
                                 u16 tile_offset, u16 palette_offset, u16 screen_offset);
void copy_mirrored_background_screen_rect(const u16 *source, u8 width, u8 height, u8 x, u8 y,
                                          u16 tile_offset, u16 palette, u16 screen_offset);
void fill_background_screen_rect(u16 tile, u8 width, u8 height, u8 x, u8 y,
                                 u16 tile_offset, u16 palette, u16 screen_offset);

#endif
