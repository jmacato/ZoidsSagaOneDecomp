#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0801E48C(void)
{
    func_0805EE78(0x20);
    func_08008B70(3, 0xC, 0x12);
    func_08011F18(3, 0xC0, 0xD0, 0x10, 1, 1);
    func_08008B70(0, 0xC, 0x12);
    func_08011F18(0, 0xC0, 0xE0, 0x10, 1, 0);
    func_08011F18(0, 0xB0, 0xE0, 0x10, 1, 0);
    func_08000BD8(1, 0);
    func_08008B70(1, 0xC, 0x12);
    func_08011F18(1, 0xC0, 0xE0, 0x10, 1, 1);
    func_08011F18(1, 0xD0, 0xE0, 0x10, 1, 1);
    func_08000BD8(2, 0);
    func_08008B70(2, 0xC, 0x12);
    func_08011F18(2, 0xC0, 0xE0, 0x10, 1, 1);
    func_08000BD8(4, 1);
    func_08008B58(0x1DA);
    func_08011F18(3, 0xB0, 0xE0, 0x10, 1, 1);
    func_08008B70(3, 0xFF, 0xFF);
    func_08011F18(2, 0xB0, 0xE0, 0x10, 1, 1);
    func_08008B70(2, 0xFF, 0xFF);
    func_08011F18(1, 0xB0, 0xE0, 0x10, 1, 1);
    func_08008B70(1, 0xFF, 0xFF);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x0801E5B9;
}
