#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0x330]; u16 f_330; } D_03004BBC;

M2C_UNK func_08008B70(s32, s32, s32);

void func_0802163C(void)
{
    if (4 & D_03004BBC.f_330)
    {
        func_08008B70(5, 0xFF, 0xFF);
        D_02000000.f_0 = 0x080215C9;
    }
}
