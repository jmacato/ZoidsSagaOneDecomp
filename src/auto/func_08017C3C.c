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
M2C_UNK func_0805EE78(s32);

void func_08017C3C(void)
{
    func_0805EE78(0x20);
    func_08011F18(0, 0x160, 0x180, 0x20, 1, 0);
    func_08008B58(0x10E);
    func_08000BD8(1, 1);
    func_08008B70(1, 0xB, 8);
    func_08008B70(2, 0xB, 8);
    func_08008B70(3, 0xB, 8);
    func_08003D78(4, 0x08017E41);
    func_08003D78(5, 0x08017E69);
    func_08011F18(1, 0x140, 0x180, 0x20, 2, 1);
    func_08000BD8(2, 3);
    func_08008B70(4, 0xB, 8);
    func_08011F18(4, 0x160, 0x140, 0x20, 1, 1);
    func_08000BD8(5, 1);
    func_08003D78(4, 0x08017E91);
    func_08003D78(5, 0x08017F6D);
    func_08003D78(6, 0x08018049);
    func_0805EE78(0x3C);
    func_08001A08(4);
    D_02000B54.f_0 = 0;
    func_080019B4(4);
    func_08008B58(0x10F);
    func_08011E08();
    func_08003DD8(4);
    func_08003DD8(5);
    func_08003DD8(6);
    func_080076C0(0x69, 0x19, 0x10, 6, 0x086680BC);
    func_08011E24();
    func_08008B58(0x110);
    func_08011F18(1, 0x190, 0x100, 0x10, 1, 1);
    func_08008B70(1, 0xFF, 0xFF);
    func_08011F18(2, 0x190, 0x100, 0x10, 1, 1);
    func_08008B70(2, 0xFF, 0xFF);
    func_08011F18(3, 0x190, 0x100, 0x10, 1, 1);
    func_08008B70(3, 0xFF, 0xFF);
    func_08011F18(4, 0x190, 0x100, 0x10, 1, 1);
    func_08008B70(4, 0xFF, 0xFF);
    func_08011F18(5, 0x190, 0x100, 0x10, 1, 1);
    func_08008B70(5, 0xFF, 0xFF);
    func_08037424(0xA);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0x69, 0x19, 0x10, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
