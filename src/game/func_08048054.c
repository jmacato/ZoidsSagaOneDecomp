#include "types.h"

s32 func_08048054(u16 base, s32 value, u8 kind)
{
    switch (kind)
    {
    case 0:
        value = base;
        break;
    case 1:
        value = (u16)(base + 24);
        break;
    case 2:
        value = (u16)(base + 48);
        break;
    }
    return value;
}
