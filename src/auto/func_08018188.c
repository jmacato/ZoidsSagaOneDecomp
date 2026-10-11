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
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037424(s32);

void func_08018188(void)
{
    func_08011E08();
    func_080076C0(0x6A, 0x15, 2, 2, 0x08668134);
    func_08001A08(8);
    D_02000B54.f_0 = 0;
    func_080019B4(8);
    func_08011E24();
    func_08008B58(0x112);
    func_08011F18(1, 0x2A0, 0x40, 0x20, 1, 1);
    func_08008B70(1, 0xFF, 0xFF);
    func_08037424(0xB);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0x6A, 0x15, 2, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
