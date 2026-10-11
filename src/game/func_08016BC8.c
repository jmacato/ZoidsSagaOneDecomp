#include "types.h"

struct Sprite
{
    u8 pad_0[8];
    u32 x;
    u32 y;
    u8 pad_10[0x78];
};

extern struct Sprite D_03004BBC[];

void func_08008B70(u16, u16, u16);
void func_0805EE78(s32);

void func_08016BC8(u32 index)
{
    u32 x = D_03004BBC[index + 1].x >> 21;
    u32 y = D_03004BBC[index + 1].y >> 21;
    u32 i;

    for (i = 0; i <= 3; i++)
    {
        func_08008B70(index, 0xFF, 0xFF);
        func_0805EE78(8);
        func_08008B70(index, x, y);
        func_0805EE78(8);
    }
    func_08008B70(index, 0xFF, 0xFF);
}
