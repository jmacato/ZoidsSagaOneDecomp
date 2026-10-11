#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u16 f_0; u16 f_2; } D_02007574;

M2C_UNK func_08000F88(s32);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_08037424(s32);

void func_0801973C(void)
{
    func_08008B58(0x171);
    if ((D_02007574.f_0 != 0) && (D_02007574.f_2 != 1))
    {
        func_08037424(0x15);
        func_08000F88(0x190);
        D_02000000.f_0 = 0x0801977D;
    }
}
