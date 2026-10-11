#include "m2c.h"

M2C_UNK func_08008B58(s32);
s32 func_08014618();

void func_080069F4(void)
{
    if (func_08014618() == 0)
    {
        func_08008B58(0xBB);
        return;
    }
    func_08008B58(0x304);
}
