#include "m2c.h"

extern struct { u8 pad_0[0x18]; u16 f_18; } D_0200000C;
extern struct { u8 pad_0[0x258]; s16 f_258; u8 pad_25A[0x26]; u16 f_280; u8 pad_282[0x8]; s16 f_28A; s16 f_28C; s16 f_28E; u8 pad_290[0xC]; s32 f_29C; } D_03004BBC;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0800E640(void)
{
    D_03004BBC.f_280 = 0xA;
    D_03004BBC.f_28A = 0x13;
    D_03004BBC.f_28C = 9;
    D_03004BBC.f_29C = 0x10000;
    D_03004BBC.f_28E = D_0200000C.f_18 * 8;
    D_03004BBC.f_258 = 1;
    do
    {
        func_0805EE78(1);
    } while (D_03004BBC.f_280 != 1);
    func_08008B70(3, 0x28, 9);
    func_08000BD8(4, 2);
    func_08003DD8(6);
}
