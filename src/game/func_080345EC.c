#include "types.h"

struct Part
{
    u32 flags;
    u8 pad_4[0x10];
};

struct Attack
{
    s32 power;
    s32 field_4;
};

struct Attacker
{
    u8 pad_0[0x50];
    struct Part parts[6];
    u8 pad_C8[0x4C];
    struct Attack attacks[6];
};

struct Defender
{
    u16 flags;
    u8 pad_2[6];
    u16 status;
    u8 pad_A[0xF8];
    u16 armor;
    u8 pad_104[0x3C];
    u16 shield;
};

extern struct
{
    u8 pad_0[0x229E];
    u16 overflow;
} D_0200EB84;

s32 func_080346C0(s32, s16);

s32 func_080345EC(struct Attacker *attacker, struct Defender *defender, u8 part, u16 flags)
{
    u16 armor;
    s32 bonus;
    s32 power;
    s32 damage;

    if (attacker->parts[part].flags & 0x30)
        armor = defender->shield;
    else
        armor = defender->armor;
    if (armor > 0x41)
    {
        armor = 0x41;
        D_0200EB84.overflow = defender->armor - 0x41;
    }
    if ((flags & 2) || (attacker->parts[part].flags & 0x400))
        armor = 0;
    bonus = 0;
    if (flags & 2)
        bonus = func_080346C0(attacker->attacks[part].power, 0x32);
    power = attacker->attacks[part].power + bonus;
    bonus = func_080346C0(power, armor);
    damage = power - bonus;
    if (defender->status & 0x100)
        damage >>= 1;
    if (damage == 0)
        damage = 1;
    if (defender->flags & 0x20)
        damage = 0;
    return damage;
}
