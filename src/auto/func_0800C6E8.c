#include "m2c.h"

s32 func_08001650(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_0805EE78(s32);

void func_0800C6E8(void)
{
    while (func_08001650(1) == 0)
    {
        func_0805EE78(1);
    }
    func_08003DD8(4);
}
