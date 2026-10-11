#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_0800BEE4();

void func_08017138(void)
{
    func_0800BEE4();
    func_08001A08(8);
    D_02000B54.f_0 = 0;
    func_080019B4(8);
    D_03004BBC.f_E8 = 1;
    D_02000000.f_0 = 0x08011E05;
    func_08003D78(3, 0x080185AD);
    func_08008B70(0, 0x16, 0x18);
}
