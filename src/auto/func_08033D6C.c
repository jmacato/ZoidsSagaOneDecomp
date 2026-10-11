#include "m2c.h"

extern struct { u8 pad_0[0x3]; u8 f_3; } D_02005C70;
extern struct { u16 f_0; } D_0200EB84;

M2C_UNK func_080019B4(u8);

void func_08033D6C(void)
{
    if (0x20 & D_0200EB84.f_0)
    {
        D_02005C70.f_3 = 0x1DU;
    }
    func_080019B4(D_02005C70.f_3);
}
