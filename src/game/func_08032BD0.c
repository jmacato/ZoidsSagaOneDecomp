#include "types.h"

struct Effect
{
    u8 pad_0[1];
    u8 turns;
    u8 pad_2[6];
};

struct Unit
{
    u8 pad_0[0x148];
    struct Effect effects[0x30];
    u8 pad_2C8[4];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

extern struct Side D_0200EB8C[];

void func_08032BD0(void)
{
    u8 side;
    u8 i;
    u8 j;

    for (side = 0; side <= 1; side++)
    {
        for (i = 0; i <= 5; i++)
        {
            struct Side *group = &D_0200EB8C[side];
            struct Unit *unit = &group->units[i];

            for (j = 0; j <= 0x2F; j++)
            {
                if (unit->effects[j].turns != 0)
                    unit->effects[j].turns--;
            }
        }
    }
}
