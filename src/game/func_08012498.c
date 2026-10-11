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
extern u8 D_08666EEC[];

void func_0800802C(void);
s32 func_08001040(s32);
void func_080076C0(s32, s32, s32, s32, u8 *);
void func_08001A08(s32);
void func_080019B4(s32);
void func_08011E04(void);
void func_0801334C(void);
void func_08003D78(s32, void *);
void func_08000F88(s32);

void func_08012498(void)
{
    s32 result;

    func_0800802C();
    if (func_08001040(0x148) != 0 && (result = func_08001040(0x149)) == 0)
    {
        func_080076C0(0x22, 0xC, 0x14, 1, D_08666EEC);
        func_08001A08(6);
        D_02000B54 = result;
        func_080019B4(6);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_0801334C);
        func_08000F88(0x149);
    }
}
