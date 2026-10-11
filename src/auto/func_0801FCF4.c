#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0801FCF4(void)
{
    func_0805EE78(0x20);
    func_08003D78(4, 0x0801FF2D);
    func_0805EE78(0x10);
    func_08003D78(5, 0x0801FF49);
    func_0805EE78(0x10);
    func_08003D78(6, 0x0801FF71);
    func_0805EE78(0x10);
    func_08003D78(7, 0x0801FFBD);
    func_0805EE78(0x10);
    func_08003D78(8, 0x08020009);
    func_0805EE78(0x10);
    func_08008B70(7, 7, 8);
    func_08011F18(7, 0x70, 0x60, 0x10, 1, 0);
    func_08011F18(7, 0x50, 0x60, 0x10, 1, 0);
    func_08011F18(7, 0x50, 0x30, 0x10, 1, 0);
    func_08000BD8(8, 3);
    func_0805EE78(0x3C);
    func_08003D78(4, 0x0802005D);
    func_08008B70(6, 8, 8);
    func_08011F18(6, 0x80, 0x70, 0x10, 1, 0);
    func_08011F18(6, 0x90, 0x70, 0x10, 1, 0);
    func_08000BD8(7, 2);
    func_08008B70(8, 7, 8);
    func_0805EE78(0xF);
    func_08011F18(8, 0x70, 0x60, 0x10, 1, 0);
    func_08003D78(4, 0x080200A1);
    func_08003D78(5, 0x080200DD);
    func_08000BD8(1, 1);
    func_08000BD8(2, 1);
    func_08000BD8(3, 1);
    func_08000BD8(4, 1);
    func_08000BD8(5, 1);
    func_08000BD8(8, 1);
    func_08008B58(0x202);
    func_08001A08(6);
    D_02000B54.f_0 = 0;
    func_080019B4(6);
    func_08011F18(4, 0xA0, 0x70, 0x10, 1, 0);
    func_08011F18(4, 0x80, 0x70, 0x10, 1, 0);
    func_08011F18(4, 0x80, 0x80, 0x10, 1, 0);
    func_08008B70(4, 0xFF, 0xFF);
    func_08008B58(0x203);
    func_08001A08(0x16);
    D_02000B54.f_0 = 0;
    func_080019B4(0x16);
    func_0805EE78(0xF);
    func_08008B70(4, 8, 8);
    func_08000BD8(5, 0);
    func_0805EE78(0xF);
    func_08000BD8(9, 1);
    func_0805EE78(0xF);
    func_08008B58(0x204);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xDD, 7, 8, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
