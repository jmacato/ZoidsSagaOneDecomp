#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

s32 func_08001040(s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08011E08();
M2C_UNK func_0805EE78(s32);

void func_08015F18(void)
{
    func_0805EE78(0x20);
    if (func_08001040(0x164) != 0)
    {
        func_08008B58(0xDE);
    }
    else
    {
        func_08008B58(0xDD);
    }
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0x32, 0xA, 0xF, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
