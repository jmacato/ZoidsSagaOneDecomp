#include "types.h"

struct Counter
{
    u8 pad_0[0x50];
    u16 enabled;
    u8 pad_52[6];
    u16 count;
};

s32 func_08049B70(struct Counter *counter)
{
    if (counter->enabled == 0)
    {
        counter->count = counter->enabled;
        return 1;
    }
    counter->count++;
    return 0;
}
