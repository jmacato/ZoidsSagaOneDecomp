#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08012040(s32, s32);

void func_0801B0B0(void)
{
    func_08011E08();
    func_08012040(3, 0x17);
    func_08008B70(2, 0xFF, 0xFF);
    func_08008B70(3, 0xFF, 0xFF);
    func_08008B70(4, 0xFF, 0xFF);
    D_03004BBC.f_E8 = 1;
    D_02000000.f_0 = 0x08011E05;
    func_08003D78(3, 0x0801B109);
}
