#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);

void func_08020B98(void)
{
    func_08007188(0x106, 8, 2, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
    D_02000000.f_0 = 0x08008025;
}
