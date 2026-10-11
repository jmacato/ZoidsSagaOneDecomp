#include "m2c.h"

extern struct { u8 pad_0[0x14]; s32 f_14; } D_03004B9C;

M2C_UNK func_0805EE78(s32);

void func_0802F010(void)
{
    if (D_03004B9C.f_14 != 0xFFF40000)
    {
        do
        {
            D_03004B9C.f_14 = (s32) (D_03004B9C.f_14 + 0xFFFF0000);
            func_0805EE78(1);
        } while (D_03004B9C.f_14 != 0xFFF40000);
    }
    D_03004B9C.f_14 = 0xFFF40000;
}
