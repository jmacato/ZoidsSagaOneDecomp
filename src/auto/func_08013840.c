#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_08013840(void)
{
    func_0805EE78(0x20);
    func_08008B58(0x8E);
    func_08011F18(3, 0x80, 0xA0, 0x20, 2, 1);
    func_08008B70(3, 0xFF, 0xFF);
    func_08011F18(4, 0x80, 0xA0, 0x20, 2, 1);
    func_08008B70(4, 0xFF, 0xFF);
    func_08011F18(2, 0x80, 0xA0, 0x20, 2, 1);
    func_08008B70(2, 0xFF, 0xFF);
    func_08011F18(5, 0x80, 0xA0, 0x20, 2, 1);
    func_08008B70(5, 0xFF, 0xFF);
    func_08011F18(1, 0x80, 0xA0, 0x20, 2, 1);
    func_08008B70(1, 0xFF, 0xFF);
    func_08011F18(6, 0x80, 0xA0, 0x20, 2, 1);
    func_08008B70(6, 0xFF, 0xFF);
    func_08011F18(0, 0x80, 0xC0, 0x20, 2, 0);
    func_08008B70(0, 0xFF, 0xFF);
    func_08001A08(7);
    D_02000B54.f_0 = 0;
    func_080019B4(7);
    func_08008B58(0x90);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0x1E, 0x11, 1, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
