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

s32 func_080081EC(void)
{
    u32 offset = 0x800;
    u16 *map;
    u16 width;
    u16 x;
    u16 y;
    u16 row;
    u16 i;

    if (D_0200000C.y == D_0200000C.height - 20)
        return 1;
    D_0200000C.y++;
    y = D_0200000C.y;
    map = D_0200000C.map;
    width = D_0200000C.width;
    i = x = D_0200000C.x;
    row = y + 19;
    for (; i != (u16)(x + 30); i++)
        D_0300239C[(row & 0x1F) * 32 + (i & 0x1F) + offset] = map[row * width + i];
    return 0;
}
