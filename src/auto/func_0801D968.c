#include "m2c.h"

M2C_UNK func_0805EE78(s32);

void func_0801D968(void)
{
    u32 var_r4;

    var_r4 = 0;
    do
    {
        *(s16 *)0x03002356 = 0xF - var_r4;
        func_0805EE78(2);
        var_r4 += 1;
    } while (var_r4 <= 0xFU);
    *(s32 *)0x03000204 = 0x0801D931;
    func_0805EE78(1);
}
