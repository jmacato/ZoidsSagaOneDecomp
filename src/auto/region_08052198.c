#include "m2c.h"

extern struct { u8 pad_0[0x338]; s32 f_338; } D_02000034;

M2C_UNK func_08003DF8(s32, M2C_UNK);
M2C_UNK func_08003E3C(s32);
M2C_UNK func_0805EE78(s32);

s32 region_08052198(void)
{
    func_08003DF8(6, 0x080521D1);
    D_02000034.f_338 = 0;
    do
    {
        func_0805EE78(1);
    } while (D_02000034.f_338 == 0);
    return func_08003E3C(6);
}
