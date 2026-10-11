#include "types.h"

u8 func_080458A8(u8 code, u8 alternate)
{
    switch (code)
    {
    case 0:
    case 15:
    case 16:
        code = 0;
        break;
    case 2:
    case 17:
        code = 2;
        break;
    case 5:
        code = 5;
        if (alternate)
            code = 0xFF;
        break;
    case 6:
        code = 0;
        if (alternate)
            code = 5;
        break;
    case 7:
        code = 7;
        if (alternate)
            code = 5;
        break;
    case 8:
        code = 7;
        if (alternate)
            code = 0;
        break;
    case 9:
        code = 0xFE;
        if (alternate)
            code = 7;
        break;
    case 10:
        code = 10;
        if (alternate)
            code = 0xFF;
        break;
    case 11:
        code = 2;
        if (alternate)
            code = 10;
        break;
    case 12:
        code = 12;
        if (alternate)
            code = 10;
        break;
    case 13:
        code = 12;
        if (alternate)
            code = 2;
        break;
    case 14:
        code = 0xFF;
        if (alternate)
            code = 12;
        break;
    }
    return code;
}
