#include "m2c.h"

extern struct { u8 pad_0[0x2]; s16 f_2; } D_03001ED4;

void func_08004C74(s16 arg0)
{
    D_03001ED4.f_2 = arg0;
}
