#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

s32 func_08001040(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_0800802C();
M2C_UNK func_0800BEE4();

void func_08021FEC(void)
{
    func_0800BEE4();
    if ((func_08001040(0x1C6) != 0) && (func_08001040(0x1C7) == 0))
    {
        func_080076C0(0x102, 0xE, 4, 0xE, 0x0866A6EC);
        D_03004BBC.f_E8 = 1;
        D_02000000.f_0 = 0x08011E05;
        func_08003D78(3, 0x080245B5);
    }
}

void func_08022050(void)
{
    func_0800802C();
}
