#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0x90]; s32 f_90; s32 f_94; } D_03004BBC;

M2C_UNK func_08000F88(M2C_UNK);

void func_08021814(void)
{
    if (((u32) (D_03004BBC.f_90 + 0xFE880000) <= 0x200000U) && (D_03004BBC.f_94 == 0xE00000))
    {
        D_02000000.f_0 = 0x0802185D;
        func_08000F88(0x1C9);
    }
}
