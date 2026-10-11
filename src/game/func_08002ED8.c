#include "types.h"

extern u16 D_0300239C[];

void func_08002ED8(void)
{
    register u32 tile asm("r4") = 0;
    u32 row;
    u32 column;

    for (row = 0; row <= 2; row++)
    {
        for (column = 0; column <= 13; column++)
        {
            D_0300239C[row * 32 + column] = tile + 0xD1B1;
            tile++;
        }
    }
    for (row = 0; row <= 2;)
    {
        u32 next_row;

        /* Keep both row values live to preserve the original loop schedule. */
        column = 0;
        next_row = row + 1;
        asm("" : : "r"(column), "r"(next_row));
        for (; column <= 13; column++)
        {
            D_0300239C[row * 32 + 14 + column] = tile + 0xD1B1;
            tile++;
        }
        asm("" : : "r"(tile), "r"(row));
        row = next_row;
    }
}
