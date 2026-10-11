#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08000F88(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);

void func_08017014(void)
{
    D_03004BBC.f_E8 = 1;
    D_02000000.f_0 = 0x08011E05;
    func_08003D78(3, 0x08018189);
    func_08000F88(0x172);
}
