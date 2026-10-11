#include "types.h"

extern struct
{
    u8 pad_0[0x1A0];
    s32 x;
    s32 y;
} D_03004BBC;

void func_0804BEC0(u8 x, u8 y)
{
    D_03004BBC.x = (x << 20) + 0x80000;
    D_03004BBC.y = (y << 20) + 0x490000;
}
