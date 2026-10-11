#include "m2c.h"

s32 func_08001040(s32);
M2C_UNK func_0800802C();
M2C_UNK func_08008B70(s32, s32, s32);

void func_08014780(void)
{
    func_0800802C();
    if ((func_08001040(0x169) == 0) || (func_08001040(0x16A) != 0))
    {
        func_08008B70(1, 0xFF, 0xFF);
    }
}
