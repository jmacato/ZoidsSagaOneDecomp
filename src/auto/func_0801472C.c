#include "m2c.h"

s32 func_08001040(s32);
M2C_UNK func_0800802C();
M2C_UNK func_08008B70(s32, s32, s32);

void func_0801472C(void)
{
    func_0800802C();
    if (func_08001040(0x16A) == 0)
    {
        func_08008B70(1, 0xFFFF, 0xFFFF);
        func_08008B70(2, 0xFFFF, 0xFFFF);
        func_08008B70(3, 0xFFFF, 0xFFFF);
    }
}
