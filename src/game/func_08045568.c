#include "types.h"

extern struct
{
    u8 pad_0[0xC7C];
    u16 first;
    u16 second;
    u16 third;
} D_03004BBC;

extern u16 D_086D41F8[];

void func_08045568(s32 unused, u16 index)
{
    D_03004BBC.first = D_086D41F8[index];
    D_03004BBC.second = D_086D41F8[index];
    D_03004BBC.third = (index + 1) << 10;
}
