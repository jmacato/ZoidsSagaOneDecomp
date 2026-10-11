#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xD6]; u16 f_D6; u16 f_D8; } D_03004BBC;

s32 func_08001040(s32);
M2C_UNK func_080076C0(s32, u16, u16, s32, s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_0800BEE4();

void func_08014B74(void)
{
    func_0800BEE4();
    if ((func_08001040(0x16B) != 0) && (func_08001040(0x16C) == 0))
    {
        func_080076C0(0x4D, D_03004BBC.f_D6, D_03004BBC.f_D8, 4, 0x08667518);
        D_02000000.f_0 = 0x08014BE1;
    }
    if (func_08001040(0x16B) != 0)
    {
        func_08008B70(1, 0xFF, 0xFF);
    }
}
