#include "m2c.h"

extern struct { u8 pad_0[0xD6]; u16 f_D6; u16 f_D8; } D_03004BBC;

s32 func_08001040(M2C_UNK);
M2C_UNK func_080076C0(s32, u16, u16, s32, s32);
M2C_UNK func_0800802C();

void func_08012408(void)
{
    func_0800802C();
    if (func_08001040(0x145) == 0)
    {
        func_080076C0(0x20, D_03004BBC.f_D6, D_03004BBC.f_D8, 0xA, 0x08666E24);
    }
}
