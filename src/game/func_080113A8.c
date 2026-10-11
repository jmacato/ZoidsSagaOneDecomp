#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern u8 D_0832AD1C[];

s32 func_08001040(s32);
void func_080079E8(s32, s32, s32, s32, u8 *);
void func_080019B4(s32);
void func_0800BEE4(void);
void func_0800C708(void);
void func_0800C4D0(void);
void func_08011408(void);
void func_08003D78(s32, void *);

void func_080113A8(void)
{
    s32 result = func_08001040(0x12E);

    if (result != 0)
    {
        func_0800BEE4();
    }
    else
    {
        func_080079E8(0x17, 0, 3, 8, D_0832AD1C);
        func_080019B4(9);
        D_02000000.second = func_0800C708;
        D_02000000.counter = result;
        D_02000000.first = func_0800C4D0;
        func_08003D78(3, func_08011408);
    }
}
