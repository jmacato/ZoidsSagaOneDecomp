#include "types.h"

struct Warp
{
    u16 field_0;
    u16 x;
    u16 y;
    u16 direction;
    u16 sound;
    u16 map;
};

extern const struct Warp *const D_0831FC6C[];
extern struct
{
    u8 pad_0[2];
    u16 area;
} D_0200000C;
extern struct
{
    u8 pad_0[0xE2];
    u16 tile;
} D_03004BBC;

void func_080019EC(u16);

s32 func_080083B8(u16 index, u16 *x, u16 *y, u16 *direction, u16 *map)
{
    const struct Warp *warps = D_0831FC6C[D_0200000C.area];

    *x = (warps[index & 0xFF]).x;
    *y = (warps[index & 0xFF]).y;
    *direction = (warps[index & 0xFF]).direction;
    *map = (warps[index & 0xFF]).map;
    if ((warps[index & 0xFF]).sound == 0)
    {
        if (D_03004BBC.tile == 0x98)
            func_080019EC(0x45);
        else
            func_080019EC(0x82);
    }
    else if ((warps[index & 0xFF]).sound != 0x44)
    {
        func_080019EC((warps[index & 0xFF]).sound);
    }
}
