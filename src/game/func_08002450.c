#include "types.h"

extern u16 D_0300239C[];

void func_08002450(s32 offset)
{
    u32 tile = 0;
    u32 row;
    u32 column;

    for (row = 0; row <= 5; row++)
    {
        for (column = 0; column <= 9; column++)
        {
            D_0300239C[row * 32 + offset + column] = tile + 0xC175;
            tile++;
        }
    }
}
