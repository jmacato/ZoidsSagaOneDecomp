#include "types.h"

extern s32 D_087064E8[];

u16 func_0804CCF0(s32 value)
{
    u16 i = 0;

    if (D_087064E8[0] != value)
    {
        do
        {
            i++;
            if (i > 0x56)
                break;
        } while (D_087064E8[i] != value);
    }
    return i;
}
