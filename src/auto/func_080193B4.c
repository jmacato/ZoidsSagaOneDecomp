#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

s32 func_08001040(s32);
M2C_UNK func_0800BEE4();

void func_080193B4(void)
{
    func_0800BEE4();
    if ((func_08001040(0x183) != 0) && (func_08001040(0x188) == 0))
    {
        D_02000000.f_0 = 0x080193E9;
    }
}
