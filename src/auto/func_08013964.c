#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008324(s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_08013964(void)
{
    u32 var_r4;

    func_08001A08(5);
    D_02000B54.f_0 = 0;
    func_080019B4(5);
    func_08011F18(0, 0x40, 0x100, 0x20, 1, 1);
    func_08000BD8(1, 3);
    var_r4 = 0;
    do
    {
        func_08008324(0x10000, 0);
        func_0805EE78(1);
        var_r4 += 1;
    } while (var_r4 <= 0x3FU);
    func_08008B70(6, 2, 8);
    func_08011F18(6, 0x80, 0x100, 0x20, 2, 1);
    func_08008B70(1, 2, 8);
    func_08011F18(1, 0x80, 0xE0, 0x20, 2, 1);
    func_08008B70(5, 2, 8);
    func_08011F18(5, 0x80, 0x120, 0x20, 2, 1);
    func_08008B70(2, 2, 8);
    func_08008B70(3, 2, 8);
    func_08008B70(4, 2, 8);
    func_08003D78(4, 0x08013A81);
    func_08003D78(5, 0x08013AA9);
    func_08011F18(2, 0x60, 0xE0, 0x20, 1, 1);
    func_08000BD8(3, 3);
    func_08008B58(0x98);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x08013AD1;
}
