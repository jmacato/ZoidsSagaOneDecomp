#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xD6]; u16 f_D6; u16 f_D8; u8 pad_DA[0xE]; s16 f_E8; } D_03004BBC;

s32 func_08001040(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_080076C0(s32, u16, u16, s32, s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_0800BEE4();

void func_08021940(void)
{
    func_0800BEE4();
    if ((func_08001040(0x1BC) != 0) && (func_08001040(0x1BD) != 0) && (func_08001040(0x1BE) != 0) && (func_08001040(0x1BF) != 0) && (func_08001040(0x1C0) != 0) && (func_08001040(0x1C1) != 0) && (func_08001040(0x1C2) == 0))
    {
        func_080076C0(0xF5, 0x15U, 0x20U, 6, 0x0866A674);
        func_08008B70(0, 0x15, 0x25);
        D_03004BBC.f_E8 = 1;
        D_02000000.f_0 = 0x08011E05;
        func_08003D78(3, 0x080239F1);
        return;
    }
    if (func_08001040(0x1C2) != 0)
    {
        func_080076C0(0xF6, D_03004BBC.f_D6, D_03004BBC.f_D8, 6, 0x08325FF0);
    }
}
