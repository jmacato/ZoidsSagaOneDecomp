#include "m2c.h"

s32 func_08001040(s32);
M2C_UNK func_08008B58(M2C_UNK);

void func_08021D1C(u8 arg0)
{
    s32 var_r0;
    u8 var_r4;

    var_r4 = 3;
    if ((u32) arg0 <= 2U)
    {
        if (func_08001040(0x1BC) != 0)
        {
            var_r4 = 2;
        }
        if (func_08001040(0x1BD) != 0)
        {
            var_r4 -= 1;
        }
        var_r0 = 0x1BE;
    }
    else
    {
        if (func_08001040(0x1BF) != 0)
        {
            var_r4 = 2;
        }
        if (func_08001040(0x1C0) != 0)
        {
            var_r4 -= 1;
        }
        var_r0 = 0x1C1;
    }
    if (func_08001040(var_r0) != 0)
    {
        var_r4 -= 1;
    }
    *(s16 *)0x02007574 = (s16) var_r4;
    func_08008B58(0x2D6);
}
