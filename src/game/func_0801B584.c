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

extern u8 D_086693E4[];

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_080076C0(s32, s32, s32, s32, u8 *);
void func_08008B70(s32, s32, s32);
void func_08011E04(void);
void func_0801C47C(void);
void func_0801B618(void);
void func_08003D78(s32, void *);
void func_08000F88(s32);

void func_0801B584(void)
{
    func_0800BEE4();
    if (func_08001040(0x195) != 0 && func_08001040(0x196) == 0)
    {
        func_080076C0(0xB1, 0x13, 5, 0xE, D_086693E4);
        func_08008B70(0, 0x13, 0x1C);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_0801C47C);
        func_08000F88(0x196);
    }
    else if (func_08001040(0x19C) == 0)
    {
        D_02000000.first = func_0801B618;
    }
}
