#include "types.h"

struct Unit
{
    u16 flags;
    u8 pad_2[0x2CA];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

extern struct
{
    u8 pad_0[2];
    u16 field_2;
    u8 pad_4[4];
    struct Side sides[2];
} D_0200EB84;

void region_08033570(void)
{
    u8 side;
    u8 unit;

    D_0200EB84.field_2 = 0;
    for (side = 0; side <= 1; side++)
    {
        for (unit = 0; unit <= 5; unit++)
            D_0200EB84.sides[side].units[unit].flags = 0;
    }
}
