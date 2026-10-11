#include "types.h"

struct MainStats32
{
    s32 hp;
    s32 energy;
    s16 evasion;
    s16 armor;
};
struct Tuning32
{
    s16 pad_0;
    s16 evasion;
    s16 armor;
    s16 power;
    s16 accuracy;
    s16 pad_A;
};
struct Part32
{
    u32 flags;
    s16 accuracy;
    u16 pad_6;
    s32 power;
    u8 pad_C[8];
};
struct Attack32
{
    s16 accuracy;
    u16 pad_2;
    s32 power;
};
struct Effect32
{
    u16 flags;
    u16 value;
    u8 mode;
    u8 turns;
    u16 source;
};
struct Unit32
{
    u16 flags;
    u8 pad_2[6];
    u16 status;
    u8 pad_A[0x26];
    struct MainStats32 base_stats;
    u8 pad_3C[8];
    struct Tuning32 base_tuning;
    struct Part32 parts[6];
    u8 pad_C8[8];
    s16 base_shield;
    s16 base_bonus;
    u8 pad_D4[0x24];
    struct MainStats32 stats;
    struct Tuning32 tuning;
    struct Attack32 attacks[6];
    s16 shield;
    s16 bonus;
    struct Effect32 effects[48];
    u8 pad_2C4[8];
};

s32 func_080346C0(s32, s32);

#define FLAT32(mask, field) \
    if (unit->effects[i].flags & (mask)) \
    { \
        if (unit->effects[i].flags & 1) \
            (field) += unit->effects[i].value; \
        else \
            (field) -= unit->effects[i].value; \
    }
#define PERCENT32(mask, field) \
    if (unit->effects[i].flags & (mask)) \
    { \
        delta = func_080346C0((field), unit->effects[i].value); \
        if (unit->effects[i].flags & 1) \
            (field) += delta; \
        else \
            (field) -= delta; \
    }

void func_08032CA4(struct Unit32 *unit)
{
    u8 i;
    u8 j;
    s32 delta;

    unit->stats = unit->base_stats;
    unit->shield = unit->base_shield;
    unit->bonus = unit->base_bonus;
    unit->tuning = unit->base_tuning;
    for (j = 0; j <= 5; j++)
    {
        unit->attacks[j].accuracy = unit->parts[j].accuracy;
        unit->attacks[j].power = unit->parts[j].power;
    }
    for (i = 0; i <= 47; i++)
    {
        if (unit->effects[i].turns != 0)
        {
            switch (unit->effects[i].mode)
            {
            case 2:
            {
                FLAT32(0x300, unit->stats.armor);
                FLAT32(0x500, unit->shield);
                FLAT32(0x800, unit->stats.evasion);
                FLAT32(0x8000, unit->bonus);
                if (unit->effects[i].flags & 0x10)
                    for (j = 0; j <= 5; j++)
                    {
                        if (unit->effects[i].flags & 1)
                            unit->attacks[j].power += unit->effects[i].value;
                        else
                            unit->attacks[j].power -= unit->effects[i].value;
                    }
                if (unit->effects[i].flags & 0x20)
                    for (j = 0; j <= 5; j++)
                    {
                        if (unit->effects[i].flags & 1)
                            unit->attacks[j].accuracy += unit->effects[i].value;
                        else
                            unit->attacks[j].accuracy -= unit->effects[i].value;
                    }
                break;
            }
            case 3:
            {
                if (unit->effects[i].flags & 0x100)
                {
                    if (unit->effects[i].flags & 1)
                    {
                        unit->tuning.armor += unit->effects[i].value;
                        unit->shield += unit->effects[i].value;
                    }
                    else
                    {
                        unit->tuning.armor -= unit->effects[i].value;
                        unit->shield -= unit->effects[i].value;
                    }
                }
                FLAT32(0x800, unit->tuning.evasion);
                FLAT32(0x10, unit->tuning.power);
                FLAT32(0x20, unit->tuning.accuracy);
                break;
            }
            }
        }
    }
    for (i = 0; i <= 47; i++)
    {
        if (unit->effects[i].turns != 0)
        {
            switch (unit->effects[i].mode)
            {
            case 0:
            {
                PERCENT32(0x300, unit->stats.armor);
                PERCENT32(0x500, unit->shield);
                PERCENT32(0x800, unit->stats.evasion);
                if (unit->effects[i].flags & 0x10)
                    for (j = 0; j <= 5; j++)
                    {
                        delta = func_080346C0(unit->attacks[j].power, unit->effects[i].value);
                        if (unit->effects[i].flags & 1)
                            unit->attacks[j].power += delta;
                        else
                            unit->attacks[j].power -= delta;
                    }
                if (unit->effects[i].flags & 0x20)
                    for (j = 0; j <= 5; j++)
                    {
                        delta = func_080346C0(unit->attacks[j].accuracy, unit->effects[i].value);
                        if (unit->effects[i].flags & 1)
                            unit->attacks[j].accuracy += delta;
                        else
                            unit->attacks[j].accuracy -= delta;
                    }
                break;
            }
            case 1:
            {
                PERCENT32(0x100, unit->tuning.armor);
                PERCENT32(0x800, unit->tuning.evasion);
                PERCENT32(0x10, unit->tuning.power);
                PERCENT32(0x20, unit->tuning.accuracy);
                break;
            }
            }
        }
    }
    for (i = 0; i <= 47; i++)
    {
        if (unit->effects[i].turns != 0)
        {
            if (unit->effects[i].flags & 0x1000)
                unit->status |= 0x8000;
            if (unit->effects[i].flags & 0x2000)
                unit->flags |= 0x10;
            if (unit->effects[i].flags & 0x4000)
                unit->flags |= 0x20;
        }
    }
    if (unit->stats.armor < 0)
        unit->stats.armor = 0;
    if (unit->stats.evasion < 0)
        unit->stats.evasion = 0;
    for (j = 0; j <= 5; j++)
    {
        if (unit->attacks[j].power < 0)
            unit->attacks[j].power = 0;
        if (unit->attacks[j].accuracy < 0)
            unit->attacks[j].accuracy = 0;
    }
    if (unit->tuning.armor < 0)
        unit->tuning.armor = 0;
    if (unit->shield < 0)
        unit->shield = 0;
    if (unit->bonus < 0)
        unit->bonus = 0;
    if (unit->tuning.evasion < 0)
        unit->tuning.evasion = 0;
    if (unit->tuning.power < 0)
        unit->tuning.power = 0;
    if (unit->tuning.accuracy < 0)
        unit->tuning.accuracy = 0;
    if (!(unit->flags & 0x10))
    {
        delta = func_080346C0(unit->stats.armor, unit->tuning.armor);
        unit->stats.armor += delta;
        delta = func_080346C0(unit->shield, unit->tuning.armor);
        unit->shield += delta;
        delta = func_080346C0(unit->stats.evasion, unit->tuning.evasion);
        unit->stats.evasion += delta;
        for (j = 0; j <= 5; j++)
        {
            delta = func_080346C0(unit->attacks[j].power, unit->tuning.power);
            unit->attacks[j].power += delta;
            delta = func_080346C0(unit->attacks[j].accuracy, unit->tuning.accuracy);
            unit->attacks[j].accuracy += delta;
        }
    }
}
