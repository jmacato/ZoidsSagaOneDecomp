#include "types.h"

u16 func_08048014(u16 from, u16 to, u8 mode)
{
    u16 delta;

    if (to < from)
        delta = from - to;
    else
        delta = to - from;
    switch (mode)
    {
    case 0:
        break;
    case 1:
        delta >>= 1;
        break;
    case 2:
        delta >>= 3;
        break;
    }
    if (to < from)
        delta += to;
    else
        delta = to - delta;
    return delta;
}
