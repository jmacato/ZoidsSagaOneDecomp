#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
s32 func_08001040(M2C_UNK);
M2C_UNK func_0800BEE4();

void func_08021E64(void)
{
    func_0800BEE4();
    if (func_08001040(0x1BD) != 0)
    {
        func_08000BD8(2, 1);
    }
}
