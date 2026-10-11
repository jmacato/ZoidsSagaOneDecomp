#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_08011E08();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0801FC8C(void)
{
    func_08011F18(1, 0xE0, 0x100, 0x20, 1, 1);
    func_08000BD8(2, 1);
    func_0805EE78(0x20);
    func_08008B58(0x201);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xDD, 7, 9, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
