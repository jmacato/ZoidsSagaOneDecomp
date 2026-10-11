#include "m2c.h"

s32 func_0805D484(s32, s32);
s32 func_0805D4FC(s32, s32);

s32 func_08034A78(s32 arg0)
{
    s32 var_r4;

    var_r4 = arg0;
    if (func_0805D4FC(arg0, 0x14) != 0)
    {
        var_r4 = func_0805D484(var_r4, 0x14);
        var_r4 *= 0x14;
        var_r4 += 0x14;
    }
    return var_r4;
}
