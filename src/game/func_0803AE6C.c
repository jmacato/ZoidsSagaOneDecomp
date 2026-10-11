#include "types.h"

struct Stage
{
    u8 first;
    u8 pad_1[0x1B];
    u8 second;
    u8 pad_1D[0x21F];
};

extern struct
{
    u8 pad_0[0x382C];
    struct Stage stages[1];
    u8 pad_3A68[0x3F0C - 0x3A68];
    u8 left;
    u8 right;
} D_02000B5C;

extern struct
{
    u16 flags;
    u8 field_2;
    u8 pad_3[2];
    u8 left;
    u8 pad_6[3];
    u8 right;
} D_02005C70;

void func_0803AE6C(void)
{
    u8 left = D_02000B5C.left;
    u8 right = D_02000B5C.right;

    D_02005C70.left = D_02000B5C.stages[left].first;
    D_02005C70.right = D_02000B5C.stages[right].second;
    D_02005C70.flags |= 0x8000;
    D_02005C70.field_2 = 0;
}
