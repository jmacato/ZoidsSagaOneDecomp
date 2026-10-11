#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019B4(s32);
M2C_UNK func_080019EC(s32);
M2C_UNK func_08001A08(s32);
s32 func_08001A28(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0801C684(void)
{
    func_08011E08();
    func_080076C0(0xB3, 4, 4, 4, 0x0866984C);
    func_08011E24();
    func_08003D78(4, 0x0801C8C5);
    func_08003D78(5, 0x0801C905);
    func_08003D78(6, 0x0801C945);
    func_08011F18(0, 0xB0, 0x40, 0x10, 1, 0);
    func_08011F18(0, 0xB0, 0x60, 0x10, 1, 0);
    func_08011F18(0, 0xD0, 0x60, 0x10, 1, 0);
    func_08011E08();
    func_080076C0(0xB3, 0xF, 6, 9, 0x0866989C);
    func_08001A08(4);
    D_02000B54.f_0 = 0;
    func_080019B4(4);
    func_08008B70(0, 0xD, 6);
    func_08011E24();
    func_0805EE78(0xB4);
    func_08008B58(0x19E);
    func_080019EC(0x7D);
    do
    {
        func_0805EE78(1);
    } while (func_08001A28(0x7D) == 0);
    func_080019EC(0x7D);
    do
    {
        func_0805EE78(1);
    } while (func_08001A28(0x7D) == 0);
    func_08008B58(0x19F);
    func_08008B70(7, 0x17, 6);
    func_08008B70(8, 0x17, 7);
    func_08003D78(4, 0x0801C985);
    func_08011F18(7, 0x120, 0x60, 0x10, 2, 0);
    func_08008B58(0x1A0);
    func_08003D78(4, 0x0801C9A5);
    func_08003D78(5, 0x0801C9D5);
    func_08011F18(4, 0x100, 0x70, 0x10, 2, 0);
    func_08011F18(4, 0x70, 0x70, 0x10, 2, 0);
    func_08000BD8(1, 2);
    func_08000BD8(2, 2);
    func_08000BD8(3, 2);
    func_08000BD8(4, 2);
    func_08008B58(0x1A1);
    func_08003D78(4, 0x0801CA05);
    func_08003D78(5, 0x0801CA21);
    func_08003D78(6, 0x0801CA41);
    func_08003D78(7, 0x0801CA61);
    func_08011E08();
    func_08003DD8(4);
    func_08003DD8(5);
    func_08003DD8(6);
    func_08003DD8(7);
    func_080076C0(0xB0, 8, 0x13, 1, 0x08669950);
    func_08011E24();
    func_08008B58(0x1A2);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xB0, 8, 0x13, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
