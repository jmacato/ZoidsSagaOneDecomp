#include "types.h"

struct Unit
{
    u8 pad_0[0x10];
    u16 flags;
    u8 pad_12[0x2BA];
};

extern struct Unit D_0200EB84[];

void func_0802F04C(void)
{
    u16 i;

    for (i = 0; i <= 5; i++)
        D_0200EB84[i].flags |= 0x3000;
}
