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

void func_0801CE90(void)
{
    func_0805EE78(0x20);
    func_08003D78(4, 0x0801D0D9);
    func_0805EE78(0x10);
    func_08003D78(5, 0x0801D129);
    func_0805EE78(0x10);
    func_08003D78(6, 0x0801D179);
    func_0805EE78(0x10);
    func_08008B70(3, 2, 8);
    func_08011F18(3, 0x20, 0x50, 0x10, 1, 1);
    func_08011F18(3, 0x70, 0x50, 0x10, 1, 1);
    func_08011F18(3, 0x70, 0x40, 0x10, 1, 1);
    func_08000BD8(4, 3);
    func_0805EE78(0xF);
    func_08000BD8(5, 2);
    func_0805EE78(0xF);
    func_08008B58(0x1AB);
    func_0805EE78(0xF);
    func_08000BD8(5, 1);
    func_0805EE78(0xF);
    func_08003D78(4, 0x0801CFF5);
    func_08003D78(6, 0x0801D08D);
    func_0805EE78(8);
    func_08003D78(5, 0x0801D041);
    func_08011F18(0, 0x80, 0x50, 0x10, 2, 0);
    func_08011F18(0, 0x20, 0x50, 0x10, 2, 0);
    func_08011F18(0, 0x20, 0x80, 0x10, 2, 0);
    func_08008B70(0, 0xFF, 0xFF);
    func_08008B58(0x1AC);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xB6, 0x15, 9, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
