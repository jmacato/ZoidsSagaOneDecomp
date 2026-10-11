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

struct Stats
{
    u16 flags;
    u8 pad_2[6];
    s32 value;
    u8 pad_C[0x1C];
    s32 base;
    u8 pad_2C[0x2A0];
};

extern struct Battle D_0200EB84;
extern struct Stats D_0200FC6C[];

u8 func_08032AC4(s32, s32);
s32 func_08032A88(s32, u8);

void func_0803D31C(void)
{
    struct Battle *battle = &D_0200EB84;
    u8 *refresh = &battle->refresh;
    u8 target;

    *refresh = 0xFF;
    target = func_08032AC4(1, 0);
    if (target != 0xFF && func_08032A88(1, target) != 0)
    {
        u8 i;

        battle->sides[1].units[target].flags |= 1;
        for (i = 0; i <= 5; i++)
        {
            if (func_08032A88(1, i) != 0)
            {
                struct Stats *stats = &D_0200FC6C[i];

                stats->flags &= 0xBFFF;
                stats->value = stats->base;
            }
        }
    }
    else
    {
        *refresh = 1;
    }
}
