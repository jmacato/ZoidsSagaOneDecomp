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
void func_08000F88(s32);
void func_080019B4(s32);
void func_08000BD8(s32, s32);
void func_0800BEE4(void);
void func_0800C708(void);
void func_0800C4D0(void);
void func_08010514(void);
void func_08003D78(s32, void *);

void func_080104A0(void)
{
    s32 result;

    if (func_08001040(0x128) == 0 || (result = func_08001040(0x129)) != 0)
    {
        func_0800BEE4();
    }
    else
    {
        func_08000F88(0x129);
        func_080019B4(4);
        D_02000000.second = func_0800C708;
        D_02000000.counter = result;
        func_08000BD8(1, 0);
        D_02000000.first = func_0800C4D0;
        func_08003D78(3, func_08010514);
        D_03004BBC.field_E8 = 1;
    }
}
