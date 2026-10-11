#include "types.h"

struct Stats
{
    u8 pad_0[0xC];
    s32 hp;
    u8 pad_10[0x1C];
    s32 max_hp;
};

struct Unit
{
    u16 flags;
    u8 pad_2[6];
    struct Stats stats;
    u8 pad_38[0x294];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Turn
{
    u8 side;
    u8 slot;
    u8 pad_2[2];
};

extern struct
{
    u8 pad_0[8];
    struct Side sides[2];
    u8 pad_21B8[0x38];
    u8 result;
    u8 pad_21F1[3];
    struct Turn turns[6];
} D_0200EB84;

void func_080335B4(u8, u8, u8, u16);

void func_0803D604(void)
{
    struct Stats *stats;
    struct Side *group;

    func_080335B4(1, 0, 5, 1);
    group = &D_0200EB84.sides[D_0200EB84.turns[0].side];
    stats = &group->units[D_0200EB84.turns[0].slot].stats;
    stats->hp += stats->max_hp >> 1;
    if (stats->hp > stats->max_hp)
        stats->hp = stats->max_hp;
    D_0200EB84.result = 0xFF;
}

void func_0803D668(void)
{
    D_0200EB84.sides[D_0200EB84.turns[0].side].units[D_0200EB84.turns[0].slot].flags |= 2;
    D_0200EB84.result = 0xFF;
}
