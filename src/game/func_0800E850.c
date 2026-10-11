#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern u8 D_0832AB3C[];

s32 func_08001040(s32);
void func_08000F88(s32);
void func_080079E8(s32, s32, s32, s32, u8 *);
void func_080019B4(s32);
void func_0800BEE4(void);
void func_0800C708(void);
void func_0800C4D0(void);
void func_0800E8B8(void);
void func_08003D78(s32, void *);

void func_0800E850(void)
{
    s32 result = func_08001040(0x128);

    if (result != 0)
    {
        func_0800BEE4();
    }
    else
    {
        func_08000F88(0x128);
        func_080079E8(0x18, 0x17, 0x1D, 8, D_0832AB3C);
        func_080019B4(6);
        D_02000000.second = func_0800C708;
        D_02000000.counter = result;
        D_02000000.first = func_0800C4D0;
        func_08003D78(3, func_0800E8B8);
    }
}
