#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern struct
{
    u8 map;
    u8 pad_1[0x17];
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

extern u8 D_02000B5C[];

s32 func_08001040(s32);
u8 func_0802AACC(s32);

void func_0802AB08(void)
{
    if (D_0200000C.map == 1)
    {
        if (!func_08001040(0x13F))
        {
            func_08008B58(0x2C1);
            func_08000F88(0x13F);
        }
        else
            func_08008B58(0x2C2);
    }
    else if (D_0200000C.map == 9)
        func_08008B58(0x2C9);
    else if (D_0200000C.map == 10)
        func_08008B58(0x2CA);
    else if (func_08001040(0x140))
        func_08008B58(0x2C8);
    else if (func_0802AACC(0x90))
    {
        func_08008B58(0x2C7);
        func_08000F88(0x140);
    }
    else if (func_0802AACC(0x8F))
        func_08008B58(0x2C6);
    else if (D_02000B5C[0x3320])
        func_08008B58(0x2C5);
    else if (func_08001040(0x141))
        func_08008B58(0x2C4);
    else
    {
        func_08008B58(0x2C3);
        func_08000F88(0x141);
    }
}
