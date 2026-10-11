#include "m2c.h"

M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_08015EA8(void)
{
    func_08011F18(7, 0x20, 0x10, 0x10, 1, 1);
    func_08011F18(7, 0x20, 0x20, 0x10, 1, 1);
    func_08008B70(7, 0xFF, 0xFF);
}
