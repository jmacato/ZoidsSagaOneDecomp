#include "types.h"
u16 func_0804CFFC(s32 *values, u16 index)
{
    if (values[index + 1] != 0)
        index++;
    else
        index = 0;
    return index;
}
