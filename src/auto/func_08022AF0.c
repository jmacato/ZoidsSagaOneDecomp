#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037424(s32);
M2C_UNK func_0805EE78(s32);

void func_08022AF0(void)
{
    func_08011E08();
    func_080076C0(0xED, 4, 0x14, 2, 0x0866A980);
    func_08011E24();
    func_08011F18(1, 0x80, 0x260, 0x20, 1, 1);
    func_0805EE78(0xF);
    func_08000BD8(1, 0);
    func_0805EE78(0xF);
    func_08008B58(0x232);
    func_08011F18(1, 0x80, 0x280, 0x20, 1, 1);
    func_08008B70(1, 0xFF, 0xFF);
    func_08037424(0x1C);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xED, 4, 0x14, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
