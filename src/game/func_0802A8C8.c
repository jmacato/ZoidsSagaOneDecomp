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
    u8 pad_0[0xE8];
    u16 field_E8;
    u8 pad_EA[0x26];
    u16 flags_2;
    u8 pad_112[0x4C];
    u16 field_15E;
    u16 field_160;
    u8 pad_162[0xE];
    u16 field_170;
    u8 pad_172[2];
    u16 field_174;
};

extern struct Obj D_03004BBC;

struct Slot
{
    u8 pad_0[2];
    u8 x;
    u8 y;
    u8 pad_4[0xC];
};

extern struct
{
    u8 pad_0[0x50];
    struct Slot slots[1];
} D_02000B5C;
extern u16 D_02007560[];

s32 func_08001040(s32);
s32 func_08008D28(s32);
void func_08006E08(void);
void func_0800BEC8(void);
void func_0800C680(void);
void func_08037990(s32);
void func_08037920(s32);

void func_0802A8C8(void)
{
    D_03004BBC.field_E8 = 0;
    for (;;)
    {
        if (func_08001040(0x13D))
        {
            D_03004BBC.field_E8 = 1;
            break;
        }
        func_0805EE78(1);
    }
    if (func_08008D28(0x29) == 1)
    {
        func_08006E08();
        func_08007188(D_02007560[0], D_02007560[1], D_02007560[2], 0);
        func_080014A8(0, func_0800BEC8);
        return;
    }
    func_08000F88(0x13C);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    D_03004BBC.flags_2 |= 0x400;
    func_0805EE78(0x1E);
    func_08008B58(0x2D1);
    func_0805EE78(0x1E);
    func_080019EC(0x6F);
    func_0805EE78(0x3C);
    func_080019EC(0x6D);
    func_08008B70(1, 0xFF, 0xFF);
    if (D_03004BBC.field_174 != 0xFFFF)
    {
        D_02000B5C.slots[D_03004BBC.field_174].x = D_03004BBC.field_15E;
        D_02000B5C.slots[D_03004BBC.field_174].y = D_03004BBC.field_160;
    }
    D_03004BBC.field_170 = 1;
    func_0805EE78(0x3C);
    func_0805EE78(0x1E);
    func_08008B58(0x2D2);
    func_0805EE78(0x1E);
    func_08037990(0x78);
    func_08037920(8);
    D_03004BBC.field_E8 = 0;
    D_02000000.first = func_08008024;
    func_08003DD8(3);
}
