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

extern u8 D_08666DAC[];

void func_0800802C(void);
s32 func_08001040(s32);
void func_080076C0(s32, s32, s32, s32, u8 *);
void func_08011E04(void);
void func_08012EF8(void);
void func_080131B0(void);
void func_08003D78(s32, void *);
void func_08000F88(s32);

void func_08012350(void)
{
    func_0800802C();
    if (func_08001040(0x143) != 0 && func_08001040(0x144) == 0)
    {
        func_080076C0(0x1F, 0x16, 0x1D, 6, D_08666DAC);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08012EF8);
        func_08000F88(0x144);
    }
    else if (func_08001040(0x145) != 0 && func_08001040(0x146) == 0)
    {
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_080131B0);
        func_08000F88(0x146);
    }
}
