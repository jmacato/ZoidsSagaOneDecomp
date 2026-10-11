#include "m2c.h"

M2C_UNK func_08000F88(u16);
M2C_UNK func_08003948();
M2C_UNK func_0800BFE4(s32, u16);
M2C_UNK func_08037424(s32);
M2C_UNK func_080375B0(s32);
M2C_UNK func_080375F0();

void func_0800BF0C(u16 arg0)
{
    u16 var_r4;
    void *temp_r6;

    temp_r6 = (*(u8 *)0x02000030 * 0x88) + 0x02000034;
    if (!(4 & *(u16 *)0x03002358))
    {
        func_08003948();
        func_080375B0(0);
        func_08037424(0);
        func_080375F0();
    }
    if (2 & *(u16 *)0x03002358)
    {
        var_r4 = 0;
        do
        {
            func_08000F88(var_r4);
            var_r4 += 1;
        } while ((u32) var_r4 <= 0x1FFU);
    }
    func_0800BFE4(0, arg0);
    M2C_FIELD(temp_r6, s32 *, 0x18) = 1;
}
