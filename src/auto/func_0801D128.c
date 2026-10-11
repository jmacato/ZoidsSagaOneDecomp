#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_0801D128(void)
{
    func_08008B70(1, 2, 8);
    func_08011F18(1, 0x20, 0x50, 0x10, 1, 1);
    func_08011F18(1, 0x70, 0x50, 0x10, 1, 1);
    func_08011F18(1, 0x70, 0x30, 0x10, 1, 1);
    func_08000BD8(2, 3);
}
