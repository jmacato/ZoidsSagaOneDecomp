#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_080154FC(void)
{
    func_0805EE78(0x20);
    func_08011F18(0, 0xE0, 0x1C0, 0x10, 1, 0);
    func_08011F18(5, 0xE0, 0x1A0, 0x10, 1, 1);
    func_08008B58(0xC6);
    func_08008B70(1, 0xE, 0x1C);
    func_08011F18(1, 0xD0, 0x1C0, 0x10, 1, 1);
    func_08000BD8(2, 3);
    func_08008B70(2, 0xE, 0x1C);
    func_08011F18(2, 0xF0, 0x1D0, 0x10, 1, 1);
    func_08000BD8(3, 0);
    func_08008B70(3, 0xE, 0x1C);
    func_08011F18(3, 0xF0, 0x1C0, 0x10, 1, 1);
    func_08000BD8(4, 2);
    func_08008B58(0xC7);
    func_08011F18(4, 0xC0, 0x1C0, 0x10, 1, 1);
    func_08001A08(7);
    D_02000B54.f_0 = 0;
    func_080019B4(7);
    func_08008B58(0xC8);
    func_08000BD8(1, 2);
    func_08000BD8(2, 2);
    func_08000BD8(3, 2);
    func_08000BD8(4, 2);
    func_0805EE78(0x1E);
    func_08011F18(4, 0xB0, 0x1C0, 0x10, 1, 1);
    func_08000BD8(5, 3);
    func_08008B58(0xC9);
    func_08011F18(4, 0xB0, 0x1A0, 0x10, 1, 1);
    func_08011F18(4, 0xD0, 0x1A0, 0x10, 1, 1);
    func_08000BD8(6, 2);
    func_08000BD8(1, 0);
    func_08000BD8(2, 0);
    func_08000BD8(3, 0);
    func_08000BD8(4, 0);
    func_08008B58(0xCA);
    func_08011F18(5, 0xE0, 0x150, 0x10, 1, 1);
    func_08008B70(5, 0xFF, 0xFF);
    func_08011F18(4, 0xE0, 0x1A0, 0x10, 1, 1);
    func_08000BD8(5, 1);
    func_08008B58(0xCB);
    func_08011F18(1, 0xE0, 0x1C0, 0x10, 1, 1);
    func_08008B70(1, 0xFF, 0xFF);
    func_08011F18(2, 0xE0, 0x1C0, 0x10, 1, 1);
    func_08008B70(2, 0xFF, 0xFF);
    func_08011F18(3, 0xE0, 0x1C0, 0x10, 1, 1);
    func_08008B70(3, 0xFF, 0xFF);
    func_08011F18(4, 0xE0, 0x1C0, 0x10, 1, 1);
    func_08008B70(4, 0xFF, 0xFF);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0x3D, 0xE, 0x1C, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
