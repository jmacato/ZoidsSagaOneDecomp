#include "types.h"

struct Part
{
    u32 flags;
    u8 pad_4[0x10];
};

struct Attack
{
    s16 accuracy;
    u8 pad_2[2];
    s32 power;
};

struct Attacker
{
    u16 flags;
    u8 pad_2[0x4E];
    struct Part parts[6];
    u8 pad_C8[0x2C];
    u8 side;
    u8 pad_F5[0x1B];
    struct Attack attacks[6];
};

struct Defender
{
    u16 flags;
    u8 pad_2[6];
    u16 status;
    u8 pad_A[0xF6];
    s16 evasion;
    u8 pad_102[0x40];
    s16 bonus;
};

struct Side
{
    u8 pad_0[0x10D1];
    u8 terrain;
    u8 pad_10D2[6];
};

extern struct
{
    struct Side sides[2];
    u8 pad_21B0[0xEC];
    u16 overflow;
} D_0200EB84;

s32 func_080346C0(s32, s16);

u16 func_08034500(struct Attacker *attacker, struct Defender *defender, u8 part)
{
    s32 chance = func_080346C0(defender->evasion, 1);
    s32 min = 50;

    if ((defender->status & 2) && !(attacker->parts[part].flags & 0x200))
        chance += 20;
    if ((defender->status & 4) && D_0200EB84.sides[attacker->side].terrain == 6)
        chance += 20;
    chance += defender->bonus;
    chance = attacker->attacks[part].accuracy - chance;
    if (chance > 99)
        D_0200EB84.overflow = chance - 100;
    if (chance < min)
        chance = 50;
    else if (chance >= 100)
        chance = 99;
    if (attacker->flags & 4)
        chance = 100;
    if (defender->flags & 2)
        chance = 0;
    if (attacker->parts[part].flags & 0x40000800)
        chance = 100;
    return chance;
}
