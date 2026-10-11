#include "types.h"

s32 func_08036460(u16 *value, u16 amount)
{
    s32 result = 0;

    *value += amount;
    if (*value > 200)
    {
        *value = 200;
        result = 1;
    }
    return result;
}
