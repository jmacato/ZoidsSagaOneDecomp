#include "types.h"

struct Entry
{
    void *data;
    u8 pad_4[0xC];
};

u8 func_08044DD4(struct Entry *entries, u16 index)
{
    if (entries[index].data)
        return 1;
    return 0;
}
