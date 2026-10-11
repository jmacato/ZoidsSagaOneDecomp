#include "m2c.h"

M2C_UNK func_08008324(s32, s32);
M2C_UNK func_0805EE78(s32);

void func_08024408(void)
{
    u32 var_r4;

    var_r4 = 0;
    do
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
        var_r4 += 1;
    } while (var_r4 <= 0x1FU);
}
