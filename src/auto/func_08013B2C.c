#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08000F88(M2C_UNK);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008324(s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037450(s32);
M2C_UNK func_0805EE78(s32);

void func_08013B2C(void)
{
    u32 var_r4;

    func_0805EE78(0x20);
    func_08008B58(0x99);
    func_08011F18(7, 0xA0, 0x100, 0x20, 4, 1);
    func_08011F18(7, 0xA0, 0x140, 0x20, 4, 1);
    func_08011F18(7, 0, 0x140, 0x20, 4, 1);
    func_08008B70(7, 0xFF, 0xFF);
    func_08008B58(0x9A);
    func_08011E08();
    func_080076C0(0x26, 3, 1, 9, 0x0866716C);
    func_08008B70(0, 0xFF, 0xFF);
    func_08001A08(7);
    D_02000B54.f_0 = 0;
    func_080019B4(7);
    func_08011E24();
    func_08008B70(8, 3, 1);
    func_0805EE78(0x3C);
    func_08011F18(5, 0x60, 0x40, 0x20, 2, 1);
    func_0805EE78(0xF);
    func_08003D78(4, 0x08013CF1);
    func_08011F18(6, 0x80, 0x40, 0x20, 2, 1);
    func_0805EE78(0xF);
    func_08003D78(4, 0x08013D11);
    func_08003D78(5, 0x08013D2D);
    func_08003D78(6, 0x08013D49);
    func_08011F18(1, 0x80, 0x60, 0x20, 2, 1);
    func_0805EE78(0x3C);
    func_08008B58(0x9B);
    func_0805EE78(0xF);
    func_08000BD8(6, 1);
    func_08000BD8(7, 1);
    func_08000BD8(8, 1);
    func_0805EE78(0xF);
    var_r4 = 0;
    do
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
        var_r4 += 1;
    } while (var_r4 <= 0x3FU);
    func_08008B58(0x9C);
    func_08037450(1);
    func_08037450(2);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08000F88(0x157);
    D_02000000.f_0 = 0x08013CCD;
}
