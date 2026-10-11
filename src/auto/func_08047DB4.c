#include "m2c.h"

extern u8 D_020143DC[];
extern u8 D_05000200[];

M2C_UNK func_0805D26C(s32, s32, s32);

void func_08047DB4(u16 arg0, u8 arg1, u8 arg2)
{
    s32 var_r3;
    u16 temp_r0;

    temp_r0 = arg0;
    if ((u32) temp_r0 <= 0xFU)
    {
        var_r3 = (temp_r0 << 5) + 0x05000000;
    }
    else
    {
        var_r3 = ((temp_r0 - 0x10) << 5) + D_05000200;
    }
    func_0805D26C(var_r3, (arg2 << 5) + D_020143DC, arg1 * 8);
}
