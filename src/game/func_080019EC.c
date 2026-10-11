#include "types.h"

extern u16 D_02000B56;

s32 func_0805BCA0(u16);

s32 func_080019EC(u16 value)
{
    s32 result = func_0805BCA0(value);

    D_02000B56 = value;
    return result;
}
