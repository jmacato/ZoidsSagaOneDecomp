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

extern const u8 D_086673B0[];
extern const u8 D_08667338[];
extern const u8 D_08667388[];

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_08000FD8(s32);
void func_08011E04(void);
void func_08015000(void);
void func_080152A4(void);
void func_08015400(void);
void func_080144DC(void);

void func_0801426C(void)
{
    func_0800BEE4();
    if (func_08001040(0x158) && !func_08001040(0x159))
    {
        func_080076C0(0x32, 0xD, 2, 2, D_086673B0);
        func_08008B70(0, 0xFF, 0xFF);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08015000);
        func_08000F88(0x159);
    }
    else if (!func_08001040(0x15C) && func_08001040(0x15D))
    {
        func_08000FD8(0x15D);
        func_080076C0(0x32, 0xA, 5, 4, D_08667338);
        func_08001A08(4);
        D_02000B54 = 0;
        func_080019B4(4);
        func_08008B70(0, 0xA, 4);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_080152A4);
    }
    else if (!func_08001040(0x15E) && func_08001040(0x15C))
    {
        func_080076C0(0x32, 0xA, 5, 2, D_08667388);
        func_08008B70(0, 0xA, 4);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08015400);
        func_08000F88(0x15E);
    }
    else
    {
        if (func_08001040(0x159) && !func_08001040(0x15A) && !func_08001040(0x164))
            D_02000000.first = func_080144DC;
        if (!func_08001040(0x164) || func_08001040(0x165))
            func_08008B70(1, 0xFF, 0xFF);
        if (!func_08001040(0x164) || func_08001040(0x166))
            func_08008B70(2, 0xFF, 0xFF);
        if (!func_08001040(0x164) || func_08001040(0x167))
            func_08008B70(3, 0xFF, 0xFF);
        if (!func_08001040(0x164) || func_08001040(0x168))
            func_08008B70(4, 0xFF, 0xFF);
    }
}
