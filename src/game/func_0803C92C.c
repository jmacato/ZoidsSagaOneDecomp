#include "types.h"

struct Side
{
    u8 pad_0[0x10D4];
    u8 order[4];
};

extern struct Side D_0200EB84[];

u8 func_0803C92C(u8 side, u8 value)
{
    u8 result = 0xFF;
    u8 i;

    for (i = 0; i <= 5; i++)
    {
        if (D_0200EB84[side].order[i] == value)
        {
            result = i;
            break;
        }
    }
    return result;
}
