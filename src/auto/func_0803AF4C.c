#include "m2c.h"

M2C_UNK func_08001848(u8, s32, s32);
M2C_UNK func_0803E488(M2C_UNK, s32);

void func_0803AF4C(u8 arg0)
{
    u8 temp_r0;

    temp_r0 = arg0;
    if (temp_r0 != 0xFF)
    {
        func_08001848(temp_r0, 1, 0);
        return;
    }
    func_0803E488(0x08675C5C, 0x16);
}
