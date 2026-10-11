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

struct Sprite
{
    u8 pad_0[8];
    u32 x;
    u32 y;
    u8 pad_10[0x78];
};

extern struct Sprite D_03004BBC[];
extern const u8 D_086679C8[];
extern const u8 D_08667A40[];
extern const u8 D_08667B08[];

void func_08016CA8(s32, u32, u32);
void func_08016BC8(s32);
void func_08037424(s32);
void func_08037450(s32);
void func_080161A0(void);
void func_08016128(void);
void func_08016150(void);
void func_08016178(void);

void func_08015F74(void)
{
    func_08011E08();
    func_080076C0(0x3C, 0x16, 7, 6, D_086679C8);
    func_08001A08(4);
    D_02000B54 = 0;
    func_080019B4(4);
    func_08011E24();
    func_08008B58(0xE7);
    func_08016CA8(5, D_03004BBC[2].x >> 21, D_03004BBC[2].y >> 21);
    func_08016BC8(1);
    func_08011F18(3, 0x300, 0xE0, 0x20, 1, 1);
    func_08003D78(4, func_080161A0);
    func_08011F18(2, 0x300, 0xC0, 0x20, 1, 1);
    func_08008B58(0xE8);
    func_08011E08();
    func_080076C0(0x39, 0xF, 0xE, 0xA, D_08667A40);
    func_08008B70(0, 2, 2);
    func_08011E24();
    func_08008B58(0xE9);
    func_08011E08();
    func_080076C0(0x42, 8, 5, 8, D_08667B08);
    func_08008B70(0, 6, 5);
    func_08011E24();
    func_08008B58(0xEA);
    func_08011F18(5, 0x80, 0xC0, 0x10, 2, 1);
    func_08008B70(5, 0xFF, 0xFF);
    func_08011F18(7, 0xA0, 0xC0, 0x10, 2, 1);
    func_08008B70(7, 0xFF, 0xFF);
    func_08003D78(4, func_08016128);
    func_08003D78(5, func_08016150);
    func_08003D78(6, func_08016178);
    func_08011F18(0, 0x60, 0xC0, 0x10, 2, 0);
    func_08008B70(0, 0xFF, 0xFF);
    func_08037424(8);
    func_08037450(7);
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    func_08007188(0x41, 0x11, 1, 0xFFFF);
    func_080014A8(1, func_0800BEA4);
}

void func_08016124(void)
{
}
