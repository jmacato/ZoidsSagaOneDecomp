#include "types.h"

s32 func_08038E7C(u32 *flags, u8 x, u8 y)
{
    s32 result = 0;

    if (*flags & 1)
    {
        switch (x)
        {
        case 0:
        case 1:
        case 2:
            switch (y)
            {
            case 0:
            case 1:
            case 2:
                result = 1;
                break;
            case 3:
            case 4:
            case 5:
                result = 2;
                break;
            }
            break;
        case 3:
        case 4:
        case 5:
            switch (y)
            {
            case 0:
            case 1:
            case 2:
                result = 2;
                break;
            case 3:
            case 4:
            case 5:
                result = 3;
                break;
            }
            break;
        }
    }
    return result;
}
