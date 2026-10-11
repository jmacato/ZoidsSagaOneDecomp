#include "types.h"

struct Unit
{
    u8 pad_0[0x4A];
    u8 kind;
    u8 pad_4B[0x281];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

extern struct Side D_0200EB84[];

u8 func_08036630(u8, u8);

u8 func_080365C8(u8 side, u8 kind)
{
    u8 result = 0xFF;
    u8 i;

    for (i = 0; i <= 5; i++)
    {
        if (func_08036630(side, i) && D_0200EB84[side].units[i].kind == kind)
        {
            result = i;
            break;
        }
    }
    return result;
}
