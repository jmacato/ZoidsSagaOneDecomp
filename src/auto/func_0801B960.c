#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xD6]; u16 f_D6; u16 f_D8; } D_03004BBC;

s32 func_08001040(s32);
M2C_UNK func_080076C0(s32, u16, u16, s32, s32);
M2C_UNK func_0800BEE4();

void func_0801B960(void)
{
    func_0800BEE4();
    if ((func_08001040(0x1A9) != 0) && (func_08001040(0x1AA) == 0))
    {
        func_080076C0(0xBC, D_03004BBC.f_D6, D_03004BBC.f_D8, 5, 0x086695D8);
        D_02000000.f_0 = 0x0801B9B9;
    }
}
