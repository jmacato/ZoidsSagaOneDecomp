#include "m2c.h"

M2C_UNK func_08000F88(s32);
M2C_UNK func_08000FD8(u8);
s32 func_0804CED0(s32, M2C_UNK);

void func_0804CF68(void)
{
    u8 var_r4;

    var_r4 = 0;
    do
    {
        func_08000FD8(var_r4);
        var_r4 += 1;
    } while ((u32) var_r4 <= 0x1DU);
    if ((func_0804CED0(0, 0x08705548) << 0x10) != 0)
    {
        func_08000F88(0);
    }
    if ((func_0804CED0(5, 0x08705868) << 0x10) != 0)
    {
        func_08000F88(5);
    }
    if ((func_0804CED0(0xA, 0x08705B88) << 0x10) != 0)
    {
        func_08000F88(0xA);
    }
    if ((func_0804CED0(0xF, 0x08705EA8) << 0x10) != 0)
    {
        func_08000F88(0xF);
    }
    if ((func_0804CED0(0x19, 0x087061C8) << 0x10) != 0)
    {
        func_08000F88(0x19);
    }
}
