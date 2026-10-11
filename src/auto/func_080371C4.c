#include "m2c.h"

u8 func_080371E8(u32);
M2C_UNK func_08037A88(u32);

void func_080371C4(u32 arg0)
{
    u32 var_r4;
    u8 temp_r0;

    var_r4 = arg0;
    var_r4 <<= 0x18;
    var_r4 = var_r4 >> 0x18;
    temp_r0 = func_080371E8(var_r4);
    if (temp_r0 != 0xFF)
    {
        var_r4 = (u32) temp_r0;
    }
    func_08037A88(var_r4);
}
