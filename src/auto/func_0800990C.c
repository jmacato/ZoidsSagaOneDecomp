#include "m2c.h"

extern struct { u8 pad_0[0x8]; u16 f_8; } D_02000000;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08003D78(s32, M2C_UNK);

s32 func_0800990C(void)
{
    D_02000000.f_8 |= 2;
    D_03004BBC.f_E8 = 1;
    return func_08003D78(0xA, 0x0800960D);
}
