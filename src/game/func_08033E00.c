#include "types.h"

struct Entry
{
    u8 id;
    u8 pad_1[3];
};

extern struct
{
    u8 pad_0[0x3600];
    struct Entry entries[6];
} D_02000B5C;

s32 func_08033E00(void)
{
    s32 found = 0;
    u8 i;

    for (i = 0; i <= 5; i++)
    {
        if (D_02000B5C.entries[i].id != 0xFF)
        {
            found = 1;
            break;
        }
    }
    return found;
}
