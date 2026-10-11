#include "m2c.h"

s32 func_08001040(M2C_UNK);

s32 func_08009A2C(void)
{
    if ((*(u16 *)0x0200756A == 1) && (func_08001040(0x199) == 0))
    {
        return 1;
    }
    return 0;
}
