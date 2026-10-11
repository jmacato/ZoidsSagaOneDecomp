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
    u8 pad_0[0x90];
    u32 x;
    u32 y;
    u8 pad_98[0x50];
    u16 field_E8;
} D_03004BBC;

extern const u8 D_08666FB4[];
extern const u8 D_08666D5C[];

void func_0800802C(void);
s32 func_08001040(s32);
void func_08011E04(void);
void func_08012888(void);
void func_08013B2C(void);
void func_08013D64(void);

void func_080126E0(void)
{
    func_0800802C();
    if (func_08001040(0x152) && D_03004BBC.x <= 0x2000000 && !func_08001040(0x153))
    {
        func_080076C0(0x26, D_03004BBC.x >> 21, D_03004BBC.y >> 21, 8, D_08666FB4);
        D_02000000.first = func_08012888;
    }
    else if (func_08001040(0x153) && !func_08001040(0x154))
    {
        func_080076C0(0x26, 5, 8, 8, D_08666FB4);
        func_08001A08(9);
        D_02000B54 = 0;
        func_080019B4(9);
        func_08008B70(0, 2, 8);
        func_08000BD8(1, 3);
        D_03004BBC.field_E8 = 1;
        func_08008B70(1, 4, 7);
        func_08008B70(2, 3, 7);
        func_08008B70(3, 3, 8);
        func_08008B70(4, 3, 9);
        func_08008B70(5, 4, 9);
        func_08008B70(6, 4, 8);
        func_08000F88(0x154);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08013B2C);
    }
    else if (func_08001040(0x154) && !func_08001040(0x155) && !func_08001040(0x157))
    {
        func_080076C0(0x1E, 4, 2, 2, D_08666D5C);
        func_08001A08(5);
        D_02000B54 = 0;
        func_080019B4(5);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08013D64);
    }
}
