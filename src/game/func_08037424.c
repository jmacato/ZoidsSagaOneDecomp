#include "types.h"

struct Grant
{
    u16 id;
    u8 kind;
    u8 count;
};

extern struct Grant *D_0867E1D8[];

void func_0803723C(u8, u16, u8);

void func_08037424(u8 index)
{
    struct Grant *grant = D_0867E1D8[index];

    while (grant->kind != 0xFF)
    {
        func_0803723C(grant->kind, grant->id, grant->count);
        grant++;
    }
}
