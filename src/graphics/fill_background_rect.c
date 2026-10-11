#include "graphics/background.h"


s32 fill_background_rect(u16 tile, u8 width, u8 height, u8 stride, u8 x, u8 y, u16 tile_offset)
{
    u8 row;
    u8 column;

    for (row = 0; row < height; row++)
    {
        for (column = 0; column < width; column++)
            background_tiles[stride * (row + y) + (column + x)] = tile + tile_offset;
    }
    mark_background_update(1);
}
