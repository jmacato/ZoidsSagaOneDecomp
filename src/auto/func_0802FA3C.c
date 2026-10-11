#include "m2c.h"

extern struct { u8 pad_0[0x44C]; s32 f_44C; u8 pad_450[0x8]; s32 f_458; } D_02000034;

s32 func_0802FA3C(void)
{
    D_02000034.f_44C = 1;
    return D_02000034.f_458;
}
