#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u16 f_0; u16 f_2; } D_02007574;

M2C_UNK func_08008B58(s32);

void func_08018FCC(void)
{
    func_08008B58(0x16C);
    if ((D_02007574.f_0 == 0) || (D_02007574.f_2 == 1))
    {
        D_02000000.f_0 = 0x08018FFD;
    }
}
