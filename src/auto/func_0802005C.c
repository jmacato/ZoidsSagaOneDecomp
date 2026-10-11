#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_0802005C(void)
{
    func_08008B70(5, 7, 8);
    func_08011F18(5, 0x70, 0x70, 0x10, 1, 0);
    func_08011F18(5, 0x60, 0x70, 0x10, 1, 0);
    func_08000BD8(6, 3);
}
