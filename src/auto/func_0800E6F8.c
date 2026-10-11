#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xD6]; u16 f_D6; u8 pad_D8[0x10]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08000F88(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_0805EE78(s32);

void func_0800E6F8(void)
{
    if (D_03004BBC.f_D6 != 0x17)
    {
        do
        {
            func_0805EE78(1);
        } while (D_03004BBC.f_D6 != 0x17);
    }
    func_08000F88(0x126);
    D_03004BBC.f_E8 = 1;
    func_0805EE78(0x1E);
    func_08008B58(0x43);
    func_0805EE78(0x1E);
    D_03004BBC.f_E8 = 0;
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
}
