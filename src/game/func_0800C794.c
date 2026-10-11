#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern struct
{
    u8 pad_0[0x148];
    u16 field_148;
    u8 pad_14A[0x26];
    u16 field_170;
    u8 pad_172[8];
    u16 field_17A;
    u16 field_17C;
    u16 field_17E;
    u8 pad_180[0xC];
    u32 field_18C;
    u8 pad_190[0x14];
    s32 field_1A4;
} D_03004BBC;

extern struct
{
    u8 pad_0[0x18];
    u16 delay;
} D_0200000C;

extern u8 D_0832A718[];

s32 func_08001040(s32);
void func_0800BEE4(void);
void func_080099B4(void);
void func_08000F88(s32);
void func_080079E8(s32, s32, s32, s32, u8 *);
void func_0800C708(void);
void func_0800C4D0(void);
void func_0800C854(void);
void func_08001D04(s32);
void func_08003D78(s32, void *);

void func_0800C794(void)
{
    s32 result = func_08001040(0x11F);

    if (result != 0)
    {
        func_0800BEE4();
    }
    else
    {
        func_080099B4();
        func_08000F88(0x11F);
        func_080079E8(4, 6, 2, 5, D_0832A718);
        D_02000000.second = func_0800C708;
        D_02000000.counter = result;
        D_03004BBC.field_1A4++;
        func_08001D04(1);
        D_02000000.first = func_0800C4D0;
        func_08003D78(3, func_0800C854);
        D_03004BBC.field_170 = 10;
        D_03004BBC.field_17A = 3;
        D_03004BBC.field_17C = 4;
        D_03004BBC.field_18C = 0x8000;
        D_03004BBC.field_17E = D_0200000C.delay << 4;
        D_03004BBC.field_148 = result;
    }
}
