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
extern const struct Place D_0866B2E0[];

void func_0803847C(u8 index)
{
    D_03004BBC[4].x = (double)(D_0866B2E0[index].x - 0x780000) + 524288.0;
    D_03004BBC[4].y = (double)D_0866B2E0[index].y - 1048576.0;
}
