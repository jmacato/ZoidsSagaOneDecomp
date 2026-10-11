#include "m2c.h"

M2C_UNK func_08008B58(s32);
s32 func_0801251C();
M2C_UNK func_0801256C();

void func_080068BC(void)
{
    if (func_0801251C() == 0)
    {
        func_08008B58(0x8B);
        return;
    }
    func_08008B58(0x84);
    func_0801256C();
}
