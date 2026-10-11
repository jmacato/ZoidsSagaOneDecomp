#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

s32 func_08001040(M2C_UNK);
M2C_UNK func_0800BEE4();

void func_0801907C(void)
{
    func_0800BEE4();
    if ((func_08001040(0x17B) != 0) && (func_08001040(0x181) == 0))
    {
        D_02000000.f_0 = 0x080190B1;
    }
}
