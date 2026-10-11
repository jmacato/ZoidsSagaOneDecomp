#include "types.h"

struct Unit
{
    u8 bytes[0x2CC];
};

struct Side
{
    u8 pad_0[4];
    struct Unit units[6];
};

void func_0802B5D0(struct Side *, u8);
void func_08031618(struct Unit *, s32);

void func_0802B5A0(struct Side *side)
{
    u8 i;

    for (i = 0; i <= 5; i++)
    {
        func_0802B5D0(side, i);
        func_08031618(&side->units[i], 0x11);
    }
}
