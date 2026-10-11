#include "types.h"

struct Pair
{
    u16 first;
    u16 second;
};

struct PairTable
{
    struct Pair pairs[33];
};

extern const struct PairTable D_08328DAC;

s32 func_08037048(u8);
s32 func_08008B58(u16);
s32 func_080378C8(void);
s32 func_0803785C(u8);

s32 func_08009430(u8 index)
{
    struct PairTable table = D_08328DAC;

    if (func_08037048(index) == 0)
    {
        func_08008B58(table.pairs[index].first);
        if (index == 16)
            return func_080378C8();
        return func_0803785C(index);
    }
    return func_08008B58(table.pairs[index].second);
}
