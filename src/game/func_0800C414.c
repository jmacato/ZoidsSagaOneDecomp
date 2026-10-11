#include "types.h"

extern u16 D_02000B54;

s32 func_08003590(u8);

s32 func_0800C414(s32 value)
{
    u16 saved = D_02000B54;
    s32 result = func_08003590((u8)value);

    D_02000B54 = saved;
    return result;
}
