#include "m2c.h"

M2C_UNK func_080089A0(s32, s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_080184BC(void)
{
    func_080089A0(5, 0xA6);
    func_08011F18(4, 0x70, 0x30, 0x10, 1, 1);
    func_08011F18(4, 0x70, 0x70, 0x10, 1, 1);
    func_08011F18(4, 0x20, 0x70, 0x10, 1, 1);
    func_08011F18(4, 0x20, 0x80, 0x10, 1, 1);
    func_08008B70(4, 0xFF, 0xFF);
}
