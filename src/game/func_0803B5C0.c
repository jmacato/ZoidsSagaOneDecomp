#include "types.h"

extern struct
{
    u8 pad_0[0x349C];
    u8 values[6];
} D_02000B5C;

s32 func_0803B5C0(u8 value)
{
    s32 found = 0;
    u8 i;

    for (i = 0; i <= 5; i++)
    {
        if (D_02000B5C.values[i] == value)
        {
            found = 1;
            break;
        }
    }
    return found;
}
