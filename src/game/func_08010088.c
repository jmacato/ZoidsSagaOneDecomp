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
    u8 pad_0[0x148];
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

void func_08010088(void)
{
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 0x1B;
    D_03004BBC.target_y_2 = 0x18;
    D_03004BBC.speed_2 = 0x10000;
    D_03004BBC.delay_2 = D_0200000C.delay << 3;
    D_03004BBC.field_148 = 1;
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 0x1B;
    D_03004BBC.target_y_2 = 0xA;
    D_03004BBC.speed_2 = 0x10000;
    D_03004BBC.delay_2 = D_0200000C.delay << 3;
    D_03004BBC.field_148 = 1;
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 0x1C;
    D_03004BBC.target_y_2 = 0xA;
    D_03004BBC.speed_2 = 0x10000;
    D_03004BBC.delay_2 = D_0200000C.delay << 3;
    D_03004BBC.field_148 = 1;
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 0x1C;
    D_03004BBC.target_y_2 = 0x9;
    D_03004BBC.speed_2 = 0x10000;
    D_03004BBC.delay_2 = D_0200000C.delay << 3;
    D_03004BBC.field_148 = 1;
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 0x26;
    D_03004BBC.target_y_2 = 0x8;
    D_03004BBC.speed_2 = 0x10000;
    D_03004BBC.delay_2 = D_0200000C.delay << 3;
    D_03004BBC.field_148 = 1;
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 0x2D;
    D_03004BBC.target_y_2 = 0x8;
    D_03004BBC.speed_2 = 0x10000;
    D_03004BBC.delay_2 = D_0200000C.delay << 3;
    D_03004BBC.field_148 = 1;
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 0x1E;
    D_03004BBC.target_y_2 = 0x8;
    D_03004BBC.speed_2 = 0x10000;
    D_03004BBC.delay_2 = D_0200000C.delay << 3;
    D_03004BBC.field_148 = 1;
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 0x1C;
    D_03004BBC.target_y_2 = 0xA;
    D_03004BBC.speed_2 = 0x10000;
    D_03004BBC.delay_2 = D_0200000C.delay << 3;
    D_03004BBC.field_148 = 1;
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    D_03004BBC.field_170 = 10;
    D_03004BBC.target_x_2 = 0x18;
    D_03004BBC.target_y_2 = 0xB;
    D_03004BBC.speed_2 = 0x10000;
    D_03004BBC.delay_2 = D_0200000C.delay << 3;
    D_03004BBC.field_148 = 1;
    while (D_03004BBC.field_170 != 1)
        func_0805EE78(1);
    func_08000BD8(2, 2);
    func_08003DD8(6);
}
