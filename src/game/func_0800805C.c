#include "types.h"

extern struct
{
    u8 pad_0[8];
    u16 *map;
    u8 pad_C[4];
    u16 x;
    u16 y;
    u16 width;
    u16 height;
} D_0200000C;

extern u16 D_0300239C[];

s32 func_0800805C(void)
{
    u32 offset = 0x800;
    u16 *map;
    u16 width;
    u16 x;
    u16 y;
    u16 i;

    if (D_0200000C.x == 0)
        return 1;
    D_0200000C.x += 0xFFFF;
    map = D_0200000C.map;
    width = D_0200000C.width;
    x = D_0200000C.x;
    y = D_0200000C.y;
    for (i = y; i != (u16)(y + 20); i++)
        D_0300239C[(i & 0x1F) * 32 + (x & 0x1F) + offset] = map[i * width + x];
    return 0;
}
