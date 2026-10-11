#include "m2c.h"

extern struct { u8 pad_0[0x18]; u16 f_18; } D_0200000C;
extern struct { u8 pad_0[0x1D0]; s16 f_1D0; u8 pad_1D2[0x26]; u16 f_1F8; u8 pad_1FA[0x8]; s16 f_202; s16 f_204; s16 f_206; u8 pad_208[0xC]; s32 f_214; } D_03004BBC;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0800E5C8(void)
{
    D_03004BBC.f_1F8 = 0xA;
    D_03004BBC.f_202 = 0x12;
    D_03004BBC.f_204 = 9;
    D_03004BBC.f_214 = 0x10000;
    D_03004BBC.f_206 = D_0200000C.f_18 * 8;
    D_03004BBC.f_1D0 = 1;
    do
    {
        func_0805EE78(1);
    } while (D_03004BBC.f_1F8 != 1);
    func_08008B70(2, 0x20, 9);
    func_08000BD8(3, 2);
    func_08003DD8(5);
}
