#include "types.h"

struct Unit
{
    u8 pad_0[0xD7];
    u8 order;
    u8 pad_D8[0x1F4];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

extern struct
{
    struct Side sides[2];
} D_0200EB84;

extern struct Side D_0200EB8C[];

u8 func_08032A88(u8, u8);
void func_0803391C(u8, void *);

void func_080338A8(u8 side)
{
    u8 i;

    for (i = 0; i <= 5; i++)
        D_0200EB84.sides[side].units[i].order = 0;
    for (i = 0; i <= 5; i++)
    {
        struct Side *group = &D_0200EB8C[side];

        if (func_08032A88(side, i))
            func_0803391C(side, &group->units[i]);
    }
}
