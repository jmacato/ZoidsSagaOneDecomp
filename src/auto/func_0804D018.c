#include "m2c.h"

u16 func_0804D018(s32 arg0, u16 arg1)
{
    u16 var_r1;

    var_r1 = arg1;
    do
    {
        if (var_r1 != 0)
        {
            var_r1 -= 1;
        }
        else
        {
            var_r1 = 0x13;
        }
    } while (*(s32 *)((var_r1 * 4) + arg0) == 0);
    return var_r1;
}
