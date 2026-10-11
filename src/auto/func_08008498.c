#include "m2c.h"

extern struct { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x4]; u16 f_14; u8 pad_16[0x2]; u16 f_18; } D_0200000C;

u16 func_0805D484(u16, u16);

u16 func_08008498(u16 arg0, u16 arg1)
{
    u16 var_r4;

    var_r4 = arg1;
    if (D_0200000C.f_18 == 2)
    {
        var_r4 += 1;
    }
    return *(s32 *)((((var_r4 * func_0805D484(D_0200000C.f_14, D_0200000C.f_18)) + arg0) * 2) + D_0200000C.f_C);
}
