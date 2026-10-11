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
extern u8 D_08667DB0[];

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_080076C0(s32, s32, s32, s32, u8 *);
void func_08008B70(s32, s32, s32);
void func_08011E04(void);
void func_08017648(void);
void func_08003D78(s32, void *);
void func_08001A08(s32);
void func_080019B4(s32);
void func_08000F88(s32);

void func_08016D20(void)
{
    s32 result;

    func_0800BEE4();
    if (func_08001040(0x16D) != 0 && (result = func_08001040(0x16E)) == 0)
    {
        func_080076C0(0x5E, 0x2F, 3, 2, D_08667DB0);
        func_08008B70(0, 0xFF, 0xFF);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08017648);
        func_08001A08(4);
        D_02000B54 = result;
        func_080019B4(4);
        func_08000F88(0x16E);
    }
}
