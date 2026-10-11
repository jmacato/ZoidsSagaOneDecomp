#include "types.h"

struct Object
{
    u8 pad_0[0x56];
    u16 field_56;
    u8 pad_58[0x30];
};

extern struct Object D_03004BBC[];

void func_0800AA34(u16 index)
{
    D_03004BBC[index].field_56 = 0;
}
