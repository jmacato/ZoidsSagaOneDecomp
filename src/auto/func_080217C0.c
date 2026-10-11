#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0x90]; s32 f_90; s32 f_94; u8 pad_98[0x50]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08000F88(M2C_UNK);
M2C_UNK func_08003D78(s32, M2C_UNK);

void func_080217C0(void)
{
    if ((D_03004BBC.f_90 == 0x02180000) && (D_03004BBC.f_94 == 0xC00000))
    {
        D_03004BBC.f_E8 = 1;
        D_02000000.f_0 = 0x08011E05;
        func_08003D78(3, 0x080235F9);
        func_08000F88(0x1BB);
    }
}
