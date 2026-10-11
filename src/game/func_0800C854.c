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
    u8 pad_0[0x94];
    s32 y;
    u8 pad_98[0x28];
    u16 field_C0;
    u8 pad_C2[0x26];
    u16 field_E8;
    u8 pad_EA[8];
    u16 target_x;
    u16 target_y;
    u16 delay;
    u8 pad_F8[0xC];
    u32 speed;
    u8 pad_108[8];
    u16 flags_2;
    u8 pad_112[0x36];
    u16 field_148;
    u8 pad_14A[0x26];
    u16 field_170;
    u8 pad_172[8];
    u16 target_x_2;
    u16 target_y_2;
    u16 delay_2;
    u8 pad_180[0xC];
    u32 speed_2;
} D_03004BBC;

void func_0800C6A4(void);
void func_0800C680(void);

void func_0800C854(void)
{
    func_0805EE78(0x78);
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    func_08000BD8(2, 3);
    func_0805EE78(0x1E);
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 8;
    D_03004BBC.target_y_2 = 4;
    D_03004BBC.speed_2 = 0x8000;
    D_03004BBC.delay_2 = D_0200000C.delay << 4;
    D_03004BBC.field_148 = 0;
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    func_08000BD8(2, 2);
    func_0805EE78(0x3C);
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 6;
    D_03004BBC.target_y_2 = 4;
    D_03004BBC.speed_2 = 0x8000;
    D_03004BBC.delay_2 = D_0200000C.delay << 4;
    D_03004BBC.field_148 = 0;
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    func_0805EE78(0xA);
    func_08000BD8(2, 0);
    func_0805EE78(0xA);
    func_08008B58(0x28);
    func_0805EE78(0xA);
    func_08003D78(4, func_0800C6A4);
    func_0805EE78(4);
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 3;
    D_03004BBC.target_y_2 = 4;
    D_03004BBC.speed_2 = 0x8000;
    D_03004BBC.delay_2 = D_0200000C.delay << 4;
    D_03004BBC.field_148 = 0;
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    func_08000BD8(2, 3);
    func_0805EE78(0x3C);
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 8;
    D_03004BBC.target_y_2 = 4;
    D_03004BBC.speed_2 = 0x8000;
    D_03004BBC.delay_2 = D_0200000C.delay << 4;
    D_03004BBC.field_148 = 0;
    func_08003D78(4, func_0800C680);
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    func_08000BD8(2, 2);
    func_0805EE78(0x3C);
    func_08008B58(0x29);
    func_0805EE78(0x14);
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 2;
    D_03004BBC.target_y_2 = 8;
    D_03004BBC.speed_2 = 0x8000;
    D_03004BBC.delay_2 = D_0200000C.delay << 4;
    D_03004BBC.field_148 = 0;
    func_0805EE78(0x78);
    func_08000BD8(1, 1);
    D_03004BBC.y -= 0x20000;
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 2;
    D_03004BBC.target_y_2 = 12;
    D_03004BBC.speed_2 = 0x8000;
    D_03004BBC.delay_2 = D_0200000C.delay << 4;
    D_03004BBC.field_148 = 0;
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    D_03004BBC.flags_2 = 0;
    D_03004BBC.y += 0x20000;
    D_03004BBC.field_E8 = 10;
    D_03004BBC.target_x = 5;
    D_03004BBC.target_y = 2;
    D_03004BBC.speed = 0x10000;
    D_03004BBC.delay = D_0200000C.delay << 3;
    D_03004BBC.field_C0 = 1;
    while (D_03004BBC.field_E8 != 1)
        func_0805EE78(1);
    D_03004BBC.field_E8 = 0;
    func_080019B4(7);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
}
