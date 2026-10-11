#include "types.h"

struct Entry
{
    u8 zoid;
    u8 pilot;
    u8 pad_2[2];
};

struct Turn
{
    u8 side;
    u8 slot;
    u8 pad_2[2];
};

extern struct
{
    u8 pad_0[0x21F1];
    u8 count;
    u8 pad_21F2[2];
    struct Turn turns[6];
} D_0200EB84;
extern struct
{
    u8 pad_0[0x3600];
    struct Entry entries[6];
} D_02000B5C;

s32 func_08032A88(u8, u8);

void func_0803C838(u32 flags)
{
    u8 count;
    u8 i;

    if (flags & 0x2000)
    {
        D_0200EB84.count = 0;
        count = 0;
        for (i = 0; i < 6; i++)
        {
            if (func_08032A88(0, i) == 0 && D_02000B5C.entries[i].zoid != 0xFF && D_02000B5C.entries[i].pilot != 0)
            {
                D_0200EB84.count++;
                D_0200EB84.turns[count].side = 0;
                D_0200EB84.turns[count].slot = i;
                count++;
            }
        }
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            if (D_02000B5C.entries[i].pilot == 0)
            {
                D_0200EB84.count = 1;
                D_0200EB84.turns[0].side = 0;
                D_0200EB84.turns[0].slot = i;
            }
        }
    }
}
