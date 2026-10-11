#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08000F88(s32);
s32 func_08001040(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008324(s32, M2C_UNK);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037424(s32);
M2C_UNK func_0805EE78(s32);

void func_08013668(void)
{
    u32 var_r4;

    func_0805EE78(0x20);
    func_08011F18(0, 0x80, 0xA0, 0x20, 1, 1);
    if (func_08001040(0x197) != 0)
    {
        func_08008B70(6, 4, 5);
        func_08011F18(6, 0x60, 0x60, 0x20, 2, 1);
    }
    func_08008B70(5, 4, 5);
    func_08011F18(5, 0x80, 0x60, 0x20, 2, 1);
    func_08008B70(1, 4, 5);
    func_08011F18(1, 0xA0, 0x60, 0x20, 2, 1);
    func_08008B70(2, 4, 5);
    func_08008B70(3, 4, 5);
    func_08008B70(4, 4, 5);
    func_08003D78(4, 0x08013789);
    func_08003D78(5, 0x080137AD);
    func_08011F18(2, 0x60, 0x80, 0x20, 1, 1);
    var_r4 = 0;
    do
    {
        func_08008324(0, 0xFFFF0000);
        func_0805EE78(1);
        var_r4 += 1;
    } while (var_r4 <= 0x3FU);
    if (func_08001040(0x197) == 0)
    {
        func_08008B58(0x8D);
        func_08037424(2);
        func_08000F88(0x197);
    }
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x080137D1;
}
