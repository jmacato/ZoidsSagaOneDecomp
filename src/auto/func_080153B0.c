#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_080153B0(void)
{
    func_08011F18(2, 0x140, 0xC0, 0x20, 2, 1);
    func_08011F18(2, 0x120, 0xC0, 0x20, 2, 1);
    func_08011F18(2, 0x120, 0x80, 0x20, 2, 1);
    func_08000BD8(3, 3);
}
