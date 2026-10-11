#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0x2A8]; u16 f_2A8; } D_03004BBC;

M2C_UNK func_08003D78(s32, M2C_UNK);

void func_0800E044(void)
{
    D_03004BBC.f_2A8 |= 0x400;
    D_02000000.f_0 = 0x0800C4D1;
    func_08003D78(3, 0x0800E07D);
}
