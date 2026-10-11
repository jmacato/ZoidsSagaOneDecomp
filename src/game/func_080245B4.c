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

void func_08008324(s32, s32);
void func_08024C94(void);
void func_08024CBC(void);
void func_08024CF8(void);
void func_08024D20(void);
void func_08024D40(void);
void func_08024D60(void);
void func_08024D80(void);
void func_08024DAC(void);
void func_08024DDC(void);
void func_080247B0(void);

void func_080245B4(void)
{
    u32 i;

    func_0805EE78(0x20);
    func_08003D78(4, func_08024C94);
    func_08003D78(5, func_08024CBC);
    func_0805EE78(0x20);
    func_08003D78(6, func_08024CF8);
    func_08008B70(4, 0xE, 4);
    func_08011F18(4, 0x1C0, 0x60, 0x20, 1, 1);
    func_08011F18(4, 0x1A0, 0x60, 0x20, 1, 1);
    func_08008B58(0x262);
    for (i = 0; i <= 0x2F; i++)
    {
        func_08008324(-0x40000, 0);
        func_0805EE78(1);
    }
    func_08011F18(6, 0xC0, 0x80, 0x20, 1, 1);
    func_0805EE78(0xF);
    func_08000BD8(7, 2);
    func_0805EE78(0xF);
    func_08011F18(6, 0xA0, 0x80, 0x20, 1, 1);
    i = 0;
    for (;;)
    {
        func_08008B70(6, 0xFF, 0xFF);
        func_0805EE78(3);
        if (i > 3)
            break;
        func_08008B70(6, 5, 4);
        func_0805EE78(3);
        i++;
    }
    func_08008B58(0x263);
    for (i = 0; i <= 0x2F; i++)
    {
        func_08008324(0x40000, 0);
        func_0805EE78(1);
    }
    func_08008B58(0x264);
    func_08011F18(5, 0x120, 0x100, 0x20, 1, 1);
    func_08008B70(5, 0xFF, 0xFF);
    func_08003D78(4, func_08024D20);
    for (i = 0; i <= 0x3F; i++)
    {
        func_08008324(-0x10000, 0);
        func_0805EE78(1);
    }
    func_08008B58(0x265);
    func_08003D78(4, func_08024D40);
    func_08003D78(5, func_08024D60);
    func_08011F18(4, 0x160, 0x60, 0x20, 2, 1);
    func_0805EE78(1);
    func_08003D78(4, func_08024D80);
    func_08003D78(5, func_08024DAC);
    func_08003D78(6, func_08024DDC);
    func_08011F18(0xB, 0x100, 0x80, 0x20, 2, 1);
    func_08000BD8(0xC, 3);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_080247B0;
    for (;;)
        func_0805EE78(1);
}
