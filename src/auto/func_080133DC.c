#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_080089A0(s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037424(s32);
M2C_UNK func_0805EE78(s32);

void func_080133DC(void)
{
    func_08011E08();
    func_08008B70(0, 0x18, 7);
    func_08000BD8(1, 0);
    func_08008B70(7, 0x19, 7);
    func_08000BD8(8, 0);
    func_08008B70(8, 0x17, 7);
    func_08000BD8(9, 0);
    func_08008B70(9, 0x16, 7);
    func_08000BD8(0xA, 0);
    func_080089A0(5, 0x9E);
    func_08008B70(4, 0x18, 4);
    func_08000BD8(5, 1);
    func_08000BD8(6, 1);
    func_08000BD8(7, 1);
    func_08011E24();
    func_08001A08(5);
    D_02000B54.f_0 = 0;
    func_080019B4(5);
    func_0805EE78(0x1E);
    func_08008B58(0x75);
    func_08001A08(8);
    D_02000B54.f_0 = 0;
    func_080019B4(8);
    func_08011F18(7, 0x190, 0x40, 0x10, 1, 1);
    func_08000BD8(8, 2);
    func_08000BD8(5, 3);
    func_0805EE78(0xF);
    func_08011F18(5, 0x180, 0x30, 0x10, 1, 1);
    func_08000BD8(6, 1);
    func_0805EE78(0x1E);
    func_08008B58(0x76);
    func_08011F18(7, 0x190, 0x70, 0x10, 1, 1);
    func_08011F18(7, 0x180, 0x70, 0x10, 1, 1);
    func_08008B70(7, 0xFF, 0xFF);
    func_08011F18(8, 0x180, 0x70, 0x10, 1, 1);
    func_08008B70(8, 0xFF, 0xFF);
    func_08011F18(9, 0x180, 0x70, 0x10, 1, 1);
    func_08008B70(9, 0xFF, 0xFF);
    func_08011F18(4, 0x190, 0x40, 0x10, 1, 1);
    func_08011F18(4, 0x190, 0x70, 0x10, 1, 1);
    func_08011F18(4, 0x180, 0x70, 0x10, 1, 1);
    func_08008B70(4, 0xFF, 0xFF);
    func_08011F18(5, 0x190, 0x30, 0x10, 1, 1);
    func_08011F18(5, 0x190, 0x70, 0x10, 1, 1);
    func_08011F18(5, 0x180, 0x70, 0x10, 1, 1);
    func_08008B70(5, 0xFF, 0xFF);
    func_08011F18(6, 0x140, 0x70, 0x10, 1, 1);
    func_08011F18(6, 0x180, 0x70, 0x10, 1, 1);
    func_08008B70(6, 0xFF, 0xFF);
    func_08037424(1);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0x20, 0x18, 7, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
