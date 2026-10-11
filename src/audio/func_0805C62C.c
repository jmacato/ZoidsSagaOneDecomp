#include "types.h"

extern const u8 D_085662A8[];
extern const u8 D_0856620C[];
extern const s16 D_08566290[];

u32 func_0805C62C(u8 chan_num, u8 key, u8 fine_adjust)
{
    if (chan_num == 4)
    {
        if (key <= 20)
        {
            key = 0;
        }
        else
        {
            key -= 21;
            if (key > 59)
                key = 59;
        }

        return D_085662A8[key];
    }
    else
    {
        s32 val1;
        s32 val2;

        if (key <= 35)
        {
            fine_adjust = 0;
            key = 0;
        }
        else
        {
            key -= 36;
            if (key > 130)
            {
                key = 130;
                fine_adjust = 255;
            }
        }

        val1 = D_0856620C[key];
        val1 = D_08566290[val1 & 0xF] >> (val1 >> 4);

        val2 = D_0856620C[key + 1];
        val2 = D_08566290[val2 & 0xF] >> (val2 >> 4);

        return val1 + ((fine_adjust * (val2 - val1)) >> 8) + 2048;
    }
}
