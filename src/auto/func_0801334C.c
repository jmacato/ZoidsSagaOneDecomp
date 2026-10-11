#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0801334C(void)
{
    func_0805EE78(0x20);
    func_08011F18(0, 0xC0, 0x130, 0x10, 1, 0);
    func_0805EE78(0x1E);
    func_08000BD8(1, 3);
    func_0805EE78(0x3C);
    func_08000BD8(1, 2);
    func_0805EE78(0x3C);
    func_08000BD8(1, 0);
    func_0805EE78(0x3C);
    func_08008B58(0x7F);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0x22, 0xC, 0x13, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
