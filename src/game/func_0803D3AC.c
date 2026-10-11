#include "types.h"

struct Status
{
    u16 flags;
    u8 pad_2[6];
    u32 value;
    u8 pad_C[0x1C];
    u32 base;
};

struct Sub
{
    u16 flags;
    u8 pad_2[6];
};

struct Unit
{
    u8 pad_0[8];
    struct Sub sub;
    struct Status status;
    u8 pad_3C[0x290];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Battle
{
    struct Side sides[2];
    u8 pad_21B0[0x40];
    u8 result;
    u8 pad_21F1[3];
    u8 side;
    u8 slot;
};

extern struct Battle D_0200EB84;

u8 func_08032AC4(s32, s32);
s32 func_08032A88(s32, u8);
void func_08032B54(struct Sub *, s32, s32, s32, s32, s32);

void func_0803D3AC(void)
{
    struct Battle *battle = &D_0200EB84;
    u8 *result = &battle->result;
    u8 i;

    *result = 0xFF;
    i = func_08032AC4(0, 0);
    if (i != 0xFF)
    {
        D_0200EB84.sides[D_0200EB84.side].units[D_0200EB84.slot].sub.flags |= 1;
        if (func_08032A88(0, i))
        {
            struct Status *status = &D_0200EB84.sides[0].units[i].status;
            struct Sub *sub;

            status->flags &= 0xBFFF;
            status->value = status->base;
            sub = &D_0200EB84.sides[0].units[i].sub;
            func_08032B54(sub, 0x11, 0x64, 1, 1, 0);
            func_08032B54(sub, 0x21, 0x64, 1, 1, 0);
            func_08032B54(sub, 0x101, 0x64, 1, 1, 0);
            func_08032B54(sub, 0x801, 0x64, 1, 1, 0);
        }
        else
            *result = 1;
    }
    else
        *result = 1;
}
