#include "types.h"

struct Unit
{
    u8 pad_0[0xE];
    u8 size;
};

s32 func_08038ECC(struct Unit *unit, u8 value)
{
    u8 low;
    u8 high;
    s32 result;

    switch (unit->size)
    {
    case 0:
        low = 1;
        high = 1;
        break;
    case 1:
        low = 1;
        high = 2;
        break;
    case 2:
        low = 1;
        high = 3;
        break;
    case 3:
        low = 2;
        high = 2;
        break;
    case 4:
        low = 2;
        high = 3;
        break;
    case 5:
        low = 3;
        high = 3;
        break;
    }
    result = 0;
    if (low <= value && value <= high)
        result = 1;
    return result;
}
