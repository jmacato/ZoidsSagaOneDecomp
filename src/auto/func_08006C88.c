#include "m2c.h"

M2C_UNK func_08008B58(M2C_UNK);
s32 func_0801B78C();

void func_08006C88(void)
{
    if ((func_0801B78C() << 0x18) != 0)
    {
        func_08008B58(0x1A9);
        return;
    }
    func_08008B58(0x372);
}
