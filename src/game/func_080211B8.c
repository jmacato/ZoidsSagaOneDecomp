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

extern const u8 D_0866A5C8[];
extern const u8 D_0866A604[];

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_08011E04(void);
void func_08022628(void);
void func_08022A60(void);
void func_080213F0(void);
void func_0802144C(void);
void func_080215C8(void);
void func_080214E0(void);
void func_0802155C(void);
void func_08021574(void);

void func_080211B8(void)
{
    func_0800BEE4();
    if (func_08001040(0x1B2) && !func_08001040(0x1B3))
    {
        func_080076C0(0xED, 0x11, 7, 3, D_0866A5C8);
        func_08008B70(0, 0xFF, 0xFF);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08022628);
        func_08000F88(0x1B3);
        return;
    }
    if (func_08001040(0x1C8) && !func_08001040(0x1B5))
    {
        func_080076C0(0xED, 0xD, 0xD, 2, D_0866A604);
        func_08001A08(9);
        D_02000B54 = 0;
        func_080019B4(9);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08022A60);
        func_08000F88(0x1B5);
        return;
    }
    if (func_08001040(0x1B5) && !func_08001040(0x1B6))
        D_02000000.first = func_080213F0;
    else if (func_08001040(0x1B6) && !func_08001040(0x1B7))
        D_02000000.first = func_0802144C;
    else if (func_08001040(0x1B7) && !func_08001040(0x1B9))
        D_02000000.first = func_080215C8;
    else if (func_08001040(0x1B9) && !func_08001040(0x1BA))
        D_02000000.first = func_080214E0;
    else if (func_08001040(0x1C6) && !func_08001040(0x1C7))
        D_02000000.second = func_0802155C;
    else if (func_08001040(0x1C7))
        D_02000000.first = func_08021574;
    if (!func_08001040(0x1B7) || func_08001040(0x1B9))
    {
        func_08008B70(1, 0xFFFF, 0xFFFF);
        func_08008B70(2, 0xFFFF, 0xFFFF);
        func_08008B70(3, 0xFFFF, 0xFFFF);
    }
    if (!func_08001040(0x1B7) || func_08001040(0x1B9))
        func_08008B70(4, 0xFFFF, 0xFFFF);
}
