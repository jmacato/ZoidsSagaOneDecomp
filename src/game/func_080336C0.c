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

extern struct Side D_0200EB84[];

void func_080336C0(void)
{
    u8 side;
    u8 unit;

    for (side = 0; side <= 1; side++)
    {
        for (unit = 0; unit <= 5; unit++)
            D_0200EB84[side].units[unit].flags &= 0x7FFF;
    }
}
