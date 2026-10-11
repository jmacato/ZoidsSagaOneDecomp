#include "types.h"

struct Entry
{
    u16 values[6];
    u16 fallback;
    u16 values_2[6];
    u16 fallback_2;
};

extern struct Entry D_086E7748[];

u16 func_080457BC(u16 index, u8 slot)
{
    u16 value;

    if (D_086E7748[index].values_2[slot] != 0xFFFF)
        value = D_086E7748[index].values_2[slot];
    else
        value = D_086E7748[index].fallback_2;
    return value;
}
