#include "m2c.h"

M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_08016928(void)
{
    func_08008B70(2, 0x20, 0x14);
    func_08011F18(2, 0x400, 0x2A0, 0x20, 2, 1);
    func_08011F18(2, 0x3C0, 0x2A0, 0x20, 2, 1);
    func_08011F18(2, 0x3C0, 0x2C0, 0x20, 2, 1);
    func_08011F18(2, 0x380, 0x2C0, 0x20, 2, 1);
    func_08008B70(2, 0xFF, 0xFF);
}
