#include "types.h"

struct Weapon
{
    u32 flags;
    u16 value;
    u8 pad_6[2];
    u16 attributes;
    u8 pad_A[0xA];
};

struct WeaponState
{
    u16 charge;
    u16 target;
};

struct Unit
{
    u8 pad_0[8];
    u16 attributes;
    u8 pad_A[0x46];
    struct Weapon weapons[6];
    u8 pad_C8[8];
    u16 value;
    u8 pad_D2[0xA];
    struct WeaponState weapon_states[6];
};

extern void func_08033A34(struct Unit *unit, u8 index);

void func_0803376C(struct Unit *unit)
{
    u8 index;

    for (index = 0; index <= 5; index++)
    {
        if (unit->weapons[index].flags & 0x20000000)
        {
            if (unit->weapons[index].flags & 0xC000)
                unit->value += unit->weapons[index].value;
            if (unit->weapons[index].flags & 0x200000)
            {
                u8 *source = (u8 *)&unit->weapons[0].attributes;
                u16 attributes;

                /* Keep the field address separate from the stride for the ROM match. */
                asm("" : "+r"(source));
                source += index * sizeof(struct Weapon);
                attributes = *(u16 *)source;

                attributes &= 0x3E;
                attributes |= unit->attributes;
                unit->attributes = attributes;
            }
            func_08033A34(unit, index);
            unit->weapon_states[index].charge = 0;
            unit->weapon_states[index].target = 0xFFFF;
        }
    }
}
