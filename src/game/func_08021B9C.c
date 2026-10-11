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
void func_08011E04(void);
void func_08021CEC(void);
void func_08003D78(s32, void *);

void func_08021B9C(void)
{
    if (func_08001040(0x1BE) == 0)
    {
        D_03004BBC.field_E8 = 1;
        D_02000000.counter |= 2;
        func_08000F88(0x1BE);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08021CEC);
    }
}
