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
M2C_UNK func_08008324(s32, s32);
M2C_UNK func_080089A0(s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_080173E0(void)
{
    u32 var_r4;

    func_0805EE78(0x20);
    func_08011F18(2, 0x80, 0x30, 0x10, 1, 1);
    func_08008B58(0xFC);
    func_08011F18(2, 0x80, 0xC0, 0x10, 1, 1);
    func_08008B70(2, 0xFF, 0xFF);
    func_08008B58(0xFD);
    func_08011E08();
    func_080076C0(0x7B, 4, 1, 4, 0x08667FF4);
    func_08001A08(4);
    D_02000B54.f_0 = 0;
    func_080019B4(4);
    func_08008B70(0, 0xFF, 0xFF);
    func_08011E24();
    func_08011F18(1, 0x80, 0x60, 0x20, 1, 1);
    func_08000BD8(2, 0);
    func_0805EE78(0x3C);
    func_08000BD8(3, 2);
    var_r4 = 0;
    do
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
        var_r4 += 1;
    } while (var_r4 <= 0x3FU);
    func_08008B58(0xFE);
    func_08011F18(1, 0x80, 0xE0, 0x20, 2, 1);
    func_08008B70(1, 0xFF, 0xFF);
    func_08011E08();
    func_080076C0(0x81, 2, 5, 4, 0x08668044);
    func_08011E24();
    func_08003D78(4, 0x08017609);
    func_0805EE78(0x3C);
    func_08008B70(3, 0xE, 2);
    func_08011F18(3, 0x50, 0x20, 0x10, 1, 1);
    func_08011F18(3, 0x50, 0x30, 0x10, 1, 1);
    func_08000BD8(4, 1);
    func_08000BD8(1, 0);
    func_08008B58(0xFF);
    func_080089A0(1, 0x98);
    func_08000BD8(1, 3);
    func_08011F18(0, 0x20, 0x40, 0x10, 1, 0);
    func_08011F18(1, 0x10, 0x40, 0x10, 1, 1);
    func_08011F18(1, 0x20, 0x40, 0x10, 1, 1);
    func_08008B70(1, 0xFF, 0xFF);
    func_08011F18(2, 0x20, 0x30, 0x10, 1, 1);
    func_08011F18(2, 0x20, 0x40, 0x10, 1, 1);
    func_08008B70(2, 0xFF, 0xFF);
    func_08011F18(3, 0x20, 0x30, 0x10, 1, 1);
    func_08011F18(3, 0x20, 0x40, 0x10, 1, 1);
    func_08008B70(3, 0xFF, 0xFF);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0x81, 2, 4, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
