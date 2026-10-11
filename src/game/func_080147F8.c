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

extern u8 D_086673D8[];

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_080076C0(s32, s32, s32, s32, u8 *);
void func_08011E04(void);
void func_0801574C(void);
void func_080154FC(void);
void func_08003D78(s32, void *);
void func_08000F88(s32);
void func_08006DFC(s32);

void func_080147F8(void)
{
    func_0800BEE4();
    if (func_08001040(0x158) != 0 && func_08001040(0x161) == 0)
    {
        if (func_08001040(0x15E) == 0)
        {
            func_080076C0(0x3D, 0xE, 0x1F, 6, D_086673D8);
            D_03004BBC.field_E8 = 1;
            D_02000000.first = func_08011E04;
            func_08003D78(3, func_0801574C);
        }
        else
        {
            func_080076C0(0x3D, 0xE, 0x1F, 6, D_086673D8);
            D_03004BBC.field_E8 = 1;
            D_02000000.first = func_08011E04;
            func_08003D78(3, func_080154FC);
            func_08000F88(0x161);
            func_08006DFC(10);
        }
    }
}
