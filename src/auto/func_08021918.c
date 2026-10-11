#include "m2c.h"

void func_08021918(u16 *arg0, s16 *arg1, s16 *arg2)
{
    if ((u32) (u16) (*arg0 - 0xEC) <= 1U)
    {
        *arg0 = 0xEC;
        *arg1 = 0xC;
        *arg2 = 0x10;
    }
}
