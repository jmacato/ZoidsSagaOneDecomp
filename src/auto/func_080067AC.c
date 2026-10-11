#include "m2c.h"

M2C_UNK func_08008B58(s32);
s32 func_080126D0();

void func_080067AC(void)
{
    if (func_080126D0() == 0)
    {
        func_08008B58(0x6F);
        return;
    }
    func_08008B58(0x2FA);
}
