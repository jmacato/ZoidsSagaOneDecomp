#include "types.h"

extern u16 D_0300239C[];

s32 func_0800A35C(u16 tile, u8 width, u8 height, u8 stride, u8 x, u8 y, u16 offset)
{
    u8 row;
    u8 column;

    for (row = 0; row < height; row++)
    {
        for (column = 0; column < width; column++)
        {
            D_0300239C[(row + y) * stride + (column + x)] = tile + offset;
            tile++;
        }
    }
}
