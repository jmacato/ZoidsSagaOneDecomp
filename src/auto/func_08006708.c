#include "m2c.h"

M2C_UNK func_08008B58(s32);
s32 func_0801247C();
s32 func_080126D0();

void func_08006708(void)
{
    if (func_0801247C() == 0)
    {
        func_08008B58(0x6B);
        return;
    }
    if (func_080126D0() == 0)
    {
        func_08008B58(0x79);
        return;
    }
    func_08008B58(0x93);
}
