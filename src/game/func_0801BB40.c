#include "types.h"

extern struct
{
    void *first;
} D_02000000;

extern struct
{
    u8 pad_0[0xE8];
    u16 field_E8;
} D_03004BBC;

extern u16 D_02000B54;
extern u8 D_08669664[];

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_080076C0(s32, s32, s32, s32, u8 *);
void func_08001A08(s32);
void func_080019B4(s32);
void func_08000BD8(s32, s32);
void func_08011E04(void);
void func_0801DF6C(void);
void func_0801DFF8(void);
void func_08003D78(s32, void *);
void func_08000F88(s32);

void func_0801BB40(void)
{
    s32 result;

    func_0800BEE4();
    if (func_08001040(0x1A5) != 0 && (result = func_08001040(0x1A6)) == 0)
    {
        func_080076C0(0xC6, 0xE, 0x11, 1, D_08669664);
        func_08001A08(4);
        D_02000B54 = result;
        func_080019B4(4);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_0801DF6C);
        func_08000F88(0x1A6);
    }
    else if (func_08001040(0x1A5) == 0)
    {
        D_03004BBC.field_E8 = 1;
        func_08000BD8(1, 0);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_0801DFF8);
    }
}
