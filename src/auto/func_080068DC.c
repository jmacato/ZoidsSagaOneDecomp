#include "m2c.h"

M2C_UNK func_08008B58(s32);
s32 func_0801251C();
M2C_UNK func_0801257C();

void func_080068DC(void)
{
    if (func_0801251C() == 0)
    {
        func_08008B58(0x8C);
        return;
    }
    func_08008B58(0x85);
    func_0801257C();
}
