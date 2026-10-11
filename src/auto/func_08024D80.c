#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_08024D80(void)
{
    func_0805EE78(0x20);
    func_08011F18(8, 0xE0, 0x60, 0x20, 2, 1);
    func_08000BD8(9, 3);
}
