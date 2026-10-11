#include "types.h"

struct Stats
{
    u8 pad_0[0xC];
    s32 value;
    u8 pad_10[0x1C];
    s32 max;
};

struct Unit
{
    u8 pad_0[8];
    struct Stats stats;
    u8 pad_38[0x294];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

extern struct
{
    u8 pad_0[8];
    struct Side sides[2];
    u8 pad_21B8[0x38];
    u8 refresh;
    u8 pad_21F1[3];
    u8 side;
    u8 unit;
} D_0200EB84;

void func_080335B4(s32, s32, s32, s32);

void func_0803D5A0(void)
{
    struct Side *group;
    struct Stats *stats;
    s32 max;

    func_080335B4(0, 0, 5, 1);
    group = &D_0200EB84.sides[D_0200EB84.side];
    stats = &group->units[D_0200EB84.unit].stats;
    max = stats->max;
    stats->value += max >> 1;
    if (stats->value > max)
        stats->value = max;
    D_0200EB84.refresh = 0xFF;
}
