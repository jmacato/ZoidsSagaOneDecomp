#include "m2c.h"

extern struct { u8 pad_0[0xD6]; u16 f_D6; u16 f_D8; } D_03004BBC;

M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_08007188(s32, u16, u16, M2C_UNK);
M2C_UNK func_08011E08();

void func_0801977C(void)
{
    func_08011E08();
    func_08007188(0x95, D_03004BBC.f_D6, D_03004BBC.f_D8, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
