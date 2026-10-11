#include "types.h"

struct Sprite
{
    u8 pad_0[0x4E];
    u16 field_4E;
    u16 field_50;
    u8 pad_52[4];
    u16 field_56;
    u8 pad_58[8];
    u16 field_60;
    u8 pad_62[8];
    u16 field_6A;
    u16 field_6C;
    u8 pad_6E[0x1A];
};

extern struct Sprite D_03004BBC[];

void func_0800A864(u16, s32, s32, u16, u16);

void func_0800AD9C(u16 index)
{
    D_03004BBC[index].field_56 = 0;
    if (D_03004BBC[index].field_6A == D_03004BBC[index].field_4E && D_03004BBC[index].field_6C == D_03004BBC[index].field_50)
        D_03004BBC[index].field_60 = 1;
    else
        func_0800A864(index, 0x40, 0, D_03004BBC[index].field_6A, D_03004BBC[index].field_6C);
}
