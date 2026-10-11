#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();

void func_0802028C(void)
{
    func_08011E24();
    func_08008B58(0x207);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xD9, 3, 0x16, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
