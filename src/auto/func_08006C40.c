#include "m2c.h"

M2C_UNK func_08008B58(s32);
s32 func_0801B78C();

void func_08006C40(void)
{
    if ((func_0801B78C() << 0x18) != 0)
    {
        func_08008B58(0x1A7);
        return;
    }
    func_08008B58(0x370);
}
