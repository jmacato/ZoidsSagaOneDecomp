#include "m2c.h"

extern struct { u8 pad_0[0x238]; s32 f_238; } D_02000034;

M2C_UNK func_08003DF8(s32, M2C_UNK);
M2C_UNK func_08003E3C(s32);
M2C_UNK func_0805EE78(s32);

void func_08003B3C(void)
{
    func_08003DF8(4, 0x0804C985);
    if (D_02000034.f_238 != 1)
    {
        do
        {
            func_0805EE78(1);
        } while (D_02000034.f_238 != 1);
    }
    func_08003E3C(4);
}
