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

extern const u8 D_08669CD4[];

void func_08008324(s32, s32);
void func_0801EAD8(void);
void func_0801EAF8(void);
void func_0801EB2C(void);
void func_0801EB60(void);
void func_0801E7BC(void);

void func_0801E5E8(void)
{
    u32 i;

    func_08008B70(1, 8, 0xB);
    func_08011F18(1, 0x70, 0xB0, 0x10, 1, 1);
    func_08000BD8(2, 0);
    func_08008B70(3, 8, 0xB);
    func_08011F18(3, 0xA0, 0xB0, 0x10, 1, 1);
    func_08000BD8(4, 0);
    func_08008B70(2, 8, 0xB);
    func_08011F18(2, 0x90, 0xB0, 0x10, 1, 1);
    func_08000BD8(3, 0);
    func_08008B58(0x1DB);
    func_08008B58(0x1DC);
    func_08008B58(0x1DD);
    func_08011F18(4, 0x60, 0x80, 0x10, 2, 1);
    func_08011F18(4, 0x60, 0x40, 0x10, 2, 1);
    func_08008B70(4, 0xFF, 0xFF);
    func_08011F18(3, 0xA0, 0xA0, 0x10, 1, 1);
    func_08011F18(3, 0x80, 0xA0, 0x10, 1, 0);
    func_08000BD8(4, 0);
    func_08008B58(0x1DE);
    func_08003D78(4, func_0801EAD8);
    func_0805EE78(8);
    func_08003D78(5, func_0801EAF8);
    func_0805EE78(8);
    func_08003D78(6, func_0801EB2C);
    func_0805EE78(8);
    func_08003D78(7, func_0801EB60);
    func_08011E08();
    func_08003DD8(4);
    func_08003DD8(5);
    func_08003DD8(6);
    func_08003DD8(7);
    func_080076C0(0xB0, 9, 0xC, 6, D_08669CD4);
    func_08011E24();
    func_0805EE78(0xF);
    func_08011F18(0, 0x120, 0x1C0, 0x20, 1, 0);
    func_08000BD8(1, 0);
    func_0805EE78(0xF);
    func_08008B70(1, 9, 0xC);
    func_0805EE78(0xF);
    for (i = 0; i <= 0x3F; i++)
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
    }
    func_0805EE78(0xF);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_0801E7BC;
    for (;;)
        func_0805EE78(1);
}
