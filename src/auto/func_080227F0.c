#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_080227F0(void)
{
    func_08011E24();
    func_08008B58(0x226);
    func_08008B70(2, 8, 0xB);
    func_08011F18(2, 0x180, 0x160, 0x20, 1, 1);
    func_08008B58(0x227);
    func_08008B70(0, 0x10, 9);
    func_08011F18(0, 0x200, 0x120, 0x20, 1, 0);
    func_08011F18(0, 0x200, 0x140, 0x20, 1, 0);
    func_08011F18(0, 0x1C0, 0x140, 0x20, 1, 0);
    func_08000BD8(1, 1);
    func_08008B58(0x228);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x080228B1;
loop_1:
    func_0805EE78(1);
    goto loop_1;
}
