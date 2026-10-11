#include "m2c.h"

u8 func_080388A4();

s32 func_080386EC(void)
{
    s32 var_r4;

    var_r4 = 1;
    if ((u32) func_080388A4() > 4U)
    {
        var_r4 = 0;
    }
    return var_r4;
}
