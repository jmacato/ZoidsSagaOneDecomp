#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08000F88(s32);
s32 func_08001040(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08006DFC(s32);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_0800BEE4();

void func_0801ED3C(void)
{
    func_0800BEE4();
    if ((func_08001040(0x1AC) != 0) && (func_08001040(0x1AD) == 0))
    {
        func_080076C0(0xDC, 0x12, 0xC, 5, 0x08669E40);
        D_03004BBC.f_E8 = 1;
        D_02000000.f_0 = 0x08011E05;
        func_08003D78(3, 0x0801F5D1);
        func_08006DFC(0x11);
        func_08000F88(0x1AD);
    }
}
