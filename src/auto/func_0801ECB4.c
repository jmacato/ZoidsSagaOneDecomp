#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xD6]; u16 f_D6; u16 f_D8; u8 pad_DA[0xE]; s16 f_E8; } D_03004BBC;

s32 func_08001040(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_0800BEE4();

void func_0801ECB4(void)
{
    func_0800BEE4();
    if ((func_08001040(0x1B0) != 0) && (func_08001040(0x1B1) == 0) && (D_03004BBC.f_D6 == 0x16) && (D_03004BBC.f_D8 == 0x11))
    {
        func_080076C0(0xDA, 0x16, 0x11, 8, 0x08669DA0);
        D_03004BBC.f_E8 = 1;
        D_02000000.f_0 = 0x08011E05;
        func_08003D78(3, 0x0802033D);
    }
}
