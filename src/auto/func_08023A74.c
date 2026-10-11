#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;
extern struct { u16 f_0; u16 f_2; u16 f_4; } D_02007560;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08000F88(s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08006DFC(s32);
M2C_UNK func_08006E08();
M2C_UNK func_08007188(u16, u16, u16, s32);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B70(s32, s32, s32);
s32 func_08008D28(s32);

void func_08023A74(void)
{
    if (func_08008D28(0x1F) == 1)
    {
        func_08006E08();
        func_08007188(D_02007560.f_0, D_02007560.f_2, D_02007560.f_4, 0);
        func_080014A8(0, 0x0800BEC9);
        return;
    }
    func_080076C0(0xF5, 0x15, 0x20, 7, 0x0866ADA4);
    func_08001A08(9);
    D_02000B54.f_0 = 0;
    func_080019B4(9);
    func_08008B70(0, 0x15, 0x20);
    func_08006DFC(0x13);
    func_08000F88(0x1C2);
    D_03004BBC.f_E8 = 1;
    D_02000000.f_0 = 0x08011E05;
    func_08003D78(3, 0x08023B19);
}
