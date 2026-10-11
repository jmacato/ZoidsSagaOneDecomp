#include "m2c.h"

s32 func_080395E8(s32 arg0, u8 *arg1)
{
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r2;
    s32 var_r3;
    s32 var_r4;

    var_r3 = arg0;
    temp_r2 = M2C_FIELD(arg1, s32 *, 0x28);
    temp_r0 = M2C_FIELD(arg1, s32 *, 8);
    var_r4 = temp_r2 - temp_r0;
    temp_r0_2 = temp_r0 + var_r3;
    M2C_FIELD(arg1, s32 *, 8) = temp_r0_2;
    if (temp_r0_2 > temp_r2)
    {
        var_r3 = var_r4;
        M2C_FIELD(arg1, s32 *, 8) = temp_r2;
    }
    return var_r3;
}
