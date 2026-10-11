#include "types.h"

u8 func_08032A88(u8, u8);

void func_08033844(u8 *out, u8 value)
{
    u8 i;

    *out = 0;
    for (i = 0; i <= 5; i++)
    {
        if (func_08032A88(value, i))
        {
            *out = i;
            break;
        }
    }
}
