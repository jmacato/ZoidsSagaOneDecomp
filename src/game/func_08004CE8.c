#include "types.h"

u16 func_08004CE8(u16 *values, u16 count)
{
    u16 total = 0;
    u16 i;

    for (i = 0; i < count; i++)
        total += values[i];
    return total;
}
