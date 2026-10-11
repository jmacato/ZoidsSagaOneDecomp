#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_0805EE78(s32);

void func_080131B0(void)
{
    func_0805EE78(0x20);
    func_08008B58(0x77);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x08012351;
    D_03004BBC.f_E8 = 0;
}
