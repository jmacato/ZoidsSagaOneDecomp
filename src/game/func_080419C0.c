#include "types.h"

u8 func_080419C0(u8 code, u16 flags)
{
    if (flags & 2)
    {
        switch (code)
        {
        case 8:
        case 10:
        case 11:
        case 15:
        case 16:
            break;
        case 9:
        case 12:
        case 13:
        case 14:
        default:
            return 7;
        }
    }
    return code;
}
