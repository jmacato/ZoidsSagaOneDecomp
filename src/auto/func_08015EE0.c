#include "m2c.h"

M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_08015EE0(void)
{
    func_08011F18(8, 0x20, 0x10, 0x10, 1, 1);
    func_08011F18(8, 0x20, 0x20, 0x10, 1, 1);
    func_08008B70(8, 0xFF, 0xFF);
}
