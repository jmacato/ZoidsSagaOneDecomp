#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_080152A4(void)
{
    func_0805EE78(0x20);
    func_08008B58(0xBE);
    func_08003D78(4, 0x08015391);
    func_08003D78(5, 0x080153B1);
    func_08011F18(3, 0x140, 0xE0, 0x20, 2, 1);
    func_08011F18(3, 0x160, 0xE0, 0x20, 2, 1);
    func_08011F18(3, 0x160, 0x80, 0x20, 2, 1);
    func_08000BD8(4, 2);
    func_08008B58(0xBF);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x08015339;
}
