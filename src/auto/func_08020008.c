#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_08020008(void)
{
    func_08008B70(4, 7, 8);
    func_08011F18(4, 0x70, 0x60, 0x10, 1, 0);
    func_08011F18(4, 0xA0, 0x60, 0x10, 1, 0);
    func_08011F18(4, 0xA0, 0x30, 0x10, 1, 0);
    func_08000BD8(5, 2);
}
