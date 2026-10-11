#include "m2c.h"

extern struct { u8 f_0; u8 pad_1[0x5]; s8 f_6; } D_030021A8;

void func_08006284(void)
{
    if (D_030021A8.f_0 != 0)
    {
        D_030021A8.f_6 = 1;
    }
}
