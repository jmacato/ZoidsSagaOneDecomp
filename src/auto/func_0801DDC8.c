#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0x330]; u16 f_330; } D_03004BBC;

M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08011E24();
M2C_UNK func_0805EE78(s32);

void func_0801DDC8(void)
{
    func_08011E24();
    func_08008B58(0x1C4);
    func_08008B58(0x1C5);
    D_03004BBC.f_330 |= 0x400;
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x0801DE1D;
loop_1:
    func_0805EE78(1);
    goto loop_1;
}
