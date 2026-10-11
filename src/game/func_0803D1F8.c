#include "types.h"

struct Stats
{
    u8 pad_0[0x28];
    s32 value;
    u8 pad_2C[0x2A0];
};

extern struct
{
    u8 pad_0[0x21F0];
    u8 refresh;
} D_0200EB84;

extern struct Stats D_0200EB94[];

s32 func_08032A88(u8, u8);
void func_080395E8(s32, void *);

void func_0803D1F8(void)
{
    u8 i;

    for (i = 0; i <= 5; i++)
    {
        if (func_08032A88(0, i))
        {
            struct Stats *stats = &D_0200EB94[i];

            func_080395E8(stats->value >> 2, stats);
        }
    }
    D_0200EB84.refresh = 0xFF;
}
