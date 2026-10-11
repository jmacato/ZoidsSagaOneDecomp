#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern struct
{
    u8 pad_0[0xD6];
    u16 x;
    u16 y;
} D_03004BBC;

extern u8 D_0832B04C[];

s32 func_08001040(s32);
void func_080079E8(s32, s32, s32, s32, u8 *);
void func_0800BEE4(void);
void func_0800C708(void);
void func_0800C4D0(void);
void func_0802636C(void);
void func_08003D78(s32, void *);

void func_08026304(void)
{
    s32 result = func_08001040(0x130);

    if (result != 0)
    {
        func_0800BEE4();
    }
    else
    {
        u16 x = D_03004BBC.x;
        u16 y = D_03004BBC.y;

        func_080079E8(0x127, x, y, 4, D_0832B04C);
        D_02000000.second = func_0800C708;
        D_02000000.counter = result;
        D_02000000.first = func_0800C4D0;
        func_08003D78(3, func_0802636C);
    }
}
