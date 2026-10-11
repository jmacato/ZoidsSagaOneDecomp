#include "m2c.h"

M2C_UNK func_08008B58(s32);
s32 func_0801251C();
M2C_UNK func_0801255C();

void func_0800689C(void)
{
    if (func_0801251C() == 0)
    {
        func_08008B58(0x8A);
        return;
    }
    func_08008B58(0x83);
    func_0801255C();
}
