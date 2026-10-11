#include "m2c.h"

extern struct { u8 pad_0[0x448]; s32 f_448; } D_02000034;

void func_0802FA6C(void)
{
    D_02000034.f_448 = 1;
}

void func_0802FA80(void)
{
    D_02000034.f_448 = 3;
}
