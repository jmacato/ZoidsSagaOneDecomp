#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_08024F24(void)
{
    func_08008B70(0, 0xD, 8);
    func_08011F18(0, 0x50, 0x80, 0x10, 1, 0);
    func_08000BD8(1, 0);
}
