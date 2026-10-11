#include "m2c.h"

extern struct { u8 pad_0[0x770]; u16 f_770; } D_03004BBC;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080019EC(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0800DEA4(void)
{
    D_03004BBC.f_770 &= 0xFBFF;
    func_08000BD8(0xE, 0);
    D_03004BBC.f_770 |= 0x400;
    func_080019EC(0x5A);
    if (!(4 & D_03004BBC.f_770))
    {
        do
        {
            func_0805EE78(1);
        } while (!(4 & D_03004BBC.f_770));
    }
    func_08008B70(0xD, 0xFF, 0xFF);
    func_08003DD8(4);
}
