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
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037424(s32);
M2C_UNK func_08037450(s32);
M2C_UNK func_0805EE78(s32);

void func_08015BEC(void)
{
    func_0805EE78(0x20);
    func_08008B58(0xDF);
    func_08011E08();
    func_080076C0(0x37, 0x1E, 0x1C, 0xD, 0x086677FC);
    func_08008B70(0, 0x1E, 0x1E);
    func_08011E24();
    func_08003D78(4, 0x08015E35);
    func_08011F18(2, 0x1F0, 0x1D0, 0x10, 1, 1);
    func_08011F18(2, 0x200, 0x1D0, 0x10, 1, 1);
    func_08000BD8(3, 0);
    func_08008B58(0xE0);
    func_08001A08(7);
    D_02000B54.f_0 = 0;
    func_080019B4(7);
    func_08008B70(0xA, 0x1E, 0x1B);
    func_08011F18(0xA, 0x1E0, 0x1C0, 0x10, 1, 1);
    func_08011F18(0xA, 0x1F0, 0x1C0, 0x10, 1, 1);
    func_08000BD8(0xB, 1);
    func_08008B70(0xB, 0x1E, 0x1B);
    func_08011F18(0xB, 0x1E0, 0x1C0, 0x10, 1, 1);
    func_08008B58(0xE1);
    func_08008B70(0xC, 0x1E, 0x1B);
    func_08011F18(0xB, 0x1D0, 0x1C0, 0x10, 1, 1);
    func_08000BD8(0xC, 1);
    func_08011F18(0xC, 0x1E0, 0x1C0, 0x10, 1, 1);
    func_08008B58(0xE2);
    func_08011E08();
    func_080076C0(0x39, 0xF, 0xE, 0xA, 0x08667900);
    func_08008B70(0, 2, 2);
    func_08011E24();
    func_08008B58(0xE3);
    func_08003D78(4, 0x08015E55);
    func_08011F18(3, 0x20, 0x20, 0x10, 1, 1);
    func_08008B70(3, 0xFF, 0xFF);
    func_08011F18(2, 0x20, 0x20, 0x10, 1, 1);
    func_08008B70(2, 0xFF, 0xFF);
    func_08003D78(5, 0x08015E79);
    func_08003D78(4, 0x08015EA9);
    func_08003D78(5, 0x08015EE1);
    func_08011F18(9, 0x20, 0x10, 0x10, 1, 1);
    func_08011F18(9, 0x20, 0x20, 0x10, 1, 1);
    func_08008B70(9, 0xFF, 0xFF);
    func_08037424(6);
    func_08037424(7);
    func_08037450(4);
    func_08037450(3);
    func_08037450(5);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0x36, 0xF, 0xE, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
