#include "types.h"

struct Place
{
    u8 pad_0[8];
    u32 x;
    u32 y;
};

struct Sprite
{
    u8 pad_0[8];
    u32 x;
    u32 y;
    u8 pad_10[0x78];
};

extern struct Sprite D_03004BBC[];
extern const struct Place D_0866B2E0[][6];

void func_0803851C(u8 side, u8 slot)
{
    D_03004BBC[4].x = (double)D_0866B2E0[side][slot].x + 524288.0;
    D_03004BBC[4].y = (double)D_0866B2E0[side][slot].y - 1048576.0;
}
