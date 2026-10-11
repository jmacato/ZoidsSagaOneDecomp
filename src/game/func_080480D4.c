#include "types.h"

void func_080480D4(u16 second, u16 third, u16 first, u8 mask)
{
    u16 value = *(vu16 *)0x04000052;

    if (mask & 1)
        value = (value & 0xFFE0) | (first & 0x1F);
    if (mask & 2)
        value = (value & 0xFFE0) | (second & 0x1F);
    if (mask & 4)
        value = (value & 0xE0FF) | ((third << 8) & 0x1F00);
    *(vu16 *)0x04000052 = value;
}
