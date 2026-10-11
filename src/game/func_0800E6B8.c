#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

s32 func_08001040(s32);
void func_0800BEE4(void);
void func_0800C708(void);
void func_0800C4D0(void);
void func_0800E6F8(void);
void func_08003D78(s32, void *);

void func_0800E6B8(void)
{
    s32 result = func_08001040(0x126);

    if (result != 0)
    {
        func_0800BEE4();
    }
    else
    {
        D_02000000.second = func_0800C708;
        D_02000000.counter = result;
        D_02000000.first = func_0800C4D0;
        func_08003D78(3, func_0800E6F8);
    }
}
