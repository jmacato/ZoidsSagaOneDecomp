#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008324(s32, s32);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_0805EE78(s32);

void func_08023134(void)
{
    u32 var_r4;
    u32 var_r4_2;

    var_r4 = 0;
    do
    {
        func_08008324(0, 0x40000);
        func_0805EE78(1);
        var_r4 += 1;
    } while (var_r4 <= 0x4FU);
    func_0805EE78(0x3C);
    var_r4_2 = 0;
    do
    {
        func_08008324(0, 0xFFFC0000);
        func_0805EE78(1);
        var_r4_2 += 1;
    } while (var_r4_2 <= 0x4FU);
    func_08008B58(0x23E);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x0802319D;
loop_5:
    func_0805EE78(1);
    goto loop_5;
}
