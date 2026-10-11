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
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_080157C0(void)
{
    func_0805EE78(0x20);
    func_08003D78(4, 0x0801590D);
    func_08011F18(4, 0x80, 0x50, 0x10, 1, 1);
    func_08008B58(0xCC);
    func_08011F18(0, 0x60, 0x70, 0x10, 1, 0);
    func_08011F18(0, 0x60, 0x50, 0x10, 1, 0);
    func_08008B58(0xCD);
    func_08003D78(4, 0x08015929);
    func_0805EE78(0x10);
    func_08008B70(7, 4, 8);
    func_08011F18(7, 0x40, 0x10, 0x10, 1, 1);
    func_08000BD8(8, 1);
    func_08008B58(0xCE);
    func_08011E08();
    func_0805EE78(0x78);
    func_08008B70(0, 6, 5);
    func_08000BD8(1, 0);
    func_08008B70(1, 5, 5);
    func_08000BD8(2, 0);
    func_08008B70(2, 7, 6);
    func_08000BD8(3, 0);
    func_08008B70(3, 6, 6);
    func_08000BD8(4, 0);
    func_08008B70(6, 5, 1);
    func_08000BD8(7, 1);
    func_08008B70(7, 4, 1);
    func_08000BD8(8, 1);
    func_08011E24();
    func_08008B58(0xCF);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0x42, 8, 7, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
