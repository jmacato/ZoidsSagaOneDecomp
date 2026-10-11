#include "m2c.h"

extern struct { u8 pad_0[0x4D0]; s32 f_4D0; u8 pad_4D4[0xC]; s32 f_4E0; } D_02000034;

void func_08004018(void)
{
    D_02000034.f_4D0 = 1;
    D_02000034.f_4E0 = 0;
}
