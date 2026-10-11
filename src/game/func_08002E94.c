#include "types.h"

extern u16 D_0300239C[];

void func_08002E94(void)
{
    u32 tile = 0x115;
    u32 row;
    u32 column;

    for (row = 0; row <= 0x13; row++)
    {
        for (column = 0; column <= 0x1D; column++)
        {
            if (row - 2 > 0xF)
                D_0300239C[0x800 + row * 32 + column] = 0x80;
            else
                D_0300239C[0x800 + row * 32 + column] = tile++;
        }
    }
}
