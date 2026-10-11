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

s32 func_08001040(s32);
void func_08037450(s32);
void func_08016928(void);
void func_080168B0(void);

void func_08016264(void)
{
    func_08001A08(0xE);
    D_02000B54 = 0;
    func_080019B4(0xE);
    func_08011F18(0, 0x400, 0x280, 0x20, 1, 1);
    func_08008B58(0xEF);
    if (!func_08001040(0x198))
    {
        func_08008B58(0xF0);
        func_08001A08(5);
        D_02000B54 = 0;
        func_080019B4(5);
        func_08008B70(1, 0x20, 0x14);
        func_08011F18(1, 0x400, 0x2A0, 0x20, 2, 1);
        func_08011F18(1, 0x3C0, 0x2A0, 0x20, 2, 1);
        func_08003D78(4, func_08016928);
        func_08011F18(1, 0x3C0, 0x2C0, 0x20, 2, 1);
        func_08011F18(1, 0x380, 0x2C0, 0x20, 2, 1);
        func_08008B70(1, 0xFF, 0xFF);
        func_0805EE78(0x5A);
        func_08008B58(0xF1);
        func_08037450(8);
        func_08037450(6);
        func_08000F88(0x198);
    }
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_080168B0;
}
