#include "types.h"

struct Slot
{
    u16 field_0;
    u16 item;
};

struct Unit
{
    u8 pad_0[0x10];
    struct Slot slots[8];
};

struct Save
{
    u8 pad_0[0x334C];
    u8 counts[0x96];
};

extern struct Save D_02000B5C;

void func_08037578(struct Unit *unit, u8 slot)
{
    u16 item = unit->slots[slot].item;

    unit->slots[slot].item = 0xFFFF;
    if (item <= 0x95)
    {
        struct Save *save = &D_02000B5C;
        u8 *counts = save->counts;
        u8 *count = &counts[item];

        if (++*count > 9)
            *count = 9;
    }
}
