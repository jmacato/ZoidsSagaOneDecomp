#include "types.h"

struct Object
{
    u16 flags;
    u8 pad_2[0x2E];
    u16 field_30;
    u8 pad_32[0x28];
    u16 state;
    u8 pad_5C[0x2C];
};

extern struct Object D_03004BBC[];
extern struct
{
    u16 first;
    u16 second;
    u16 third;
} D_02007560;

void func_080089A0(u16, s32);
void func_080019EC(s32);
void func_0800BEC8(void);
void func_08001524(s32, void *);
void func_08006E08(void);
void func_08007188(u16, u16, u16, s32);
void func_080014A8(s32, void *);

void func_0800BC8C(u16 index)
{
    if (D_03004BBC[index].flags & 4)
    {
        if (D_03004BBC[index].state != 0xFD)
        {
            D_03004BBC[index].field_30 = 0;
            func_080089A0(index, 0xFD);
            D_03004BBC[index].flags |= 0x400;
            func_080019EC(0x5A);
        }
        else
        {
            D_03004BBC[index].flags = 0;
        }
    }
    if (index == 1 && D_03004BBC[1].flags == 0)
    {
        func_08001524(0, func_0800BEC8);
        func_08006E08();
        func_08007188(D_02007560.first, D_02007560.second, D_02007560.third, 0);
        func_080014A8(0, func_0800BEC8);
    }
}

void func_0800BD1C(void)
{
}
