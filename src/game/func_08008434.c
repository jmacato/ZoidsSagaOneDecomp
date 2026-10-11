#include "types.h"

struct Object
{
    u8 pad_0[0x4E];
    u16 x;
    u16 y;
    u8 pad_52[0x36];
};

extern struct Object D_03004BBC[];
extern struct
{
    u8 pad_0[0xC];
    u16 *map;
    u8 pad_10[4];
    u16 width;
    u8 pad_16[2];
    u16 size;
} D_0200000C;

u16 func_0805D484(u16, u16);

u16 func_08008434(u16 index, u16 dx, u16 dy)
{
    u16 x = dx + D_03004BBC[index].x;
    u16 y = dy + D_03004BBC[index].y;

    if (D_0200000C.size == 2)
        y++;
    return D_0200000C.map[func_0805D484(D_0200000C.width, D_0200000C.size) * y + x];
}
