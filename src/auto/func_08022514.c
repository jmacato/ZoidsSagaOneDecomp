#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_08022514(void)
{
    func_08011F18(3, 0xA0, 0x30, 0x10, 1, 1);
    func_08011F18(3, 0xA0, 0x40, 0x10, 1, 1);
    func_08000BD8(4, 2);
}
