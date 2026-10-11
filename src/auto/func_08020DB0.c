#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_08020DB0(void)
{
    func_08008B70(0xA, 0x1F, 0xF);
    func_08011F18(0xA, 0x190, 0xF0, 0x10, 1, 0);
    func_08011F18(0xA, 0x190, 0xE0, 0x10, 1, 0);
    func_08000BD8(0xB, 2);
}
