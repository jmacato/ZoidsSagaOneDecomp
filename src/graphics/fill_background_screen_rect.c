#include "graphics/background.h"

void fill_background_screen_rect(u16 tile, u8 width, u8 height, u8 x, u8 y,
                                 u16 tile_offset, u16 palette, u16 screen_offset)
{
    u16 row;
    u16 column;
    u16 bits = palette & 0xF000;

    for (row = 0; row < height; row++)
    {
        for (column = 0; column < width; column++)
        {
            u16 px = x + column;
            u16 page = 0;

            if (px > 0x1F)
            {
                page = 0x400;
                px -= 32;
            }
            background_tiles[screen_offset + page + ((row + y) * 32 + px)] = (tile + tile_offset) | bits;
        }
    }
    mark_background_update(1);
}
