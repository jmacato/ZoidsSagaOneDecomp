#include "types.h"

struct Effect
{
    u16 kind;
    u16 value;
    u8 power;
    u8 turns;
    u16 source;
};

struct Unit
{
    u8 pad_0[0x144];
    struct Effect effects[0x30];
};

u8 func_08032B54(struct Unit *unit, u16 kind, u16 value, u8 power, u8 turns, u16 source)
{
    u8 result = 0xFF;
    u8 i;

    for (i = 0; i <= 0x2F; i++)
    {
        if (unit->effects[i].turns == 0)
        {
            unit->effects[i].kind = kind;
            unit->effects[i].value = value;
            unit->effects[i].power = power;
            unit->effects[i].turns = turns;
            unit->effects[i].source = source;
            result = i;
            break;
        }
    }
    return result;
}
