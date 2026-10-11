#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E24();
M2C_UNK func_0805EE78(s32);

void func_0801B068(void)
{
    func_08008B70(5, 0xFF, 0xFF);
    func_08008B70(6, 8, 2);
    func_08011E24();
    func_08008B58(0x18A);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x0801B0B1;
loop_1:
    func_0805EE78(1);
    goto loop_1;
}
