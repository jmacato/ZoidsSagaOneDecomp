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

extern u8 D_0832B114[];

void func_0800C708(void);
s32 func_08001040(s32);
void func_080079E8(s32, s32, s32, s32, u8 *);
void func_0800C4D0(void);
void func_08003D78(s32, void *);
void func_08027AAC(void);
void func_08027E8C(void);
void func_08008B70(s32, s32, s32);
void func_08000BD8(s32, s32);
void func_0800BEE4(void);

void func_080279C0(void)
{
    D_02000000.second = func_0800C708;
    D_02000000.counter = 0;
    if (!func_08001040(0x135))
    {
        func_080079E8(0x128, D_03004BBC.x, D_03004BBC.y, 0xE, D_0832B114);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_0800C4D0;
        func_08003D78(3, func_08027AAC);
    }
    else if (!func_08001040(0x136))
    {
        func_080079E8(0x128, 8, 5, 0xE, D_0832B114);
        func_08008B70(0, 8, 7);
        func_08008B70(2, 8, 4);
        func_08008B70(3, 8, 6);
        func_08008B70(4, 9, 5);
        func_08008B70(5, 7, 5);
        func_08000BD8(1, 0);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_0800C4D0;
        func_08003D78(3, func_08027E8C);
    }
    else
    {
        func_0800BEE4();
    }
}
