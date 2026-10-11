#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08000F88(s32);
s32 func_08001040(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08008B58(s32);

s32 func_0800CB84(void)
{
    func_08008B58(0x2E);
    if ((func_08001040(0x122) == 0) && (func_08001040(0x120) != 0) && (func_08001040(0x121) != 0))
    {
        func_08000F88(0x122);
        D_03004BBC.f_E8 = 1;
        D_02000000.f_0 = 0x0800C4D1;
        return func_08003D78(3, 0x0800CC95);
    }
}
