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

extern struct Side D_0200EB84[];

u8 func_08032A88(u8, u8);

s32 func_080335B4(u8 side, u8 first, u8 last, u16 bits)
{
    s32 result = 0;
    u8 i;

    for (i = first; i <= last; i++)
    {
        if (func_08032A88(side, i))
        {
            D_0200EB84[side].units[i].flags |= bits;
            result = 1;
        }
    }
    return result;
}
