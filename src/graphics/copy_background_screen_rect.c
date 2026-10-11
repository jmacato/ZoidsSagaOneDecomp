#include "graphics/background.h"

void copy_background_screen_rect(const u16 *source, u8 width, u8 height, u8 x, u8 y,
                                 u16 tile_offset, u16 palette_offset, u16 screen_offset)
{
    u16 index = 0;
    u16 row;
    u16 column;

    for (row = 0; row < height; row++)
    {
        for (column = 0; column < width; column++)
        {
            u16 px = x + column;
            u16 page = 0;
            u16 value;
            u16 pal;
            u16 chr;

            if (px > 0x1F)
            {
                page = 0x400;
                px -= 32;
            }
            value = source[index];
            pal = value & 0xF000;
            chr = value & 0xFFF;
            pal = ((pal >> 12) + palette_offset) << 12;
            pal &= 0xF000;
            background_tiles[page + screen_offset + ((row + y) * 32 + px)] = pal | (chr + tile_offset);
            index++;
        }
    }
    mark_background_update(1);
}
