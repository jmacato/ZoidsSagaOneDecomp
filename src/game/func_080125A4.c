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
    u8 pad_0[0xD6];
    u16 x;
    u16 y;
    u8 pad_DA[0xE];
    u16 field_E8;
} D_03004BBC;

extern const u8 D_08666F00[];

void func_0800802C(void);
s32 func_08001040(s32);
void func_08011E04(void);
void func_08013668(void);
void func_08013840(void);

void func_080125A4(void)
{
    func_0800802C();
    if (func_08001040(0x150) && !func_08001040(0x151))
    {
        func_080076C0(0x25, 4, 9, 9, D_08666F00);
        func_08001A08(5);
        D_02000B54 = 0;
        func_080019B4(5);
        if (func_08001040(0x197))
            func_08008B70(6, 0xFF, 0xFF);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08013668);
    }
    else if (func_08001040(0x151) && !func_08001040(0x152))
    {
        func_080076C0(0x25, 4, 3, 9, D_08666F00);
        func_08008B70(0, 4, 5);
        func_08008B70(1, 5, 3);
        func_08008B70(2, 3, 4);
        func_08008B70(3, 4, 4);
        func_08008B70(4, 5, 4);
        func_08008B70(5, 4, 3);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08013840);
        func_08000F88(0x152);
    }
}
