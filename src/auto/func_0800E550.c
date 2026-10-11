#include "m2c.h"

extern struct { u8 pad_0[0x18]; u16 f_18; } D_0200000C;
extern struct { u8 pad_0[0x148]; s16 f_148; u8 pad_14A[0x26]; u16 f_170; u8 pad_172[0x8]; s16 f_17A; s16 f_17C; s16 f_17E; u8 pad_180[0xC]; s32 f_18C; } D_03004BBC;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0800E550(void)
{
    D_03004BBC.f_170 = 0xA;
    D_03004BBC.f_17A = 0x11;
    D_03004BBC.f_17C = 9;
    D_03004BBC.f_18C = 0x10000;
    D_03004BBC.f_17E = D_0200000C.f_18 * 8;
    D_03004BBC.f_148 = 1;
    do
    {
        func_0805EE78(1);
    } while (D_03004BBC.f_170 != 1);
    func_08008B70(1, 0x18, 9);
    func_08000BD8(2, 2);
    func_08003DD8(4);
}
