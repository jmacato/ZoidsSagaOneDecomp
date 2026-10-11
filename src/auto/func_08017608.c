#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_08017608(void)
{
    func_08008B70(2, 0xE, 2);
    func_08011F18(2, 0x30, 0x20, 0x10, 1, 1);
    func_08011F18(2, 0x30, 0x30, 0x10, 1, 1);
    func_08000BD8(3, 1);
}
