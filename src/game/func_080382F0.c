#include "types.h"

extern u16 D_0300235A;

void func_080382F0(u8 *value, u8 max)
{
    if (D_0300235A & 0x200)
    {
        if (*value != 0)
            *value = *value - 1;
    }
    else if (D_0300235A & 0x100)
    {
        if (*value < max)
            *value = *value + 1;
    }
}
