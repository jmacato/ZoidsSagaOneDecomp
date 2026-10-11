#include "m2c.h"

M2C_UNK func_08008324(M2C_UNK, s32);
M2C_UNK func_0805EE78(s32);

void func_080235D0(void)
{
    u32 var_r4;

    var_r4 = 0;
    do
    {
        func_08008324(0xFFFF0000, 0);
        func_0805EE78(2);
        var_r4 += 1;
    } while (var_r4 <= 0x20FU);
}
