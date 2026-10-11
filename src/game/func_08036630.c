#include "types.h"

struct Unit
{
    u8 pad_0[8];
    vu16 flags;
    u8 pad_A[4];
    u16 kind;
    u8 pad_10[0x2BC];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

extern struct Side D_0200EB8C[];

s32 func_08036630(u8 side, u8 slot)
{
    s32 result = 0;
    struct Side *group = &D_0200EB8C[side];
    struct Unit *unit = &group->units[slot];

    if (unit->kind != 0xFF && !(unit->flags & 0x800))
        result = 1;
    return result;
}
