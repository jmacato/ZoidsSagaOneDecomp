#include "types.h"

struct Unit
{
    u8 pad_0[0xE];
    u16 kind;
    u8 pad_10[0x32];
    u8 slot;
    u8 pad_43[0x289];
};

struct Side
{
    u8 pad_0[8];
    struct Unit units[6];
    u8 pad_10D0[8];
};

extern struct Side D_0200EB84[];

u8 func_08032AC4(u8 side, u8 slot)
{
    u8 result = 0xFF;
    u8 i;

    for (i = 0; i <= 5; i++)
    {
        if (D_0200EB84[side].units[i].kind != 0xFF && D_0200EB84[side].units[i].slot == slot)
        {
            result = i;
            break;
        }
    }
    return result;
}
