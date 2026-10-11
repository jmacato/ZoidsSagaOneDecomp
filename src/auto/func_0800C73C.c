#include "m2c.h"

M2C_UNK func_08000F88(s32);
s32 func_08001040(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);

s32 func_0800C73C(void)
{
    func_08008B58(0x2B);
    func_08000F88(0x120);
    if ((func_08001040(0x120) != 0) && (func_08001040(0x121) != 0))
    {
        func_08008B70(2, 0x26, 1);
    }
}
