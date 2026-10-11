#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;
extern struct { u16 f_0; u16 f_2; } D_02007574;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08000F88(s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037424(s32);
M2C_UNK func_0805EE78(s32);

void func_0801AEDC(void)
{
    func_08011E08();
    func_080076C0(0x96, 8, 8, 9, 0x086690E8);
    func_08001A08(0x12);
    D_02000B54.f_0 = 0;
    func_080019B4(0x12);
    func_08008B70(0, 8, 6);
    func_08011E24();
    func_08003D78(4, 0x0801B009);
    func_0805EE78(8);
    func_08008B70(8, 8, 0xF);
    func_08011F18(8, 0x70, 0x80, 0x10, 1, 1);
    func_0805EE78(0xF);
    func_08000BD8(1, 1);
    func_08000BD8(2, 1);
    func_08000BD8(3, 1);
    func_08000BD8(4, 1);
    func_08000BD8(5, 1);
    func_08000BD8(6, 1);
    func_08000BD8(7, 1);
    func_0805EE78(0xF);
    func_08008B58(0x16F);
    if ((D_02007574.f_0 != 0) && (D_02007574.f_2 != 1))
    {
        func_08037424(0x14);
        func_08037424(0x15);
        func_08000F88(0x190);
    }
    else
    {
        func_08037424(0x14);
    }
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08000BD8(1, 3);
    func_08007188(0x96, 8, 4, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
