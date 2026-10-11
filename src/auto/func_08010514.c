#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xE8]; s16 f_E8; } D_03004BBC;

M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008324(s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_0805EE78(s32);

void func_08010514(void)
{
    u16 var_r4;
    u16 var_r4_2;

    var_r4 = 0;
    do
    {
        func_08008324(0, 0xFFFE0000);
        func_0805EE78(1);
        var_r4 += 1;
    } while ((u32) var_r4 <= 0x63U);
    var_r4_2 = 0;
    do
    {
        func_08008324(0, 0x20000);
        func_0805EE78(1);
        var_r4_2 += 1;
    } while ((u32) var_r4_2 <= 0x63U);
    func_0805EE78(0x3C);
    func_08008B58(0x51);
    func_0805EE78(0x3C);
    D_03004BBC.f_E8 = 0;
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
}
