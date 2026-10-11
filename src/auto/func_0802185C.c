#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0x90]; s32 f_90; s32 f_94; u8 pad_98[0x50]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08000F88(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);

void func_0802185C(void)
{
    if (((u32) (D_03004BBC.f_90 + 0xFE880000) <= 0x200000U) && (D_03004BBC.f_94 == 0xF00000))
    {
        D_03004BBC.f_E8 = 1;
        D_02000000.f_0 = 0x08011E05;
        func_08003D78(3, 0x080252E1);
        func_08000F88(0x1C8);
    }
}
