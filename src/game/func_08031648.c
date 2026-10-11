#include "graphics/background.h"

extern u16 D_0300239C[];

void func_08031648(u16 x, u16 width, u16 y, u16 height, u16 palette)
{
    register u16 palette_bits asm("r12") = palette;
    u16 row;
    u32 column;

    width += x;
    height += y;
    asm("" : : "r"(palette_bits));
    for (row = y; row < height;)
    {
        column = x;
        {
            register u32 next_row asm("r4") = row + 1;

            for (; column < width; column++)
                D_0300239C[row * 32 + column] =
                    (D_0300239C[row * 32 + column] & 0xFFF) | palette_bits;
            {
                register u32 narrowed asm("r0") = next_row << 16;

                asm("" : "+r"(narrowed));
                row = narrowed >> 16;
            }
        }
    }
    mark_background_update(1);
}
