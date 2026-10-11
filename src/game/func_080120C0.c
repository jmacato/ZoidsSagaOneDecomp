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

extern const u8 D_08666D84[];
extern const u8 D_08666D98[];
extern const u8 D_08666D5C[];

void func_0800802C(void);
s32 func_08001040(s32);
void func_08000FD8(s32);
void func_08011E04(void);
void func_080122F0(void);
void func_08013304(void);
void func_08013620(void);
void func_08013D70(void);
void func_08013E34(void);

void func_080120C0(void)
{
    func_0800802C();
    if (func_08001040(0x146) && !func_08001040(0x147))
    {
        D_02000000.first = func_080122F0;
    }
    else if (func_08001040(0x147) && !func_08001040(0x148))
    {
        func_080076C0(0x1E, 0x1D, 4, 1, D_08666D84);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08013304);
        func_08000F88(0x148);
    }
    else if (func_08001040(0x14A) && func_08001040(0x14B) && func_08001040(0x14C) && func_08001040(0x14D)
             && func_08001040(0x14E) && func_08001040(0x14F) && !func_08001040(0x150))
    {
        func_080076C0(0x1E, 0xE, 9, 1, D_08666D98);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08013620);
        func_08000F88(0x150);
    }
    else if (func_08001040(0x154) && !func_08001040(0x155))
    {
        if (func_08001040(0x157))
        {
            func_080076C0(0x1E, 4, 2, 2, D_08666D5C);
            func_08001A08(5);
            D_02000B54 = 0;
            func_080019B4(5);
            D_03004BBC.field_E8 = 1;
            D_02000000.first = func_08011E04;
            func_08003D78(3, func_08013D70);
            func_08000FD8(0x157);
        }
    }
    else if (func_08001040(0x155) && !func_08001040(0x156))
    {
        func_080076C0(0x1E, 4, 2, 2, D_08666D5C);
        func_08008B70(1, 5, 2);
        func_08001A08(6);
        D_02000B54 = 0;
        func_080019B4(6);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08013E34);
        func_08000F88(0x156);
    }
}
