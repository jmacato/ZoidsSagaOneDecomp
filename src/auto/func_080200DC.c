#include "m2c.h"

M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_080200DC(void)
{
    func_08011F18(5, 0x70, 0x70, 0x10, 1, 0);
    func_08011F18(5, 0x70, 0x80, 0x10, 1, 0);
    func_08008B70(5, 0xFF, 0xFF);
}
