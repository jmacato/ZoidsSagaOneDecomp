#include "m2c.h"

extern struct { u8 pad_0[0x8]; u16 f_8; } D_02000000;

M2C_UNK func_0800BE54();

void func_0800BEC8(void)
{
    if (!(8 & D_02000000.f_8))
    {
        func_0800BE54();
    }
}
