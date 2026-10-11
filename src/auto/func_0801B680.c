#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

s32 func_08001040(s32);
M2C_UNK func_0800BEE4();

void func_0801B680(void)
{
    func_0800BEE4();
    if ((func_08001040(0x19C) != 0) && (func_08001040(0x19D) == 0))
    {
        D_02000000.f_0 = 0x0801B6B5;
    }
}
