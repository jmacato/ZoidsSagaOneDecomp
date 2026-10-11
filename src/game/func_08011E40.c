#include "types.h"

struct Sprite
{
    u8 pad_0[8];
    s32 x;
    s32 y;
    u8 pad_10[0x78];
};

extern struct Sprite D_03004BBC[];

void func_08008324(s32, s32);
void func_0805EE78(s32);

void func_08011E40(u16 index, u8 frames, s32 step, u8 flags)
{
    u8 i;

    for (i = 0; i < frames; i++)
    {
        D_03004BBC[index + 1].x += step << 16;
        if (index == 0 && (flags & 1))
            func_08008324(step << 16, 0);
        func_0805EE78(1);
    }
}
