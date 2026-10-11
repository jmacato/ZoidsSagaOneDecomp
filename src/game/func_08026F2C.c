#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

s32 func_08001040(s32);
void func_08008B70(s32, s32, s32);
void func_0800BEE4(void);
void func_0800C708(void);
void func_0800C4D0(void);
void func_08026F7C(void);
void func_08003D78(s32, void *);

void func_08026F2C(void)
{
    s32 result = func_08001040(0x133);

    if (result == 0)
    {
        func_08008B70(1, 4, 2);
        D_02000000.second = func_0800C708;
        D_02000000.counter = result;
        D_02000000.first = func_0800C4D0;
        func_08003D78(3, func_08026F7C);
    }
    else
    {
        func_0800BEE4();
    }
}
