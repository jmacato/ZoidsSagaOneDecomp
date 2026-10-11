#include "m2c.h"

M2C_UNK func_08008B58(s32);
s32 func_08014618();

void func_08006A14(void)
{
    if (func_08014618() == 0)
    {
        func_08008B58(0xBC);
        return;
    }
    func_08008B58(0x305);
}
