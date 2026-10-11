#include "m2c.h"

extern struct { u8 pad_0[0x170]; s16 f_170; } D_03004BBC;

M2C_UNK func_08000F88(M2C_UNK);
M2C_UNK func_08008B58(s32);
M2C_UNK func_0803E024(s32, s32, s32);

void func_0802AA14(void)
{
    func_0803E024(0, 0x140, 0xB4);
    func_08008B58(0x2D0);
    func_08000F88(0x13D);
    D_03004BBC.f_170 = 1;
}
