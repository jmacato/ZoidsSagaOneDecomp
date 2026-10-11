#include "types.h"

struct Unit
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[0x2C2];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Battle
{
    struct Side sides[2];
    u8 pad_21B0[0x40];
    u8 refresh;
};

extern struct Battle D_0200EB84;

extern struct Unit D_0200EB8C[];

u8 func_08032AC4(s32, s32);
s32 func_08032A88(s32, u8);
void func_08032B54(struct Unit *, s32, s32, s32, s32, s32);

void func_0803CA6C(void)
{
    struct Battle *battle = &D_0200EB84;
    u8 *refresh = &battle->refresh;
    u8 target;

    *refresh = 0xFF;
    target = func_08032AC4(0, 0);
    if (target != 0xFF && func_08032A88(0, target) != 0)
    {
        u8 i;

        battle->sides[0].units[target].flags |= 1;
        for (i = 0; i <= 5; i++)
        {
            if (func_08032A88(0, i) != 0)
            {
                struct Unit *unit = &D_0200EB8C[i];

                func_08032B54(unit, 0x11, 0x64, 1, 1, 0);
                func_08032B54(unit, 0x21, 0x64, 1, 1, 0);
                func_08032B54(unit, 0x101, 0x64, 1, 1, 0);
                func_08032B54(unit, 0x801, 0x64, 1, 1, 0);
            }
        }
    }
    else
    {
        *refresh = 1;
    }
}
