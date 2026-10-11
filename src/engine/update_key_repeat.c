#include "types.h"

struct KeyRepeat
{
    u8 history;
    u8 timer;
    u8 pad_2[2];
};

extern u16 D_03002358;
extern struct KeyRepeat D_0300235C[];

u16 update_key_repeat(u8 delay, u8 rate)
{
    u16 result = 0;
    u16 keys = D_03002358;
    u16 i;

    for (i = 0; i < 10; i++)
    {
        if (keys & 1)
        {
            u32 history = (D_0300235C[i].history << 1) | 1;

            D_0300235C[i].history = history;
            if ((history & 3) == 1)
            {
                D_0300235C[i].timer = delay;
                result |= 0x400;
            }
            else if (--D_0300235C[i].timer == 0xFF)
            {
                D_0300235C[i].timer = rate;
                result |= 0x400;
            }
        }
        else
        {
            D_0300235C[i].history <<= 1;
        }
        keys >>= 1;
        result >>= 1;
    }
    return result;
}
