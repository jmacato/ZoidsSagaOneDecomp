#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_08023E78(void)
{
    func_0805EE78(0x20);
    func_08003D78(4, 0x08023F3D);
    func_0805EE78(0x20);
    func_08003D78(5, 0x08023F69);
    func_0805EE78(0x20);
    func_08008B70(4, 0xE, 0x10);
    func_08011F18(4, 0x100, 0x200, 0x20, 1, 1);
    func_08008B70(0, 0xE, 0x10);
    func_08011F18(0, 0x160, 0x200, 0x20, 1, 0);
    func_08008B58(0x256);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x08023F19;
loop_1:
    func_0805EE78(1);
    goto loop_1;
}
