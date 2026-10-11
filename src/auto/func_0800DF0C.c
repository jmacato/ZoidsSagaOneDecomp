#include "m2c.h"

extern struct { u8 pad_0[0x7F8]; u16 f_7F8; } D_03004BBC;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080019EC(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0800DF0C(void)
{
    D_03004BBC.f_7F8 &= 0xFBFF;
    func_08000BD8(0xF, 0);
    D_03004BBC.f_7F8 |= 0x400;
    func_080019EC(0x5A);
    if (!(4 & D_03004BBC.f_7F8))
    {
        do
        {
            func_0805EE78(1);
        } while (!(4 & D_03004BBC.f_7F8));
    }
    func_08008B70(0xE, 0xFF, 0xFF);
    func_08003DD8(5);
}
