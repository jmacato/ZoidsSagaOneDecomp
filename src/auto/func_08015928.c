#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_08015928(void)
{
    func_08008B70(6, 4, 8);
    func_08011F18(6, 0x40, 0x10, 0x10, 1, 1);
    func_08011F18(6, 0x50, 0x10, 0x10, 1, 1);
    func_08000BD8(7, 1);
}
