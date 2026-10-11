#include "types.h"

struct Unit
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[0x2C2];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

extern struct
{
    union
    {
        struct Side sides[2];
        struct
        {
            u8 pad_0[2];
            u16 flags;
        } header;
    } u;
    u8 pad_21B0[0x40];
    u8 refresh;
    u8 pad_21F1[3];
    u8 side;
    u8 unit;
} D_0200EB84;

s32 func_08032A88(u8, u8);

void func_0803CD9C(void)
{
    u8 side;
    u8 i;

    for (side = 0; side <= 1; side++)
    {
        for (i = 0; i <= 5; i++)
        {
            if (func_08032A88(side, i) != 0 && (side != D_0200EB84.side || i != D_0200EB84.unit))
                D_0200EB84.u.sides[side].units[i].flags |= 1;
        }
    }
    D_0200EB84.refresh = 0xFF;
}

void func_0803CE1C(void)
{
    D_0200EB84.u.header.flags |= 0x20;
    D_0200EB84.refresh = 0xFF;
}

void func_0803CE38(void)
{
    D_0200EB84.u.header.flags |= 0x40;
    D_0200EB84.refresh = 0xFF;
}
