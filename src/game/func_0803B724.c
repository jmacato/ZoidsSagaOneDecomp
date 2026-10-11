#include "types.h"

extern struct
{
    u8 pad_0[0x349C];
    u8 values[1];
} D_02000B5C;

void func_0803B724(u8 value, u8 index)
{
    D_02000B5C.values[index] = value;
}
