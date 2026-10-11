#include "types.h"

struct Entry
{
    u8 table;
    u8 index;
    u8 pad_2[0x1A];
    u8 rank;
    u8 pad_1D[7];
};

struct Item
{
    u8 value;
    u8 pad_1[0x1B];
};

extern struct Entry *D_08683720[][12];
extern struct Entry D_02004A70[];
extern struct Item D_086787A4[][32];

u16 func_08001080(void);

u8 func_080328FC(u8 area, u8 group, u8 slot)
{
    struct Entry *entries;
    u8 picks[12];
    u8 count;
    u8 i;
    u16 roll;
    u8 rank;

    if (area > 10)
        area = 0;
    entries = D_08683720[area][group];
    roll = func_08001080() % 100;
    rank = 0;
    if (roll >= 60)
    {
        rank = 2;
        if (roll < 95)
            rank = 1;
    }
    count = 0;
    for (i = 0; i < 12; i++)
    {
        if (entries[i].rank == rank)
        {
            picks[count] = i;
            count++;
        }
    }
    if (count == 0)
    {
        picks[0] = count;
        count = 1;
    }
    roll = func_08001080() % count;
    if (roll >= count)
        roll = 0;
    entries = &entries[picks[roll]];
    if (slot < 127)
    {
        D_02004A70[slot] = *entries;
        return D_086787A4[entries->table][entries->index].value;
    }
    return 0xFF;
}
