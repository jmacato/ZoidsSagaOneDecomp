#include "types.h"

struct Entry
{
    s32 value;
    s16 key;
    s16 extra;
};

void func_080325C8(s32 count, struct Entry *entries)
{
    s32 i;
    s32 j;

    for (i = 1; i < count; i++)
    {
        struct Entry entry = entries[i];

        for (j = i - 1; j >= 0 && entries[j].key > entry.key; j--)
            entries[j + 1] = entries[j];
        entries[j + 1] = entry;
    }
}
