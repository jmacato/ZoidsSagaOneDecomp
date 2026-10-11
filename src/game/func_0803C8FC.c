#include "types.h"

void func_0803C8FC(u32 *flags)
{
    u32 value = *flags;

    if (value & 1)
    {
        value = (value & ~1) | 2;
    }
    else if (value & 2)
    {
        value = (value & ~2) | 1;
    }
    else
    {
        return;
    }
    *flags = value;
}
