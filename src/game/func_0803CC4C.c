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

extern struct
{
    u8 pad_0[0x21F0];
    u8 refresh;
} D_0200EB84;

void func_0803CC4C(void)
{
    u8 i;

    D_0200EB84.refresh = 2;
    for (i = 0; i <= 5; i++)
    {
        if (D_02000B5C.entries[i].id == 0)
        {
            D_0200EB84.refresh = 0xFF;
            break;
        }
    }
}
