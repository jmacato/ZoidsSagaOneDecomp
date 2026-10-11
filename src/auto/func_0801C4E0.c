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
M2C_UNK func_0805EE78(s32);

void func_0801C4E0(void)
{
    func_08011E08();
    func_080076C0(0xB1, 0xC, 4, 5, 0x086697D4);
    func_08001A08(6);
    D_02000B54.f_0 = 0;
    func_080019B4(6);
    func_08008B70(0, 0xC, 6);
    func_08011E24();
    func_08008B58(0x19A);
    func_08000BD8(5, 1);
    func_0805EE78(0xF);
    func_08008B58(0x19B);
    func_08011F18(4, 0xC0, 0, 0x10, 1, 1);
    func_08008B70(4, 0xFF, 0xFF);
    func_08008B58(0x19C);
    func_08003D78(4, 0x0801C60D);
    func_08003D78(5, 0x0801C629);
    func_08003D78(6, 0x0801C645);
    func_08003D78(7, 0x0801C665);
    func_08011E08();
    func_08003DD8(4);
    func_08003DD8(5);
    func_08003DD8(6);
    func_08003DD8(7);
    func_080076C0(0xB2, 0xD, 7, 1, 0x08669838);
    func_08011E24();
    func_08008B58(0x19D);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xB2, 0xD, 7, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
