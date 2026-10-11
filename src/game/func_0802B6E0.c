#include "types.h"

struct Stats
{
    u8 pad_0[0x32];
    s16 value;
    u8 pad_34[4];
};

struct Unit
{
    u8 pad_0[4];
    struct Stats *source;
    struct Stats stats;
    u8 pad_40[0x90];
    s16 half;
    u16 field_D2;
    u8 pad_D4[0x20];
    u8 first;
    u8 second;
};

void func_0802BA24(struct Stats *, struct Unit *);

void func_0802B6E0(struct Stats *source, struct Unit *unit, u8 first, u8 second)
{
    func_0802BA24(source, unit);
    unit->source = source;
    unit->stats = *source;
    unit->half = source->value >> 1;
    unit->field_D2 = 0;
    unit->first = first;
    unit->second = second;
}
