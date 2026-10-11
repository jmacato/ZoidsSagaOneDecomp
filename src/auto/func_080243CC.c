#include "m2c.h"

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);

void func_080243CC(void)
{
    func_08011F18(2, 0xA0, 0x1A0, 0x20, 2, 1);
    func_08011F18(2, 0xA0, 0x1C0, 0x20, 2, 1);
    func_08000BD8(3, 2);
}
