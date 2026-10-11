#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019EC(s32);
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

void func_0801CA80(void)
{
    func_08011E08();
    func_080076C0(0xB3, 0x1B, 4, 4, 0x08669964);
    func_08011E24();
    func_08003D78(4, 0x0801CCB1);
    func_08003D78(5, 0x0801CCF9);
    func_08003D78(6, 0x0801CD41);
    func_08011F18(0, 0x150, 0x40, 0x10, 1, 0);
    func_08011F18(0, 0x150, 0x60, 0x10, 1, 0);
    func_08011F18(0, 0x120, 0x60, 0x10, 1, 0);
    func_08011E08();
    func_080076C0(0xB3, 0x10, 6, 9, 0x086699B4);
    func_08008B70(0, 0x12, 6);
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
    func_08008B70(7, 8, 6);
    func_08008B70(8, 8, 7);
    func_08003D78(4, 0x0801CD89);
    func_08011F18(7, 0xD0, 0x60, 0x10, 2, 0);
    func_08008B58(0x1A0);
    func_08003D78(4, 0x0801CDA9);
    func_08003D78(5, 0x0801CDDD);
    func_08011F18(4, 0xF0, 0x70, 0x10, 2, 0);
    func_08011F18(4, 0x180, 0x70, 0x10, 2, 0);
    func_08000BD8(1, 3);
    func_08000BD8(2, 3);
    func_08000BD8(3, 3);
    func_08000BD8(4, 3);
    func_08008B58(0x1A1);
    func_08003D78(4, 0x0801CE11);
    func_08003D78(5, 0x0801CE31);
    func_08003D78(6, 0x0801CE51);
    func_08003D78(7, 0x0801CE71);
    func_08011E08();
    func_08003DD8(4);
    func_08003DD8(5);
    func_08003DD8(6);
    func_08003DD8(7);
    func_080076C0(0xB0, 8, 0x13, 1, 0x08669A68);
    func_08011E24();
    func_08008B58(0x1A2);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xB0, 8, 0x13, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
