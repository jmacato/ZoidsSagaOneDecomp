#include "types.h"

struct Entry
{
    u16 id;
    u16 value;
    u8 pad_4[4];
};

extern struct Entry D_0832AE10[];

s32 func_0803723C(u16, s32, u16);

s32 func_08026614(u16 index)
{
    return func_0803723C(D_0832AE10[index].id, 0xE, D_0832AE10[index].value);
}
