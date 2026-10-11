#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_08011E08();
M2C_UNK func_0805EE78(s32);

void func_08022A00(void)
{
    func_0805EE78(0x20);
    func_08008B58(0x22A);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x08022A3D;
loop_1:
    func_0805EE78(1);
    goto loop_1;
}
