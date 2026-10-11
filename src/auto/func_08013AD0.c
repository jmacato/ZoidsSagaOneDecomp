#include "m2c.h"

extern struct { u16 f_0; u16 f_2; u16 f_4; } D_02007560;

M2C_UNK func_08000F88(M2C_UNK);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_08006E08();
M2C_UNK func_08007188(u16, u16, u16, s32);
s32 func_08008D28(s32);

void func_08013AD0(void)
{
    if (func_08008D28(4) == 1)
    {
        func_08006E08();
        func_08007188(D_02007560.f_0, D_02007560.f_2, D_02007560.f_4, 0);
        func_080014A8(0, 0x0800BEC9);
        return;
    }
    func_08000F88(0x153);
    func_08007188(0x26U, 5U, 8U, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
