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
extern u8 D_08667F90[];

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_080076C0(s32, s32, s32, s32, u8 *);
void func_08001A08(s32);
void func_080019B4(s32);
void func_08008B70(s32, s32, s32);
void func_08011E04(void);
void func_0801851C(void);
void func_08003D78(s32, void *);

void func_08017048(void)
{
    s32 result;

    func_0800BEE4();
    if (func_08001040(0x173) != 0 && (result = func_08001040(0x175)) == 0)
    {
        func_080076C0(0x6B, 0xB, 0xD, 2, D_08667F90);
        func_08001A08(9);
        D_02000B54 = result;
        func_080019B4(9);
        func_08008B70(0, 0xB, 0xC);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_0801851C);
    }
    if (func_08001040(0x175) != 0)
        func_08008B70(1, 0xFFFF, 0xFFFF);
}
