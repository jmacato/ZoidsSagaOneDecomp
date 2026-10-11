#include "types.h"

struct Unit
{
    u8 pad_0[0x10];
    u16 flags;
    u8 pad_12[0x2BA];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

extern struct
{
    struct Side sides[2];
    u8 pad_21B0[0x38];
    u8 result;
} D_0200EB84;

u8 func_08032A88(u8, u8);
u16 func_0800175C(s32, s32);

void func_08032684(void)
{
    s16 i;

    D_0200EB84.result = 3;
    for (i = 0; i <= 5; i++)
    {
        if (func_08032A88(0, i))
        {
            D_0200EB84.result = 0;
            goto enemies;
        }
    }
    for (i = 0; i <= 5; i++)
    {
        if (D_0200EB84.sides[0].units[i].flags & 0x1000)
            D_0200EB84.result = 4;
        else
            break;
    }
enemies:
    if (D_0200EB84.result == 0)
    {
        D_0200EB84.result = 1;
        for (i = 0; i <= 5; i++)
        {
            if (func_08032A88(1, i))
            {
                D_0200EB84.result = 0;
                return;
            }
        }
        for (i = 0; i <= 5; i++)
        {
            if (!(D_0200EB84.sides[1].units[i].flags & 0x1000))
                return;
        }
        D_0200EB84.result = 2;
    }
}

s32 func_0803279C(s32 *cursor, s32 count)
{
    s32 result = 0;
    u16 keys = func_0800175C(0x10, 6);

    if (keys & 1)
        result = 1;
    else if (keys & 2)
        result = 2;
    else if (keys & 0x40)
    {
        if (*cursor)
            (*cursor)--;
        else
            *cursor = count - 1;
    }
    else if (keys & 0x80)
    {
        (*cursor)++;
        if (*cursor >= count)
            *cursor = result;
    }
    return result;
}
