#include "graphics/background.h"

void copy_mirrored_background_screen_rect(const u16 *source, u8 width, u8 height, u8 x, u8 y,
                                          u16 tile_offset, u16 palette, u16 screen_offset)
{
    u16 bits;
    u16 index = 0;
    u16 row;
    u16 column;

    bits = palette & 0xF000;

    for (row = 0; row < height; row++)
    {
        u16 offset;

        for (column = 0, offset = width - 1; column < width; column++)
        {
            u16 px = x + offset;
            u16 page = 0;

            if (px > 0x1F)
            {
                page = 0x400;
                px -= 32;
            }
            background_tiles[screen_offset + page + ((row + y) * 32 + px)] = (tile_offset + source[index++]) | (bits | 0x400);
            offset--;
        }
    }
    mark_background_update(1);
}
