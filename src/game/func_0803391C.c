#include "types.h"

struct Unit
{
    u8 pad_0[0x16];
    u16 zoid;
    u8 pad_18[0xBF];
    u8 order;
    u8 pad_D8[0x1F4];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Body
{
    u8 pad_0[0xE];
    u16 zoid;
};

extern struct
{
    struct Side sides[2];
} D_0200EB84;

u8 func_08032A88(u8, u8);

void func_0803391C(u8 side, struct Body *body)
{
    u8 list[6];
    u8 count = 0;
    u8 i;
    u8 j;

    for (i = 0; i < 6; i++)
    {
        if (func_08032A88(side, i) && D_0200EB84.sides[side].units[i].order == 0 && body->zoid == D_0200EB84.sides[side].units[i].zoid)
        {
            list[count] = i;
            count++;
        }
    }
    if (count > 1)
    {
        for (j = 0; j < count; j++)
            D_0200EB84.sides[side].units[list[j]].order = j + 1;
    }
}
