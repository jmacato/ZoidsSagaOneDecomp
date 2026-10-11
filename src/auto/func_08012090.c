#include "m2c.h"

M2C_UNK func_08008B58(s32);
s32 func_08037048(u16);
M2C_UNK func_0803785C(u16);

void func_08012090(u16 arg0, s32 arg1, s32 arg2)
{
    u16 temp_r4;

    temp_r4 = arg0;
    if (func_08037048(temp_r4) != 0)
    {
        func_08008B58(arg2);
        return;
    }
    func_08008B58(arg1);
    func_0803785C(temp_r4);
}
