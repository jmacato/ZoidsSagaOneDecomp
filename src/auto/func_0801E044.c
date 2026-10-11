#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0801E044(void)
{
    func_0805EE78(0x20);
    func_08008B58(0x1D3);
    func_08008B70(3, 0x11, 0x15);
    func_0805EE78(0xF);
    func_08011F18(3, 0x220, 0x260, 0x20, 2, 0);
    func_08000BD8(4, 2);
    func_0805EE78(0xF);
    func_08008B58(0x1D4);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x0801E0BD;
loop_1:
    func_0805EE78(1);
    goto loop_1;
}
