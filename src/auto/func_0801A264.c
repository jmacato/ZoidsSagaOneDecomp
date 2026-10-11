#include "m2c.h"

extern struct { u8 pad_0[0x90]; u32 f_90; u32 f_94; } D_03004BBC;

M2C_UNK func_08016CA8(s32, s32, s32);

void func_0801A264(void)
{
    func_08016CA8(7, ((u32) D_03004BBC.f_90 >> 0x15) - 1, ((u32) D_03004BBC.f_94 >> 0x15) + 1);
}
