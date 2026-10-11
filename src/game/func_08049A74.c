#include "types.h"

struct Actor
{
    u8 pad_0[8];
    s32 x;
    s32 y;
    u8 pad_10[0x46];
    u16 field_56;
};

extern u8 D_0200E238;

void func_08049A74(struct Actor *actor, s32 dx, s32 dy)
{
    if (dx < 0)
        actor->field_56 += (u32)(~dx + 1) >> 16;
    else
        actor->field_56 += (u32)dx >> 16;
    if (D_0200E238 == 0)
        dx = ~dx + 1;
    actor->x += dx;
    actor->y -= dy;
}
