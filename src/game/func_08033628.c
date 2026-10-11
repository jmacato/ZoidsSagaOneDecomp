#include "types.h"

struct Unit
{
    u8 data[0x2CC];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

extern struct Side D_0200EB8C[];

u8 func_08032A88(u8, u8);
void func_08032B54(struct Unit *, u16, u16, u8, u8, s32);

u8 func_08033628(u8 side, u8 first, u8 last, u16 a, u16 b, u8 c, u8 d)
{
    u8 found = 0;
    u8 i;

    for (i = first; i <= last; i++)
    {
        if (func_08032A88(side, i))
        {
            struct Side *group = &D_0200EB8C[side];

            func_08032B54(&group->units[i], a, b, c, d, 0);
            found = 1;
        }
    }
    return found;
}
