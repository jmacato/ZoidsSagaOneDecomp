#include "types.h"

extern u16 D_02000B54;

s32 func_0805BCA0(u16);

s32 func_080019B4(u16 value)
{
    if (value != D_02000B54)
    {
        s32 result = func_0805BCA0(value);

        D_02000B54 = value;
        return result;
    }
}
