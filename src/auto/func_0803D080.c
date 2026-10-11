#include "m2c.h"

extern struct { u8 pad_0[0x2]; u16 f_2; u8 pad_4[0x21EC]; s8 f_21F0; } D_0200EB84;

s32 func_080335B4(s32, s32, s32, s32);
M2C_UNK func_08033628(s32, s32, s32, s32, s32, s32, s32);

void func_0803D080(void)
{
    D_0200EB84.f_21F0 = 0xFF;
    if (func_080335B4(1, 3, 5, 1) != 0)
    {
        func_08033628(0, 0, 5, 0x102, 0x32, 0, 1);
        return;
    }
    D_0200EB84.f_21F0 = 4;
}

void func_0803D0D0(void)
{
    D_0200EB84.f_2 = (u16) (8 | D_0200EB84.f_2);
    D_0200EB84.f_21F0 = 0xFF;
}

void func_0803D0EC(void)
{
    D_0200EB84.f_2 = (u16) (0x10 | D_0200EB84.f_2);
    D_0200EB84.f_21F0 = 0xFF;
}
