#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

s32 func_08001040(M2C_UNK);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_0800BEE4();

void func_0800E758(void)
{
    func_0800BEE4();
    if (func_08001040(0x127) == 0)
    {
        D_02000000.f_0 = 0x0800C4D1;
        func_08003D78(3, 0x0800E78D);
    }
}
