#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08000F88(s32);
s32 func_08001040(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_0800BEE4();

void func_08014918(void)
{
    func_0800BEE4();
    if (func_08001040(0x162) == 0)
    {
        func_080076C0(0x42, 8, 0x12, 8, 0x08667450);
        D_03004BBC.f_E8 = 1;
        D_02000000.f_0 = 0x08011E05;
        func_08003D78(3, 0x080157C1);
        func_08000F88(0x162);
    }
    if (func_08001040(0x164) != 0)
    {
        func_08008B70(2, 0xFF, 0xFF);
        func_08008B70(3, 0xFF, 0xFF);
        func_08008B70(4, 0xFF, 0xFF);
    }
    if (func_08001040(0x16A) != 0)
    {
        func_08008B70(1, 7, 1);
        func_08008B70(5, 9, 5);
    }
}
