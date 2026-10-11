#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08000F88(s32);
s32 func_08001040(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_0800BEE4();

void func_0801EDB0(void)
{
    func_0800BEE4();
    if ((func_08001040(0x1AD) != 0) && (func_08001040(0x1AE) == 0))
    {
        func_080076C0(0xDD, 7, 9, 2, 0x08669EA4);
        D_03004BBC.f_E8 = 1;
        D_02000000.f_0 = 0x08011E05;
        func_08003D78(3, 0x0801FC8D);
        func_08000F88(0x1AE);
    }
}
