#include "types.h"

struct Slot
{
    u16 pad_0;
    u16 id;
    u8 pad_4[0x10];
};

struct Slots
{
    u8 pad_0[0x60];
    struct Slot slots[6];
};

s32 func_08033DCC(struct Slots *slots)
{
    s32 found = 0;
    u8 i;

    for (i = 0; i <= 5; i++)
    {
        if (slots->slots[i].id != 0xFFFF)
        {
            found = 1;
            break;
        }
    }
    return found;
}
