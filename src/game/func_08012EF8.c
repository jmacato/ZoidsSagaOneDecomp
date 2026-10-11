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
    u8 pad_0[0xC0];
    u16 field_C0;
    u8 pad_C2[0x26];
    u16 field_E8;
    u8 pad_EA[8];
    u16 target_x;
    u16 target_y;
    u16 delay;
    u8 pad_F8[0xC];
    u32 speed;
} D_03004BBC;


void func_08013184(void);

void func_08012EF8(void)
{
    func_0805EE78(0x20);
    D_03004BBC.field_E8 = 10;
    D_03004BBC.target_x = 0x16;
    D_03004BBC.target_y = 0x1A;
    D_03004BBC.speed = 0x10000;
    D_03004BBC.delay = D_0200000C.delay << 3;
    D_03004BBC.field_C0 = 1;
    do
        func_0805EE78(1);
    while (D_03004BBC.field_E8 != 1);
    func_08008B70(1, 0x16, 0x1A);
    func_08011F18(1, 0x150, 0x170, 0x10, 1, 1);
    func_0805EE78(0x3C);
    func_08008B70(2, 0x16, 0x1A);
    func_08011F18(2, 0x150, 0x1A0, 0x10, 1, 1);
    func_08000BD8(3, 3);
    func_08008B70(3, 0x16, 0x1A);
    func_08011F18(3, 0x160, 0x1B0, 0x10, 1, 1);
    func_08000BD8(4, 0);
    func_0805EE78(0x3C);
    func_08000BD8(1, 1);
    func_0805EE78(0x3C);
    func_08008B58(0x66);
    func_0805EE78(0x3C);
    func_08000BD8(1, 0);
    func_0805EE78(0x3C);
    func_08008B70(4, 0x16, 0x14);
    func_08011F18(4, 0x160, 0x190, 0x10, 2, 1);
    func_08001A08(8);
    D_02000B54 = 0;
    func_080019B4(8);
    func_080019EC(0x48);
    do
        func_0805EE78(1);
    while (!func_08001A28(0x48));
    func_08000BD8(2, 1);
    func_0805EE78(0x1E);
    func_08008B70(5, 0x16, 0x14);
    func_08011F18(5, 0x160, 0x180, 0x10, 1, 1);
    func_08008B58(0x67);
    func_08011F18(0, 0x170, 0x1A0, 0x10, 1, 1);
    func_08000BD8(1, 2);
    func_08011F18(3, 0x170, 0x1B0, 0x10, 1, 1);
    func_08000BD8(4, 2);
    func_0805EE78(0x3C);
    func_08003D78(4, func_08013184);
    func_08011F18(5, 0x160, 0x1F0, 0x10, 2, 1);
    func_08008B70(5, 0xFF, 0);
    func_08000BD8(1, 1);
    func_08000BD8(3, 1);
    func_08000BD8(4, 1);
    func_0805EE78(0x3C);
    func_08011F18(1, 0x150, 0x180, 0x10, 1, 1);
    func_08001A08(D_0200000C.music);
    D_02000B54 = 0;
    func_080019B4(D_0200000C.music);
    func_08000BD8(1, 0);
    func_08000BD8(3, 0);
    func_08000BD8(4, 0);
    func_0805EE78(0x3C);
    func_08008B58(0x68);
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    func_08007188(0x1F, 0x16, 0x1A, 0xFFFF);
    func_080014A8(1, func_0800BEA4);
}
