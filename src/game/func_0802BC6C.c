#include "types.h"

struct Party
{
    u8 pad_0[0x10D0];
    u8 slots[6];
};

extern u8 D_02003FF8[];

void func_0802BC6C(struct Party *party)
{
    u16 i;

    for (i = 0; i <= 5; i++)
        party->slots[i] = D_02003FF8[i];
}
