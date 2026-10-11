#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
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

void func_080235F8(void)
{
    func_08011E08();
    func_080076C0(0xEE, 0x22, 8, 2, 0x0866AD7C);
    func_08008B70(0, 0x22, 0xA);
    func_08011E24();
    func_08000BD8(2, 1);
    func_0805EE78(0xF);
    func_08008B58(0x246);
    func_08011F18(1, 0x220, 0x60, 0x10, 1, 0);
    func_08008B58(0x247);
    func_08000BD8(2, 1);
    func_08008B58(0x248);
    func_08011F18(1, 0x220, 0x40, 0x10, 1, 0);
    func_08008B70(1, 0xFF, 0xFF);
    func_08003D78(4, 0x08023875);
    func_08011E08();
    func_08003DD8(4);
    func_080076C0(0xF2, 0xC, 8, 8, 0x0866ACDC);
    func_08003D78(4, 0x08023895);
    func_08003D78(5, 0x080238A1);
    func_08003D78(6, 0x080238D1);
    func_08003D78(7, 0x08023901);
    func_08011F18(3, 0xC0, 0x40, 0x10, 1, 0);
    func_08000BD8(4, 2);
    func_08000BD8(5, 3);
    func_0805EE78(0xF);
    func_08000BD8(6, 3);
    func_08000BD8(7, 3);
    func_08000BD8(8, 3);
    func_0805EE78(0xF);
    func_08008B58(0x249);
    func_08003D78(4, 0x08023929);
    func_08003D78(5, 0x08023951);
    func_08011F18(3, 0xB0, 0x30, 0x10, 1, 0);
    func_08008B70(3, 0xFF, 0xFF);
    func_0805EE78(1);
    func_08003D78(4, 0x08023979);
    func_08003D78(5, 0x080239A1);
    func_08003D78(6, 0x080239C9);
    func_08011F18(5, 0xB0, 0x30, 0x10, 1, 0);
    func_08008B70(5, 0xFF, 0xFF);
    func_0805EE78(1);
    func_08037424(0x1F);
    func_08037424(0x20);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xF2, 0xB, 3, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}

void func_080237F4(void)
{
    func_08011F18(0, 0xC0, 0x40, 0x10, 1, 0);
    func_08011F18(0, 0xB0, 0x40, 0x10, 1, 0);
}

void func_08023824(void)
{
    func_08011F18(1, 0xC0, 0x50, 0x10, 1, 0);
    func_08011F18(1, 0xB0, 0x50, 0x10, 1, 0);
}

void func_08023854(void)
{
    func_08011F18(2, 0xC0, 0x40, 0x10, 1, 0);
}
