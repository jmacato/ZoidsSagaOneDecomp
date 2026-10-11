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

extern u8 D_086682D8[];

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_080076C0(s32, s32, s32, s32, u8 *);
void func_08008B70(s32, s32, s32);
void func_08011E04(void);
void func_08003D78(s32, void *);
void func_08019DE4(void);
void func_0801A2DC(void);
void func_08000F88(s32);
void func_08006DFC(s32);

void func_08018EEC(void)
{
    func_0800BEE4();
    if (func_08001040(0x178) && !func_08001040(0x179))
    {
        func_080076C0(0x85, 0x29, 7, 0xB, D_086682D8);
        func_08008B70(0, 0xFFFF, 0xFFFF);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08019DE4);
        func_08000F88(0x179);
    }
    else if (func_08001040(0x179) && !func_08001040(0x17A))
    {
        func_080076C0(0x85, 0x25, 0x13, 0xB, D_086682D8);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_0801A2DC);
        func_08006DFC(0xC);
        func_08000F88(0x17A);
    }
}
