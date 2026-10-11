#include "types.h"

struct Unit
{
    u8 pad_0[8];
    u8 stats[0x10];
    u32 values[6];
    u8 pad_30[0xAC];
    u32 base[6];
    u8 pad_F4[0x1D8];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

extern struct Side D_0200EB8C[];

void func_0802BA24(void *, struct Unit *);

void func_0802F81C(void)
{
    u8 side;
    u8 slot;
    u8 i;

    for (side = 0; side < 2; side++)
    {
        for (slot = 0; slot < 6; slot++)
        {
            struct Side *group = &D_0200EB8C[side];

            for (i = 0; i < 6; i++)
                D_0200EB8C[side].units[slot].values[i] = D_0200EB8C[side].units[slot].base[i];
            func_0802BA24(group->units[slot].stats, &group->units[slot]);
        }
    }
}
