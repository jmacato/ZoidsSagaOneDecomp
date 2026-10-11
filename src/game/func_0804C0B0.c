#include "types.h"

extern u16 D_086D6F1C[];
extern u16 D_086D6F6E[];
extern u16 D_086D6FC0[];
extern u16 D_086D6FD4[];

u16 func_0804C0B0(s32 unused, u16 code, u16 kind)
{
    u16 i;

    switch (kind)
    {
    case 0xFFFF:
        for (i = 0; i <= 0x28; i++)
        {
            if (D_086D6F6E[i] == code)
                code = D_086D6F1C[i];
        }
        break;
    case 0xFFFE:
        for (i = 0; i <= 9; i++)
        {
            if (D_086D6FD4[i] == code)
                code = D_086D6FC0[i];
        }
        break;
    }
    return code;
}
