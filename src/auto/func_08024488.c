#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_08024488(void)
{
    func_08011F18(0, 0x180, 0x200, 0x20, 1, 0);
    func_08008B70(0, 0xFF, 0xFF);
    func_0805EE78(0xF);
    func_08003D78(4, 0x08024585);
    func_0805EE78(0x20);
    func_08011E08();
    func_08003DD8(4);
    func_0805EE78(1);
    func_080076C0(0xED, 0xD, 0xB, 2, 0x0866B0B0);
    func_08008B70(0, 0xFF, 0xFF);
    func_08003D78(4, 0x080245A9);
    func_08011F18(1, 0x1A0, 0x140, 0x20, 1, 1);
    func_08008B70(0, 0xD, 0xA);
    func_08011F18(0, 0x1A0, 0x160, 0x20, 1, 0);
    func_0805EE78(0xF);
    func_08011F18(1, 0x1A0, 0xE0, 0x20, 1, 1);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xED, 0xD, 0xB, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
