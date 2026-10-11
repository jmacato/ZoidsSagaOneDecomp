#include "m2c.h"

extern struct { u8 pad_0[0x90]; u32 f_90; u32 f_94; } D_03004BBC;

M2C_UNK func_08016CA8(s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0801A2B0(void)
{
    func_0805EE78(4);
    func_08016CA8(9, ((u32) D_03004BBC.f_90 >> 0x15) + 1, ((u32) D_03004BBC.f_94 >> 0x15) + 1);
}
