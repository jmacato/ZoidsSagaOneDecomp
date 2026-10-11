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

extern const u8 D_0866A9A8[];
extern const u8 D_0866A9D0[];
extern const u8 D_0866AA84[];
extern const u8 D_0866ABB0[];

void func_08037450(s32);
void func_08008324(s32, s32);
void func_08022EE8(void);
void func_08022F18(void);
void func_08022F40(void);
void func_08022F68(void);
void func_08022F90(void);
void func_08022FB8(void);
void func_08022FE0(void);
void func_08023008(void);
void func_08023030(void);
void func_08023058(void);

void func_08022BA0(void)
{
    u32 i;

    func_08011F18(0, 0x180, 0x2C0, 0x20, 1, 1);
    func_08000BD8(1, 3);
    func_08011E08();
    func_080076C0(0xED, 0xE, 0x16, 2, D_0866A9A8);
    func_08008B70(0, 0xC, 0x16);
    func_08011E24();
    func_08008B58(0x233);
    func_08008B70(1, 0xE, 0x16);
    func_0805EE78(0xF);
    func_08008B58(0x234);
    func_08037450(0x1C);
    func_08011F18(0, 0x1C0, 0x2C0, 0x20, 1, 0);
    func_08008B70(0, 0xFF, 0xFF);
    func_08011E08();
    func_080076C0(0xF3, 0xA, 4, 9, D_0866A9D0);
    func_08008B70(0, 0xA, 0x13);
    func_08011E24();
    for (i = 0; i <= 0xEF; i++)
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
    }
    func_08008B58(0x235);
    func_08008B70(7, 0xA, 0xD);
    func_08011F18(7, 0xA0, 0x110, 0x10, 1, 1);
    func_08003D78(4, func_08022F18);
    func_08003D78(5, func_08022F40);
    func_08003D78(6, func_08022F68);
    func_08008B70(8, 9, 0xC);
    func_08011F18(8, 0x90, 0x100, 0x10, 1, 1);
    func_08008B58(0x236);
    for (i = 0; i <= 2; i++)
    {
        func_080019EC(0x80);
        do
            func_0805EE78(1);
        while (!func_08001A28(0x80));
        func_080019EC(0x58);
        do
            func_0805EE78(1);
        while (!func_08001A28(0x58));
    }
    func_08001A08(4);
    D_02000B54 = 0;
    func_080019B4(4);
    func_08008B58(0x237);
    func_08003D78(4, func_08022F90);
    func_08003D78(5, func_08022FB8);
    func_08003D78(6, func_08022FE0);
    func_08003D78(7, func_08023008);
    func_08003D78(8, func_08023030);
    func_08011E08();
    func_08003DD8(4);
    func_08003DD8(5);
    func_08003DD8(6);
    func_08003DD8(7);
    func_08003DD8(8);
    func_080076C0(0xF4, 9, 0x12, 0xF, D_0866AA84);
    func_08008B70(0, 8, 0x14);
    func_08011E24();
    for (i = 0; i <= 0x7F; i++)
    {
        func_08008324(0, -0x10000);
        func_0805EE78(1);
    }
    func_08001A08(9);
    D_02000B54 = 0;
    func_080019B4(9);
    func_08008B58(0x238);
    func_08003D78(4, func_08023058);
    func_0805EE78(0xF);
    func_08000BD8(9, 3);
    func_08000BD8(0xA, 2);
    func_08000BD8(0xD, 2);
    func_0805EE78(0xF);
    func_08008B58(0x239);
    func_08003DD8(4);
    func_08008B70(0xE, 0xFF, 0xFF);
    func_0805EE78(0xF);
    func_08008B58(0x23A);
    for (i = 0; i <= 0x8F; i++)
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
    }
    func_0805EE78(0xF);
    func_08000BD8(0xB, 1);
    func_08000BD8(0xE, 1);
    func_0805EE78(0xF);
    func_08011F18(0, 0x80, 0x130, 0x10, 1, 0);
    func_08008B58(0x23B);
    func_08011E08();
    func_080076C0(0xED, 0xE, 0x16, 4, D_0866ABB0);
    func_08008B70(0, 0xD, 0x17);
    func_08011E24();
    func_08008B58(0x23C);
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_08022EE8;
    for (;;)
        func_0805EE78(1);
}
