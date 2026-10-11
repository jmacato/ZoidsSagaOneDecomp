#include "m2c.h"

M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_08018A64(void)
{
    func_08011F18(5, 0x570, 0x2C0, 0x10, 2, 1);
    func_08011F18(5, 0x5C0, 0x2D0, 0x10, 2, 1);
    func_08008B70(5, 0xFF, 0xFF);
}
