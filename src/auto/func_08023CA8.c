#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037450(s32);

void func_08023CA8(void)
{
    func_08011E24();
    func_08008B58(0x24F);
    func_08011F18(5, 0xC0, 0x1E0, 0x10, 1, 1);
    func_08008B70(5, 0xFF, 0xFF);
    func_08008B58(0x250);
    func_08011F18(1, 0x130, 0x1F0, 0x10, 2, 0);
    func_08000BD8(2, 3);
    func_08008B58(0x251);
    func_08011F18(4, 0x1A0, 0x1A0, 0x10, 1, 1);
    func_08008B70(4, 0xFF, 0xFF);
    func_08008B58(0x252);
    func_08011E08();
    func_080076C0(0xF5, 0x18, 0x11, 5, 0x0866AE30);
    func_08001A08(4);
    D_02000B54.f_0 = 0;
    func_080019B4(4);
    func_08008B70(0, 0x18, 0x11);
    func_08011E24();
    func_08008B58(0x253);
    func_08037450(0x1D);
    func_08037450(0x1E);
    func_08011E08();
    func_080076C0(0xF4, 9, 0xA, 0xF, 0x0866AE94);
    func_08001A08(4);
    D_02000B54.f_0 = 0;
    func_080019B4(4);
    func_08008B70(0, 8, 0x14);
    func_08011E24();
    func_08008B58(0x255);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xF3, 0xA, 5, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
