#include "m2c.h"

extern struct { u8 pad_0[0x21F0]; s8 f_21F0; } D_0200EB84;

s32 func_080335B4(s32, s32, s32, s32);
M2C_UNK func_08033628(s32, s32, s32, s32, s32, s32, s32);

void func_0803CF48(void)
{
    D_0200EB84.f_21F0 = 0xFF;
    if (func_080335B4(1, 3, 5, 1) != 0)
    {
        func_08033628(1, 0, 2, 0x11, 0x64, 0, 1);
        return;
    }
    D_0200EB84.f_21F0 = 4;
}
