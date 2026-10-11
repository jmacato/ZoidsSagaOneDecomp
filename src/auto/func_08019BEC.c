#include "m2c.h"

extern u8 D_02000000[];
extern u8 D_02000B54[];
extern u8 D_086683F0[];
extern u8 D_08668454[];

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_080089A0(s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_08019BEC(void)
{
    func_0805EE78(0x20);
    func_08011F18(2, 0x80, 0x30, 0x10, 1, 1);
    func_08008B58(0x123);
    func_08011E08();
    func_080076C0(0xA8, 4, 4, 5, D_086683F0);
    func_08001A08(4);
    *(s16 *)D_02000B54 = 0;
    func_080019B4(4);
    func_08008B70(0, 0xFF, 0xFF);
    func_08011E24();
    func_08008B58(0x124);
    func_08011E08();
    func_080076C0(0xAE, 2, 5, 4, D_08668454);
    func_08011E24();
    func_08003D78(4, 0x08019DA5);
    func_0805EE78(0x3C);
    func_08008B70(3, 0xE, 2);
    func_08011F18(3, 0x50, 0x20, 0x10, 1, 1);
    func_08011F18(3, 0x50, 0x30, 0x10, 1, 1);
    func_08000BD8(4, 1);
    func_08000BD8(1, 0);
    func_08008B58(0x125);
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
    *(s32 *)D_02000000 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xAE, 2, 4, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
