#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern struct
{
    u8 pad_0[0xE8];
    u16 field_E8;
} D_03004BBC;

s32 func_08001040(s32);
void func_0800BEE4(void);
void func_0800C708(void);
void func_0800C4D0(void);
void func_0801114C(void);
void func_08003D78(s32, void *);

void func_080110C8(void)
{
    if (func_08001040(0x12C) != 0 && func_08001040(0x12D) != 0)
    {
        func_0800BEE4();
    }
    else
    {
        D_02000000.second = func_0800C708;
        D_02000000.counter = 0;
        D_02000000.first = func_0800C4D0;
        func_08003D78(3, func_0801114C);
        D_02000000.counter |= 2;
        D_03004BBC.field_E8 = 1;
    }
}
