#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

s32 func_08001040(s32);
M2C_UNK func_0800BEE4();

void func_0801EE94(void)
{
    func_0800BEE4();
    if ((func_08001040(0x1AF) != 0) && (func_08001040(0x1B0) == 0))
    {
        D_02000000.f_0 = 0x0801EEC9;
    }
}
