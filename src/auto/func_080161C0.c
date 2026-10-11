#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();

void func_080161C0(void)
{
    func_08011E08();
    func_080076C0(0x47, 0x26, 0xC, 2, 0x08667BA8);
    func_08001A08(0x16);
    D_02000B54.f_0 = 0;
    func_080019B4(0x16);
    func_08011E24();
    func_08008B58(0xED);
    func_08011E08();
    func_080076C0(0x42, 8, 5, 5, 0x08667BD0);
    func_08008B70(0, 6, 5);
    func_08011E24();
    func_08008B58(0xEE);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0x32, 0x11, 0x15, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
