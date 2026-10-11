#include "types.h"

extern u16 D_0300239C[];

s32 func_08009AD4(u16 value, u16 pos)
{
    D_0300239C[pos] = ((value >> 12) & 0xF) + 2;
    D_0300239C[pos + 1] = ((value >> 8) & 0xF) + 2;
    D_0300239C[pos + 2] = ((value >> 4) & 0xF) + 2;
    D_0300239C[pos + 3] = (value & 0xF) + 2;
}
