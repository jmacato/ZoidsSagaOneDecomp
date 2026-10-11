#include "types.h"

u16 func_0804C024(u16 code)
{
    if (code == 0x814A)
        return 0xFFFF;
    if (code == 0x814B)
        return 0xFFFE;
    return code;
}
