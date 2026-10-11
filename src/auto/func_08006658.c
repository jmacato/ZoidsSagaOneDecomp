#include "m2c.h"

s32 func_08001040(s32);
M2C_UNK func_08008B58(s32);

void func_08006658(void)
{
    if ((func_08001040(0x120) != 0) && (func_08001040(0x121) != 0))
    {
        func_08008B58(0x2D);
        return;
    }
    func_08008B58(0x2DD);
}
