#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037450(s32);

void func_0801E9E0(void)
{
    func_08008B58(0x1E2);
    func_08011F18(2, 0x80, 0x1C0, 0x20, 2, 0);
    func_08008B70(2, 0xFF, 0xFF);
    func_08008B58(0x1E3);
    func_08011F18(4, 0x1C0, 0x1A0, 0x20, 1, 0);
    func_08008B70(4, 0xFF, 0xFF);
    func_08008B58(0x1E4);
    func_08011F18(3, 0x1C0, 0x1C0, 0x20, 2, 0);
    func_08008B70(3, 0xFF, 0xFF);
    func_08008B58(0x1E5);
    func_08037450(0x18);
    func_08037450(0x19);
    func_08003D78(4, 0x0801EB95);
    func_08011E08();
    func_08003DD8(4);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x0801EAA9;
}
