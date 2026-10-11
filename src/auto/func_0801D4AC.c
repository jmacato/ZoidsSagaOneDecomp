#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0x90]; u32 f_90; u32 f_94; } D_03004BBC;

M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, u32, u32, M2C_UNK);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_08011E08();

void func_0801D4AC(void)
{
    func_08008B58(0x1B3);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xB0, (u32) D_03004BBC.f_90 >> 0x15, (u32) D_03004BBC.f_94 >> 0x15, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
