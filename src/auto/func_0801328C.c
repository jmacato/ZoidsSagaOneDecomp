#include "m2c.h"

extern struct { u8 pad_0[0x1A]; u16 f_1A; } D_0200000C;
extern struct { s16 f_0; } D_02000B54;
extern struct { u16 f_0; u16 f_2; u16 f_4; } D_02007560;

M2C_UNK func_08000F88(M2C_UNK);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019B4(u16);
M2C_UNK func_08001A08(u16);
M2C_UNK func_08006E08();
M2C_UNK func_08007188(u16, u16, u16, s32);
s32 func_08008D28(s32);

void func_0801328C(void)
{
    if (func_08008D28(2) == 1)
    {
        func_08006E08();
        func_08007188(D_02007560.f_0, D_02007560.f_2, D_02007560.f_4, 0);
        func_080014A8(0, 0x0800BEC9);
        return;
    }
    func_08000F88(0x147);
    func_08007188(0x1EU, 0x1AU, 4U, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
    func_08001A08(D_0200000C.f_1A);
    D_02000B54.f_0 = 0;
    func_080019B4(D_0200000C.f_1A);
}
