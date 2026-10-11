#include "m2c.h"

s32 func_080395E8(s32, s32);

void func_0803958C(s32 arg0, s32 *arg1)
{
    *arg1 = func_080395E8(0x32, arg0);
}

void func_080395A4(u16 *arg0, s32 *arg1)
{
    *arg1 = 0;
    *arg0 &= 0xBFFF;
}

void func_080395B8(u8 *arg0, s32 *arg1)
{
    *arg1 = 0;
    M2C_FIELD(arg0, u16 *, 0) = (u16) (0xBFFF & M2C_FIELD(arg0, u16 *, 0));
    M2C_FIELD(arg0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
}
