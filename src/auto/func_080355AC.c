#include "m2c.h"

s32 func_080355AC(u8 arg0)
{
    s32 var_r2;
    u8 temp_r1;

    var_r2 = 0;
    temp_r1 = arg0;
    if (((u32) ((u32) ((arg0 << 0x18) + 0xFC000000) >> 0x18) <= 1U) || (temp_r1 == 0) || (temp_r1 == 1) || (temp_r1 == 2))
    {
        var_r2 = 1;
    }
    return var_r2;
}
