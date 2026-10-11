#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08000F88(s32);
M2C_UNK func_08000FD8(M2C_UNK);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08006DFC(s32);
M2C_UNK func_08008B58(M2C_UNK);

void func_08021168(void)
{
    func_08008B58(0x261);
    D_03004BBC.f_E8 = 1;
    D_02000000.f_0 = 0x08011E05;
    func_08003D78(3, 0x08024489);
    func_08006DFC(0x16);
    func_08000F88(0x1C6);
    func_08000FD8(0x199);
}
