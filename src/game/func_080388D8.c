#include "types.h"

extern u8 D_0867E298[];

s32 func_080388D8(u8 value)
{
    u8 index = 0;
    s32 found = 0;

    while (D_0867E298[index] != 0)
    {
        if (D_0867E298[index] == value)
        {
            found = 1;
            break;
        }
        index++;
    }
    return found;
}
