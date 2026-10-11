#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern struct
{
    u8 pad_0[0x18];
    u16 delay;
    u16 music;
} D_0200000C;

extern u16 D_02000B54;

void func_0805EE78(s32);
void func_08000BD8(s32, s32);
void func_080019EC(s32);
void func_08008B70(s32, s32, s32);
void func_08008B58(s32);
void func_08011E08(void);
void func_08011E24(void);
void func_08008024(void);
void func_08003DD8(s32);
void func_08003D78(s32, void *);
void func_08007188(s32, s32, s32, s32);
void func_080076C0(s32, s32, s32, s32, const void *);
void func_0800BEA4(void);
void func_080014A8(s32, void *);
void func_08001A08(s32);
void func_080019B4(s32);
void func_08011F18(s32, s32, s32, s32, s32, s32);
s32 func_08001A28(s32);
void func_08000F88(s32);

extern struct
{
    u8 pad_0[0xE8];
    u16 field_E8;
} D_03004BBC;

extern const u8 D_086694FC[];

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_08011E04(void);
void func_0801CE90(void);
void func_0801D1C8(void);

void func_0801B7A8(void)
{
    func_0800BEE4();
    if ((func_08001040(0x19D) && !func_08001040(0x19E)) || (func_08001040(0x19F) && !func_08001040(0x1A0)))
    {
        func_08008B70(1, 9, 3);
        if (!func_08001040(0x19E))
        {
            func_080076C0(0xB7, 2, 8, 7, D_086694FC);
            func_08008B70(0, 0xFF, 0xFF);
            D_03004BBC.field_E8 = 1;
            D_02000000.first = func_08011E04;
            func_08003D78(3, func_0801CE90);
            func_08000F88(0x19E);
        }
        else if (!func_08001040(0x1A0))
        {
            func_080076C0(0xB7, 2, 8, 7, D_086694FC);
            func_08008B70(0, 0xFF, 0xFF);
            D_03004BBC.field_E8 = 1;
            D_02000000.first = func_08011E04;
            func_08003D78(3, func_0801D1C8);
            func_08000F88(0x1A0);
        }
    }
}

void func_0801B8A8(void)
{
}
