#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_08024390(void)
{
    func_08011F18(1, 0xC0, 0x1E0, 0x20, 2, 1);
    func_08011F18(1, 0x80, 0x1E0, 0x20, 2, 1);
    func_08000BD8(2, 0);
}
