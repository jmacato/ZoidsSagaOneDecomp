#include "m2c.h"

M2C_UNK func_08044DE8(s32, s32, s32);
M2C_UNK func_0805EE78(s32);

s32 func_08044F0C(void)
{
    s32 var_r4;
    s32 var_r5;

    var_r4 = -0xB00000;
    func_08044DE8(1, -0xB00000, 0);
    var_r5 = 0x2000;
loop_1:
    func_0805EE78(1);
    func_08044DE8(1, var_r4, 0);
    if (var_r4 < 0)
    {
        var_r4 += var_r5;
        var_r5 += 0x4000;
        goto loop_1;
    }
    func_08044DE8(1, 0, 0);
    return 0;
}
