#include "types.h"

s32 func_08005E5C(u16 value)
{
    s32 result = 0;

    if ((value & 0xFF00) == 0xFE00)
        result = 1;
    return result;
}
