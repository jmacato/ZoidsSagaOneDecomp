#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern u8 D_0832AEF8[];

s32 func_08001040(s32);
void func_08009A14(void);
void func_08000F88(s32);
void func_080079E8(s32, s32, s32, s32, u8 *);
void func_0800BEE4(void);
void func_0800C708(void);
void func_0800C4D0(void);
void func_080254D0(void);
void func_08003D78(s32, void *);

void func_08025468(void)
{
    s32 result = func_08001040(0x12F);

    if (result == 0)
    {
        func_08009A14();
        func_08000F88(0x12F);
        func_080079E8(0x11A, 0xA, 0x12, 5, D_0832AEF8);
        D_02000000.second = func_0800C708;
        D_02000000.counter = result;
        D_02000000.first = func_0800C4D0;
        func_08003D78(3, func_080254D0);
    }
    else
    {
        func_0800BEE4();
    }
}
