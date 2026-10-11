#include "types.h"

struct Grant
{
    u16 id;
    u8 kind;
    u8 count;
};

extern struct Grant *D_0867E1D8[];

void func_080372F8(u8);
void func_0803747C(void);

void func_08037450(u8 index)
{
    struct Grant *grant = D_0867E1D8[index];

    while (grant->kind != 0xFF)
    {
        func_080372F8(grant->kind);
        grant++;
    }
    func_0803747C();
}
