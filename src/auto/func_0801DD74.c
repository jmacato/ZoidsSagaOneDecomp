#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08011E08();
M2C_UNK func_08012040(M2C_UNK, s32);

void func_0801DD74(void)
{
    func_08011E08();
    func_08012040(0x086692F0, 0x17);
    func_08001A08(5);
    D_02000B54.f_0 = 0;
    func_080019B4(5);
    D_03004BBC.f_E8 = 1;
    D_02000000.f_0 = 0x08011E05;
    func_08003D78(3, 0x0801DDC9);
}
