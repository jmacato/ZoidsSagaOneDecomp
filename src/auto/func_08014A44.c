#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

s32 func_08001040(M2C_UNK);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_0800BEE4();

void func_08014A44(void)
{
    func_0800BEE4();
    if (func_08001040(0x15F) == 0)
    {
        func_080076C0(0x44, 0x15, 0xD, 2, 0x086674F0);
        D_03004BBC.f_E8 = 1;
        D_02000000.f_0 = 0x08011E05;
        func_08003D78(3, 0x08015499);
    }
}
