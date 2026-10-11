#include "m2c.h"

extern struct { u8 pad_0[0x228]; s32 f_228; } D_02000034;

M2C_UNK func_08003DF8(s32, M2C_UNK);
M2C_UNK func_08003E3C(s32);
M2C_UNK func_0805EE78(s32);

void func_080552F4(void)
{
    func_08003DF8(4, 0x0805532D);
    D_02000034.f_228 = 0;
    do
    {
        func_0805EE78(1);
    } while (D_02000034.f_228 == 0);
    func_08003E3C(4);
}
