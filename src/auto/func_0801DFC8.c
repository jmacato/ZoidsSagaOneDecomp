#include "m2c.h"

M2C_UNK func_08003DD8(u8);
M2C_UNK func_08008324(s32, M2C_UNK);
M2C_UNK func_0805EE78(s32);

void func_0801DFC8(void)
{
    u32 var_r4;

    var_r4 = 0;
    do
    {
        func_08008324(0, 0xFFFF0000);
        func_0805EE78(1);
        var_r4 += 1;
    } while (var_r4 <= 0x8FU);
    func_08003DD8(*(u8 *)0x02000030);
}
