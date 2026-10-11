#include "graphics/background.h"

s32 copy_background_rect(const u16 *source, u8 width, u8 height, u8 stride, u8 x, u8 y, u16 tile_offset)
{
    u16 row;
    u16 column;
    u16 index = 0;

    for (row = 0; row < height; row++)
    {
        for (column = 0; column < width; column++)
            background_tiles[(row + y) * stride + (column + x)] = source[index++] + tile_offset;
    }
    mark_background_update(1);
}
