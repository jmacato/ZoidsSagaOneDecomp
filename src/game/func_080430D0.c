#include "types.h"

struct Part
{
    u16 flags;
    u16 id;
};

struct Info
{
    u8 pad_0[8];
    struct Part parts[17];
};

extern struct Info D_0867006C[];

struct Equip
{
    u16 kind;
    u16 pad_2;
    u16 ids[3];
};

void func_080430D0(struct Equip *equip)
{
    u16 kind = equip->kind;
    u16 i;

    for (i = 0; i <= 2; i++)
    {
        u16 id = D_0867006C[kind].parts[i].id;

        if (id != 0xFFFF)
            equip->ids[i] = id;
        else
            equip->ids[i] = 0;
    }
}
