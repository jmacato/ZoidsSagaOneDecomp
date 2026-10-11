#include "graphics/sprites.h"

extern u16 D_0200758A[];
extern u8 D_0200758C[];
extern u8 D_030022E5;
extern struct
{
    u8 pad_0[0xD18];
    u8 name[16];
} D_02000B5C;

void func_0804BCDC(void);

void func_0804BF78(void)
{
    u8 found = 0;
    u16 i;
    register u16 *base asm("r4");
    register u16 *scan asm("r6");
    register u32 space asm("r0");
    register u32 padding asm("r5");

    i = 8;
    base = D_0200758A;
    scan = base;
    asm("" : : "r"(base), "r"(scan));
    space = 0x8140;
    asm("" : "+r"(space));
    padding = space;
    asm("" : : "r"(padding));
    for (; i != 0; i--)
    {
        if (D_0200758A[i] == 0 && !found)
            D_0200758A[i] = padding;
        else
            found = 1;
    }
    i = 8;
    if (D_0200758A[8] == 0x8140)
    {
        D_0200758A[8] = 0;
        while (1)
        {
            if (i == 1)
            {
                func_0804BCDC();
                D_030022E5 = 4;
                set_sprite_animation(2, 4);
                i = 9;
            }
            i--;
            if (i == 0 || *(D_0200758A + i) != 0x8140)
                break;
            *(D_0200758A + i) = 0;
        }
    }
    for (i = 0; i < 16; i++)
        D_02000B5C.name[i] = D_0200758C[i];
}
