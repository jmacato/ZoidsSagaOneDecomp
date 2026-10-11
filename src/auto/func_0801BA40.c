#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08000F88(s32);
s32 func_08001040(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_0800BEE4();

void func_0801BA40(void)
{
    func_0800BEE4();
    if ((func_08001040(0x1A1) != 0) && (func_08001040(0x1A2) == 0))
    {
        func_080076C0(0xD8, 0xF, 0x18, 1, 0x0866963C);
        D_03004BBC.f_E8 = 1;
        D_02000000.f_0 = 0x08011E05;
        func_08003D78(3, 0x0801D5E5);
        func_08000F88(0x1A2);
    }
}
