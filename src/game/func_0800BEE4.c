#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

void func_08008024(void);
void func_08008028(void);
s32 func_08003DD8(s32);

s32 func_0800BEE4(void)
{
    D_02000000.first = func_08008024;
    D_02000000.second = func_08008028;
    D_02000000.counter = 0;
    return func_08003DD8(3);
}
