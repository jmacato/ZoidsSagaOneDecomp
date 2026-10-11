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

extern const u8 D_086692F4[];
extern const u8 D_0866931C[];
extern const u8 D_0866936C[];

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_08006DFC(s32);
void func_08011E04(void);
void func_0801C35C(void);
void func_0801B45C(void);
void func_0801B4C4(void);
void func_0801B524(void);
void func_0801E044(void);
void func_0801E828(void);

void func_0801B284(void)
{
    func_0800BEE4();
    if (func_08001040(0x194) && !func_08001040(0x195))
    {
        func_080076C0(0xB0, 5, 0x15, 2, D_086692F4);
        func_08008B70(0, 0xFF, 0xFF);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_0801C35C);
        func_08006DFC(0x10);
        func_08000F88(0x195);
    }
    else if (func_08001040(0x19E) && !func_08001040(0x19F))
        D_02000000.first = func_0801B45C;
    else if (func_08001040(0x19F) && !func_08001040(0x1A1))
        D_02000000.first = func_0801B4C4;
    else if (func_08001040(0x1A2) && !func_08001040(0x1A3))
        D_02000000.first = func_0801B524;
    else if (func_08001040(0x1A7) && !func_08001040(0x1A8))
    {
        func_080076C0(0xB0, 0x11, 0x13, 4, D_0866931C);
        func_08001A08(9);
        D_02000B54 = 0;
        func_080019B4(9);
        func_08008B70(0, 0x11, 0x15);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_0801E044);
        func_08000F88(0x1A8);
    }
    else if (func_08001040(0x1AA) && !func_08001040(0x19B))
    {
        func_080076C0(0xB0, 9, 0xE, 6, D_0866936C);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_0801E828);
    }
}
