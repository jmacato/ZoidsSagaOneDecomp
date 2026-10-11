#include "types.h"

struct Entry
{
    u16 id;
    u8 pad_2[6];
};

extern struct Entry D_0832AE10[];

s32 func_0803723C(u16, s32, s32);

s32 func_0802A67C(u16 index)
{
    return func_0803723C(D_0832AE10[index].id, 6, 0);
}
