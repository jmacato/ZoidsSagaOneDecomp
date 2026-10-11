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

struct Obj
{
    u8 pad_0[0x3B8];
    u16 flags_7;
};

extern struct Obj D_03004BBC;

void func_08011E40(u16, u8, s32, u8);
void func_08023C50(void);

void func_08023B18(void)
{
    struct Obj *obj;
    u16 *flags;

    func_08011E24();
    func_08008B70(5, 0xD, 0x1E);
    func_08011F18(5, 0x110, 0x1E0, 0x10, 2, 1);
    func_08008B58(0x24C);
    func_08008B70(6, 0x15, 0x1D);
    func_08000BD8(7, 0);
    obj = &D_03004BBC;
    flags = &obj->flags_7;
    obj->flags_7 |= 0x400;
    func_080019EC(0x85);
    while (!(*flags & 4))
        func_0805EE78(1);
    func_08000BD8(7, 1);
    D_03004BBC.flags_7 &= 0xFBFF;
    do
        func_0805EE78(1);
    while (!func_08001A28(0x85));
    func_08008B58(0x24D);
    func_08011F18(0, 0x150, 0x1F0, 0x10, 2, 0);
    func_08000BD8(1, 2);
    func_0805EE78(0xF);
    func_08000BD8(1, 3);
    func_08011E40(4, 0x14, 4, 0);
    func_08000BD8(5, 2);
    func_0805EE78(0xF);
    func_08000BD8(1, 2);
    func_0805EE78(0xF);
    func_08008B58(0x24E);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_08023C50;
    for (;;)
        func_0805EE78(1);
}
