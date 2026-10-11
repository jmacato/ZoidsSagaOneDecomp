#include "types.h"

struct Entry
{
    u8 pad_0;
    u8 id;
    u8 pad_2[2];
};

extern struct
{
    u8 pad_0[0x3600];
    struct Entry entries[6];
} D_02000B5C;

u8 func_08037810(u8 id)
{
    u8 result = 0xFF;
    u8 i;

    for (i = 0; i <= 5; i++)
    {
        if (D_02000B5C.entries[i].id == id)
        {
            result = i;
            break;
        }
    }
    return result;
}
