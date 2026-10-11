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
    u8 pad_DA[0xE];
    u16 field_E8;
} D_03004BBC;

extern u8 D_0832AC68[];

s32 func_08001040(s32);
void func_080079E8(s32, s32, s32, s32, u8 *);
void func_0800BEE4(void);
void func_0800C708(void);
void func_0800C4D0(void);
void func_08010754(void);
void func_08003D78(s32, void *);

void func_080106C4(void)
{
    s32 result = func_08001040(0x12B);

    if (result != 0)
    {
        func_0800BEE4();
    }
    else
    {
        func_080079E8(0xC, D_03004BBC.x, D_03004BBC.y, 4, D_0832AC68);
        D_02000000.second = func_0800C708;
        D_02000000.counter = result;
        D_02000000.first = func_0800C4D0;
        func_08003D78(3, func_08010754);
        D_03004BBC.field_E8 = result;
    }
}

void func_08010734(void)
{
    D_02000000.first = func_0800C4D0;
    func_08003D78(3, func_08010754);
}
