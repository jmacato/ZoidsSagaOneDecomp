#include "m2c.h"

M2C_UNK func_08008B58(s32);
s32 func_0801251C();
M2C_UNK func_0801253C();

void func_0800685C(void)
{
    if (func_0801251C() == 0)
    {
        func_08008B58(0x88);
        return;
    }
    func_08008B58(0x81);
    func_0801253C();
}
