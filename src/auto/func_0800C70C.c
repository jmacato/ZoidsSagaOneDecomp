#include "m2c.h"

s32 func_08001040(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_0800BEE4();

void func_0800C70C(void)
{
    func_0800BEE4();
    if ((func_08001040(0x120) != 0) && (func_08001040(0x121) != 0))
    {
        func_08008B70(2, 0x26, 1);
    }
}
