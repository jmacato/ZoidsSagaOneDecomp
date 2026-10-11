#include "types.h"

struct Entry
{
    u16 values[6];
    u16 fallback;
    u8 pad_E[0xE];
};

extern struct Entry D_086E7748[];

u16 func_08045784(u16 index, u8 slot)
{
    u16 value;

    if (D_086E7748[index].values[slot] != 0xFFFF)
        value = D_086E7748[index].values[slot];
    else
        value = D_086E7748[index].fallback;
    return value;
}
