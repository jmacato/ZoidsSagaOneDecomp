#include "types.h"

void func_080339F8(u8 value, u8 low, u8 high, u8 *flags)
{
    if (high - low <= 0)
    {
        *flags = 0;
        return;
    }
    *flags |= 3;
    if (value <= low)
        *flags &= ~1;
    else if (value >= high)
        *flags &= ~2;
}
