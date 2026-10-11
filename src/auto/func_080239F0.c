#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_080239F0(void)
{
    func_08003D78(4, 0x08023DFD);
    func_08003D78(5, 0x08023E1D);
    func_08003D78(6, 0x08023E41);
    func_08011F18(0, 0x150, 0x200, 0x10, 2, 0);
    func_08001A08(4);
    D_02000B54.f_0 = 0;
    func_080019B4(4);
    func_08008B58(0x24B);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x08023A75;
loop_1:
    func_0805EE78(1);
    goto loop_1;
}
