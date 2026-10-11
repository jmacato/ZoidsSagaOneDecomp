#include "types.h"

struct Entry
{
    u32 flags;
    u8 pad_4[0x10];
};

struct Attacker
{
    u8 pad_0[0x50];
    struct Entry entries[8];
};

s32 region_0803470C(struct Attacker *attacker, u8 slot)
{
    s32 result = 0;
    u32 flags = attacker->entries[slot].flags;

    if (flags & 1)
    {
        if (!(flags & 0x800))
            result = 1;
    }
    return result;
}
