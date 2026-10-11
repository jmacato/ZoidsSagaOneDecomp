#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_08008324(s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08011E08();
M2C_UNK func_0805EE78(s32);

void func_0801C47C(void)
{
    u32 var_r4;

    var_r4 = 0;
    do
    {
        func_08008324(0, 0x20000);
        func_0805EE78(1);
        var_r4 += 1;
    } while (var_r4 <= 0xBFU);
    func_0805EE78(0x20);
    func_08008B58(0x194);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xB1, 0x13, 0x1C, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
