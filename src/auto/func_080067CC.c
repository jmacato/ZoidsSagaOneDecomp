#include "m2c.h"

M2C_UNK func_08008B58(s32);
s32 func_080126D0();

void func_080067CC(void)
{
    if (func_080126D0() == 0)
    {
        func_08008B58(0x70);
        return;
    }
    func_08008B58(0x96);
}
