#include "m2c.h"

extern struct { u8 pad_0[0x220]; u16 f_220; } D_03004BBC;

void func_08031B54(void)
{
    D_03004BBC.f_220 &= 0x7FFF;
}
