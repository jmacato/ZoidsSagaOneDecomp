#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_0801FAE8(void)
{
    func_08011F18(0, 0x120, 0x50, 0x10, 1, 1);
    func_08011F18(0, 0x140, 0x50, 0x10, 1, 1);
    func_08000BD8(1, 0);
}
