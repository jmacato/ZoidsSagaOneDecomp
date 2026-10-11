#include "m2c.h"

extern struct { u8 pad_0[0x21F0]; s8 f_21F0; } D_0200EB84;

M2C_UNK func_080335B4(s32, s32, s32, s32);
M2C_UNK func_08033628(s32, s32, s32, M2C_UNK, s32, s32, s32);

void func_0803DB38(void)
{
    func_08033628(0, 0, 5, 0x802, 0x32, 0, 1);
    func_080335B4(0, 0, 5, 4);
    D_0200EB84.f_21F0 = 0xFF;
}
