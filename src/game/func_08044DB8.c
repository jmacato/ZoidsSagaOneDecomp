#include "types.h"

struct Entry
{
    s32 value;
    u8 pad_4[8];
};

s32 func_08044DB8(struct Entry *entries, u16 index)
{
    if (entries[index].value != 0)
        return 1;
    return 0;
}
