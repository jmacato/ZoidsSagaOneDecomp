#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0801E0F8(void)
{
    func_08008B58(0x1D5);
    func_08011F18(2, 0x240, 0x200, 0x20, 2, 0);
    func_08008B70(2, 0xFF, 0xFF);
    func_08008B58(0x1D6);
    func_08011F18(1, 0x1E0, 0x260, 0x20, 2, 0);
    func_08011F18(1, 0x1E0, 0x200, 0x20, 2, 0);
    func_08008B70(1, 0xFF, 0xFF);
    func_08008B58(0x1D7);
    func_0805EE78(0xF);
    func_08000BD8(4, 1);
    func_0805EE78(0xF);
    func_08008B58(0x1D8);
    func_08003D78(4, 0x0801E1E1);
    func_08011E08();
    func_08003DD8(4);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xB0, 0x11, 0x15, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
