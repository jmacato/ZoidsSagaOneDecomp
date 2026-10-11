#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_08020D20(void)
{
    func_08008B70(2, 0xE, 0xF);
    func_08011F18(2, 0x130, 0xF0, 0x10, 1, 0);
    func_08011F18(2, 0x130, 0xE0, 0x10, 1, 0);
    func_08000BD8(3, 3);
}
