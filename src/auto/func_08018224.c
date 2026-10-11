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
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037990(s32);
M2C_UNK func_0805EE78(s32);

void func_08018224(void)
{
    func_0805EE78(0x20);
    func_08003D78(4, 0x08018379);
    func_0805EE78(0x1E);
    func_08003D78(5, 0x080183B9);
    func_0805EE78(0x1E);
    func_08003D78(6, 0x080183F9);
    func_0805EE78(0x1E);
    func_08003D78(7, 0x0801843D);
    func_0805EE78(0x1E);
    func_08003D78(8, 0x0801847D);
    func_0805EE78(0x1E);
    func_08008B70(3, 2, 8);
    func_08011F18(3, 0x20, 0x70, 0x10, 1, 1);
    func_08011F18(3, 0x20, 0x60, 0x10, 1, 1);
    func_08000BD8(4, 0);
    func_08008B58(0x113);
    func_08037990(0x48);
    func_08003D78(4, 0x080184BD);
    func_0805EE78(0x3C);
    func_08011F18(5, 0x70, 0x70, 0x10, 1, 1);
    func_08011F18(5, 0x20, 0x70, 0x10, 1, 1);
    func_08011F18(5, 0x20, 0x80, 0x10, 1, 1);
    func_08008B70(5, 0xFF, 0xFF);
    func_0805EE78(0xF);
    func_08000BD8(7, 1);
    func_08000BD8(8, 1);
    func_0805EE78(0xF);
    func_08008B58(0x114);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0x5F, 0xC, 5, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
