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
    vu16 delay;
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

extern u16 D_02007560[];

void func_08008324(s32, s32);
s32 func_08008D28(s32);
void func_08006E08(void);
void func_080079E8(s32, s32, s32, s32, const void *);
void func_080089A0(s32, s32);
void func_08008E4C(s32);
void func_08009938(void);
void func_0803785C(s32);
void func_08001524(s32, void *);
void func_08037990(s32);
void func_08037920(s32);
void func_08006DFC(s32);
s32 func_08001040(s32);
void func_08000FD8(s32);
void func_0800BEC8(void);

struct Obj
{
    u8 pad_0[0x88];
    u16 sprite1_flags;
    u8 pad_8A[0x36];
    u16 sprite1_mode;
    u8 pad_C2[0x26];
    u16 sprite1_state;
    u8 pad_EA[0x8];
    u16 sprite1_target_x;
    u16 sprite1_target_y;
    u16 sprite1_delay;
    u8 pad_F8[0xC];
    u32 sprite1_speed;
    u8 pad_108[0x8];
    u16 sprite2_flags;
    u8 pad_112[0x36];
    u16 sprite2_mode;
    u8 pad_14A[0x26];
    u16 sprite2_state;
    u8 pad_172[0x8];
    u16 sprite2_target_x;
    u16 sprite2_target_y;
    u16 sprite2_delay;
    u8 pad_180[0xC];
    u32 sprite2_speed;
    u8 pad_190[0x40];
    u16 sprite3_mode;
    u8 pad_1D2[0x26];
    u16 sprite3_state;
    u8 pad_1FA[0x8];
    u16 sprite3_target_x;
    u16 sprite3_target_y;
    u16 sprite3_delay;
    u8 pad_208[0xC];
    u32 sprite3_speed;
};

extern struct Obj D_03004BBC;

void func_08008024(void);
void func_0800BEC8(void);
void func_0800C680(void);
void func_0800C6A4(void);

void func_080274B4(void)
{
    u8 i;

    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 4;
    D_03004BBC.sprite2_target_y = 4;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 4;
    D_03004BBC.sprite1_target_y = 8;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 4;
    D_03004BBC.sprite1_target_y = 6;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    func_080019B4(9);
    func_0805EE78(0x3C);
    func_08008B58(0x29B);
    func_0805EE78(0x1E);
    if (func_08008D28(0x26) == 1)
    {
        func_08006E08();
        func_08007188(D_02007560[0], D_02007560[1], D_02007560[2], 0);
        func_080014A8(0, func_0800BEC8);
        return;
    }
    func_08000F88(0x134);
    func_080019B4(0x14);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    func_0805EE78(0x1E);
    func_08008B58(0x29C);
    func_0805EE78(0x1E);
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 4;
    D_03004BBC.sprite2_target_y = 5;
    D_03004BBC.sprite2_speed = 0x4000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 5;
    D_03004BBC.sprite2_mode = 0xFFFF;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_flags |= 0x400;
    func_0805EE78(0x1E);
    func_08008B58(0x29D);
    func_0805EE78(0x1E);
    func_0805EE78(0x1E);
    func_08008B58(0x29E);
    func_0805EE78(0x1E);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 3;
    D_03004BBC.sprite1_target_y = 6;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 3;
    D_03004BBC.sprite1_target_y = 4;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 4;
    D_03004BBC.sprite1_target_y = 4;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 4;
    D_03004BBC.sprite1_target_y = 0;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_flags = 0;
    func_080019EC(0x82);
    func_0805EE78(0x1E);
    for (i = 0; i < 128; i++)
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
    }
    func_0805EE78(0x3C);
    func_0805EE78(0x1E);
    func_08008B58(0x29F);
    func_0805EE78(0x1E);
    func_08008B70(2, 6, 8);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 4;
    D_03004BBC.sprite3_target_y = 8;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 4;
    D_03004BBC.sprite3_target_y = 6;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    func_0805EE78(0x1E);
    func_08008B58(0x2A0);
    func_0805EE78(0x1E);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 4;
    D_03004BBC.sprite3_target_y = 5;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_flags = 0;
    func_0805EE78(0x1E);
    func_08008B58(0x2A1);
    func_0805EE78(0x1E);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 4;
    D_03004BBC.sprite3_target_y = 0;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    for (i = 0; i < 128; i++)
    {
        func_08008324(0, -0x10000);
        func_0805EE78(1);
    }
    func_0805EE78(0x1E);
    func_08003D78(4, func_0800C6A4);
    func_0805EE78(0x3C);
    func_08007188(0x119, 5, 8, 2);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
}
