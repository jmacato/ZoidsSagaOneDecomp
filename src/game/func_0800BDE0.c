#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[0x48];
    u16 state;
    u8 pad_4C[0x3C];
};

extern struct Sprite D_03004BBC[];
extern struct
{
    u8 pad_0[6];
    u16 count;
} D_0200000C;
extern void (*const D_08666D34[])(u16);

void func_08000AF8(u16, u16);

s32 func_0800BDE0(void)
{
    u16 i;

    for (i = 2; i < D_0200000C.count + 1; i++)
    {

        if (D_03004BBC[i].flags & 0x8000)
        {
            D_08666D34[D_03004BBC[i].state](i);
            func_08000AF8(i, D_03004BBC[i].flags & 0x400);
        }
    }
    return 0;
}
