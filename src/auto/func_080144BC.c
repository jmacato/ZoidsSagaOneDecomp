#include "m2c.h"

extern struct { u8 pad_0[0x8]; u16 f_8; } D_02000000;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

void func_080144BC(void)
{
    D_03004BBC.f_E8 = 0;
    D_02000000.f_8 &= 0xFFFD;
}
