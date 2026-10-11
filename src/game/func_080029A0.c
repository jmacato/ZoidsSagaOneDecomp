#include "types.h"

extern u16 D_0300239C[];

void func_080029A0(void)
{
    u32 tile = 0;
    u32 row;
    u32 column;

    for (row = 4; row <= 5; row++)
    {
        for (column = 0; column <= 13; column++)
        {
            D_0300239C[row * 32 + 7 + column] = tile + 0xE205;
            tile++;
        }
    }
}
