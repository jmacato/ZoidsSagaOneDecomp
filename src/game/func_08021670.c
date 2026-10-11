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

extern const u8 D_0866A64C[];

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_08011E04(void);
void func_08022A00(void);
void func_08006DFC(s32);
void func_08021814(void);
void func_0802185C(void);
void func_080217C0(void);

void func_08021670(void)
{
    func_0800BEE4();
    if (func_08001040(0x1B3) && !func_08001040(0x1B4))
    {
        func_080076C0(0xEE, 0x19, 0x1B, 2, D_0866A64C);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08022A00);
        func_08006DFC(0x12);
        func_08000F88(0x1B4);
        return;
    }
    if (func_08001040(0x1B4) && !func_08001040(0x1C8))
    {
        if (!func_08001040(0x1C9))
            D_02000000.first = func_08021814;
        else
            D_02000000.first = func_0802185C;
    }
    else if (!func_08001040(0x1C4) && func_08001040(0x1B3) && !func_08001040(0x1BB))
    {
        D_02000000.first = func_080217C0;
    }
    if (func_08001040(0x1B6))
    {
        func_08008B70(1, 0xFFFF, 0xFFFF);
        func_08008B70(2, 0xFFFF, 0xFFFF);
        func_08008B70(3, 0xFFFF, 0xFFFF);
        func_08008B70(4, 0xFFFF, 0xFFFF);
        func_08008B70(5, 0xFFFF, 0xFFFF);
        func_08008B70(6, 0xFFFF, 0xFFFF);
        func_08008B70(7, 0xFFFF, 0xFFFF);
        func_08008B70(8, 0xFFFF, 0xFFFF);
    }
}
