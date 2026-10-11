#include "types.h"

struct Unit
{
    u8 pad_0[0x2CC];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

extern struct Side D_0200EB8C[];

void func_0803376C(struct Unit *);

void func_08033718(void)
{
    u8 side;
    u8 i;

    for (side = 0; side <= 1; side++)
    {
        for (i = 0; i <= 5; i++)
        {
            struct Side *group = &D_0200EB8C[side];

            func_0803376C(&group->units[i]);
        }
    }
}
