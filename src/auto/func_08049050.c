#include "m2c.h"

M2C_UNK func_08048C8C(u8, s32, s32, s32, s32, s32);
M2C_UNK func_08048DA0(u8, s32, s32, s32, s32, s32);

void func_08049050(void)
{
    u16 var_r4;

    func_08048C8C(8U, 0, 0, 0x1E, 0x1E, 0);
    func_08048DA0(0x18U, 1, 0, 0x1E, 0x1E, 0);
    var_r4 = 1;
    do
    {
        func_08048C8C((u8) (var_r4 + 8), 0, 8, 0, 0, 0x80000000);
        func_08048DA0((u8) (var_r4 + 0x18), 1, 0x18, 0, 0, 0x80000000);
        var_r4 += 1;
    } while ((u32) var_r4 <= 5U);
}
