#include "m2c.h"

extern struct { u8 pad_0[0x4]; s32 f_4; } D_02000000;

s32 func_08001040(s32);
M2C_UNK func_0800802C();

void func_080218E8(void)
{
    func_0800802C();
    if ((func_08001040(0x1C2) != 0) && (func_08001040(0x1C6) == 0))
    {
        D_02000000.f_4 = 0x08021919;
    }
}
