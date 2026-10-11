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

extern struct
{
    u8 pad_0[0x90];
    u32 x;
    u32 y;
} D_03004BBC;

extern const u8 D_08669A7C[];

void func_0801D500(void);
void func_0801D52C(void);
void func_0801D558(void);
void func_0801D42C(void);

void func_0801D328(void)
{
    u32 x;
    u32 y;

    func_08011E08();
    x = D_03004BBC.x >> 21;
    y = D_03004BBC.y >> 21;
    func_080076C0(0xB0, x, y, 5, D_08669A7C);
    func_08001A08(9);
    D_02000B54 = 0;
    func_080019B4(9);
    func_08008B70(1, x + 10, y);
    func_08011E24();
    func_08003D78(4, func_0801D500);
    func_08003D78(5, func_0801D52C);
    func_08003D78(6, func_0801D558);
    func_08008B58(0x1B0);
    func_08003DD8(4);
    func_08003DD8(5);
    func_08003DD8(6);
    func_08008B70(2, 0xFF, 0xFF);
    func_08008B70(3, 0xFF, 0xFF);
    func_08008B70(4, 0xFF, 0xFF);
    func_08008B58(0x1B1);
    func_08011F18(1, (u16)((x + 1) << 5), y << 5, 0x20, 2, 0);
    func_08008B58(0x1B2);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_0801D42C;
    for (;;)
        func_0805EE78(1);
}
