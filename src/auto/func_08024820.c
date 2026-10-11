#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008324(M2C_UNK, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_08024820(void)
{
    u32 var_r4;

    func_08008B70(8, 0xFF, 0xFF);
    func_08008B70(9, 0xFF, 0xFF);
    func_08008B70(0xA, 0xFF, 0xFF);
    func_08008B70(0xB, 0xFF, 0xFF);
    func_08008B70(0xC, 6, 4);
    func_08008B70(0xD, 5, 3);
    func_08011E24();
    func_08008B58(0x266);
    func_08003D78(4, 0x08024E05);
    func_08003D78(5, 0x08024E25);
    func_08003D78(6, 0x08024E45);
    func_08003D78(7, 0x08024E65);
    var_r4 = 0;
    do
    {
        func_08008324(0xFFFF0000, 0);
        func_0805EE78(1);
        var_r4 += 1;
    } while (var_r4 <= 0x7FU);
    func_08011F18(0xC, 0xE0, 0x80, 0x20, 1, 1);
    func_08008B58(0x267);
    func_08011F18(0xC, 0xE0, 0xA0, 0x20, 4, 1);
    func_08011F18(0xC, 0x160, 0xA0, 0x20, 4, 1);
    func_08008B70(0xC, 0xFF, 0xFF);
    func_08008B58(0x268);
    func_08011F18(1, 0xC0, 0x80, 0x20, 2, 1);
    func_08008B58(0x269);
    func_08003D78(4, 0x08024E85);
    func_08003D78(5, 0x08024EA5);
    func_08011F18(2, 0xE0, 0x80, 0x20, 2, 1);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x08024975;
loop_3:
    func_0805EE78(1);
    goto loop_3;
}
