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

void func_08037424(s32);
void func_08037450(s32);
void func_08008324(s32, s32);
extern const u8 D_0866A098[];
extern const u8 D_0866A0E8[];
void func_0801FAB8(void);
void func_0801FAE8(void);
void func_0801FB24(void);
void func_0801FB58(void);
void func_0801FB78(void);
void func_0801FBA0(void);
void func_0801FBBC(void);

void func_0801F5D0(void)
{
    u32 i;

    func_0805EE78(0x20);
    func_08008B70(1, 0x12, 0xC);
    func_08011F18(1, 0x120, 0x50, 0x10, 1, 1);
    func_08000BD8(2, 0);
    func_08001A08(8);
    D_02000B54 = 0;
    func_080019B4(8);
    func_08008B58(0x1F5);
    func_08003D78(4, func_0801FAB8);
    func_08011F18(2, 0x110, 0x50, 0x10, 1, 1);
    func_08011F18(2, 0x120, 0x50, 0x10, 1, 1);
    func_08011F18(2, 0x120, 0x90, 0x10, 1, 1);
    func_08011F18(2, 0x60, 0x90, 0x10, 1, 1);
    func_08003D78(4, func_0801FAE8);
    func_0805EE78(0x10);
    func_08008B70(4, 0x12, 0xC);
    func_08011F18(4, 0x120, 0x50, 0x10, 1, 1);
    func_08011F18(4, 0x130, 0x50, 0x10, 1, 1);
    func_08000BD8(5, 0);
    func_08008B58(0x1F6);
    func_08003D78(4, func_0801FB24);
    func_08011F18(2, 0x120, 0x90, 0x10, 1, 1);
    func_08011F18(2, 0x120, 0x50, 0x10, 1, 1);
    func_08011F18(2, 0x110, 0x50, 0x10, 1, 1);
    func_08011F18(2, 0x110, 0x40, 0x10, 1, 1);
    func_08000BD8(3, 1);
    func_08008B58(0x1F7);
    func_08011F18(1, 0x100, 0x50, 0x10, 1, 1);
    func_08000BD8(2, 3);
    func_08011F18(2, 0x110, 0x50, 0x10, 1, 1);
    func_08011F18(2, 0x120, 0x50, 0x10, 1, 1);
    func_08011F18(2, 0x120, 0x90, 0x10, 1, 1);
    func_08011F18(2, 0x60, 0x90, 0x10, 1, 1);
    func_08008B58(0x1F8);
    func_080019EC(0x5B);
    func_0805EE78(0x1E);
    func_080019EC(0x5B);
    func_0805EE78(0x1E);
    func_080019EC(0x5B);
    do
    func_0805EE78(1);
    while (!func_08001A28(0x5B));
    func_0805EE78(0x1E);
    func_080019EC(0x5B);
    func_0805EE78(0x2D);
    func_080019EC(0x5B);
    do
    func_0805EE78(1);
    while (!func_08001A28(0x5B));
    func_08001A08(4);
    D_02000B54 = 0;
    func_080019B4(4);
    func_08000BD8(1, 1);
    func_08000BD8(2, 1);
    func_08000BD8(3, 1);
    func_08000BD8(4, 1);
    func_08000BD8(5, 1);
    func_0805EE78(0xF);
    func_08011F18(4, 0x110, 0x50, 0x10, 1, 1);
    func_08000BD8(5, 3);
    func_08011F18(0, 0x120, 0x50, 0x10, 1, 0);
    func_08003D78(4, func_0801FB58);
    func_08011E08();
    func_08003DD8(4);
    func_080076C0(0xDA, 4, 0xE, 4, D_0866A098);
    func_08008B70(0, 4, 0x10);
    func_08011E24();
    func_08008B70(2, 4, 0xE);
    func_08011F18(2, 0x40, 0xF0, 0x10, 1, 1);
    func_08011F18(2, 0x50, 0xF0, 0x10, 1, 1);
    func_08000BD8(3, 1);
    func_08008B70(3, 4, 0xE);
    func_08011F18(3, 0x40, 0xF0, 0x10, 1, 1);
    func_08008B58(0x1F9);
    func_08008B58(0x1FA);
    func_08011E08();
    func_080076C0(0xDA, 0x15, 4, 9, D_0866A0E8);
    func_08001A08(4);
    D_02000B54 = 0;
    func_080019B4(4);
    func_08011E24();
    func_08008B58(0x1FB);
    for (i = 0; i <= 0x1F; i++)
    {
    func_08008324(0, 0x10000);
    func_0805EE78(1);
    }
    func_08008B70(7, 0x15, 0xC);
    func_08011F18(7, 0x150, 0x70, 0x10, 1, 1);
    func_0805EE78(0xF);
    func_08000BD8(1, 1);
    func_08000BD8(2, 1);
    func_08000BD8(3, 1);
    func_08000BD8(4, 1);
    func_08000BD8(5, 1);
    func_0805EE78(0xF);
    func_08011F18(6, 0x130, 0x30, 0x10, 1, 1);
    func_08011F18(6, 0x130, 0x50, 0x10, 1, 1);
    func_08001A08(0x16);
    D_02000B54 = 0;
    func_080019B4(0x16);
    func_08008B58(0x1FC);
    func_08003D78(4, func_0801FB78);
    func_08011F18(2, 0x160, 0x50, 0x10, 1, 1);
    func_08000BD8(3, 1);
    func_08011F18(0, 0x150, 0x50, 0x10, 1, 0);
    func_08008B58(0x1FD);
    func_08003D78(4, func_0801FBA0);
    func_08003D78(5, func_0801FBBC);
    func_08011F18(3, 0x170, 0x60, 0x10, 1, 1);
    func_08008B58(0x1FE);
    for (i = 0; i <= 0xF; i++)
    {
    func_08008324(0, 0x10000);
    func_0805EE78(1);
    }
    func_08008B70(8, 0x14, 0xD);
    func_08011F18(8, 0x140, 0x70, 0x10, 1, 1);
    func_08008B58(0x1FF);
    func_08037424(0x1A);
    func_08037424(0x1B);
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    func_08007188(0xD9, 8, 0xC, 0xFFFF);
    func_080014A8(1, func_0800BEA4);
}
