#include "m2c.h"

extern struct { u8 pad_0[0x21F0]; s8 f_21F0; } D_0200EB84;

M2C_UNK func_080335B4(s32, s32, s32, s32);
M2C_UNK func_08033628(s32, s32, s32, s32, s32, s32, s32);

void func_0803D89C(void)
{
    func_080335B4(0, 0, 5, 8);
    func_08033628(1, 0, 5, 0x102, 0x64, 0, 1);
    D_0200EB84.f_21F0 = 0xFF;
}
