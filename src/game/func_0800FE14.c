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
    u8 pad_0[0x1D0];
    u16 field_c0;
    u8 pad_1D2[0x26];
    u16 field_e8;
    u8 pad_1FA[0x8];
    u16 target_x;
    u16 target_y;
    u16 delay;
    u8 pad_208[0xC];
    u32 speed;
} D_03004BBC;

void func_0800FE14(void)
{
    D_03004BBC.field_e8 = 10;
    D_03004BBC.target_x = 0x11;
    D_03004BBC.target_y = 0x18;
    D_03004BBC.speed = 0x10000;
    D_03004BBC.delay = D_0200000C.delay << 3;
    D_03004BBC.field_c0 = 1;
    while (D_03004BBC.field_e8 != 1)
        func_0805EE78(1);
    D_03004BBC.field_e8 = 10;
    D_03004BBC.target_x = 0x11;
    D_03004BBC.target_y = 0x12;
    D_03004BBC.speed = 0x10000;
    D_03004BBC.delay = D_0200000C.delay << 3;
    D_03004BBC.field_c0 = 1;
    while (D_03004BBC.field_e8 != 1)
        func_0805EE78(1);
    D_03004BBC.field_e8 = 10;
    D_03004BBC.target_x = 8;
    D_03004BBC.target_y = 0x12;
    D_03004BBC.speed = 0x10000;
    D_03004BBC.delay = D_0200000C.delay << 3;
    D_03004BBC.field_c0 = 1;
    while (D_03004BBC.field_e8 != 1)
        func_0805EE78(1);
    D_03004BBC.field_e8 = 10;
    D_03004BBC.target_x = 8;
    D_03004BBC.target_y = 7;
    D_03004BBC.speed = 0x10000;
    D_03004BBC.delay = D_0200000C.delay << 3;
    D_03004BBC.field_c0 = 1;
    while (D_03004BBC.field_e8 != 1)
        func_0805EE78(1);
    D_03004BBC.field_e8 = 11;
    D_03004BBC.target_x = 0x11;
    D_03004BBC.target_y = 7;
    D_03004BBC.speed = 0x10000;
    D_03004BBC.delay = D_0200000C.delay << 3;
    D_03004BBC.field_c0 = 1;
    while (D_03004BBC.field_e8 != 1)
        func_0805EE78(1);
    D_03004BBC.field_e8 = 10;
    D_03004BBC.target_x = 0x11;
    D_03004BBC.target_y = 0xC;
    D_03004BBC.speed = 0x10000;
    D_03004BBC.delay = D_0200000C.delay << 3;
    D_03004BBC.field_c0 = 1;
    while (D_03004BBC.field_e8 != 1)
        func_0805EE78(1);
    D_03004BBC.field_e8 = 10;
    D_03004BBC.target_x = 0x11;
    D_03004BBC.target_y = 0xC;
    D_03004BBC.speed = 0x10000;
    D_03004BBC.delay = D_0200000C.delay << 3;
    D_03004BBC.field_c0 = 1;
    while (D_03004BBC.field_e8 != 1)
        func_0805EE78(1);
    D_03004BBC.field_e8 = 10;
    D_03004BBC.target_x = 0x17;
    D_03004BBC.target_y = 0xC;
    D_03004BBC.speed = 0x10000;
    D_03004BBC.delay = D_0200000C.delay << 3;
    D_03004BBC.field_c0 = 1;
    while (D_03004BBC.field_e8 != 1)
        func_0805EE78(1);
    func_08000BD8(3, 0);
    func_08003DD8(5);
}
