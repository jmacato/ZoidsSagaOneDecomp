#include "m2c.h"

s32 func_08001040(s32);

u16 func_0804CD18(u8 arg0)
{
    u16 var_r5;
    u32 var_r4;
    u8 temp_r6;

    temp_r6 = arg0;
    var_r4 = 0;
    var_r5 = 0;
    if (func_08001040(0) == 0)
    {
        var_r5 = 1;
    }
    else
    {
        var_r4 = 1;
    }
    if ((func_08001040(5) == 0) && ((u32) temp_r6 >= var_r4))
    {
        var_r5 += 1;
    }
    else
    {
        var_r4 = (u32) (u16) (var_r4 + 1);
    }
    if ((func_08001040(0xA) == 0) && ((u32) temp_r6 >= var_r4))
    {
        var_r5 += 1;
    }
    else
    {
        var_r4 = (u32) (u16) (var_r4 + 1);
    }
    if ((func_08001040(0xF) == 0) && ((u32) temp_r6 >= var_r4))
    {
        var_r5 += 1;
    }
    else
    {
        var_r4 = (u32) (u16) (var_r4 + 1);
    }
    if ((func_08001040(0x19) == 0) && ((u32) temp_r6 >= var_r4))
    {
        var_r5 += 1;
    }
    return (u16) (var_r5 + temp_r6);
}
