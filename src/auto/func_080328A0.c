#include "m2c.h"

s32 func_080355AC(u8);
M2C_UNK func_0803E488(M2C_UNK, u8);

void func_080328A0(u8 arg0)
{
    u8 temp_r4;

    temp_r4 = arg0;
    if ((0x20 & *(u16 *)0x0200EB84) && (func_080355AC(temp_r4) != 0))
    {
        func_0803E488(0x08675B68, 0x15U);
        return;
    }
    func_0803E488(0x0867640C, temp_r4);
}
