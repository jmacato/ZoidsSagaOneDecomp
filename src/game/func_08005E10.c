#include "types.h"

extern u16 D_03001ED4[];

void func_08005E10(void)
{
    u8 i;

    for (i = 0; i <= 11; i++)
        D_03001ED4[i] = 0;
}

s32 func_08005E2C(u8 *values, u16 count)
{
    s32 result = 1;
    u16 i;

    for (i = 0; i < count; i++)
    {
        if (values[i] == 0)
        {
            result = 0;
            break;
        }
    }
    return result;
}
