#include "types.h"

extern u16 D_086D6F1C[];
extern u16 D_086D6FC0[];

s32 func_0804C054(u16 kind, u16 value)
{
    u16 i;

    switch (kind)
    {
    case 0xFFFF:
        for (i = 0; i <= 0x28; i++)
        {
            if (value == D_086D6F1C[i])
                return 1;
        }
        break;
    case 0xFFFE:
        for (i = 0; i <= 9; i++)
        {
            if (value == D_086D6FC0[i])
                return 1;
        }
        break;
    }
    return 0;
}
