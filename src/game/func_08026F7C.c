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
    u8 pad_C2[0x14];
    u16 sprite1_x;
    u16 sprite1_y;
    u8 pad_DA[0xE];
    u16 sprite1_state;
    u8 pad_EA[0x8];
    u16 sprite1_target_x;
    u16 sprite1_target_y;
    u16 sprite1_delay;
    u8 pad_F8[0xC];
    u32 sprite1_speed;
    u8 pad_108[0x8];
    u16 sprite2_flags;
    u8 pad_112[0x2E];
    u16 sprite2_dir;
    u8 pad_142[0x56];
    u16 sprite3_flags;
    u8 pad_19A[0x36];
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

void func_08026F7C(void)
{
    u8 i;

    while (D_03004BBC.sprite1_x != 9 || D_03004BBC.sprite1_y != 5)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 1;
    func_0805EE78(0x1E);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 7;
    D_03004BBC.sprite1_target_y = 5;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 7;
    D_03004BBC.sprite1_target_y = 2;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 5;
    D_03004BBC.sprite1_target_y = 2;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    func_080019B4(9);
    func_0805EE78(0x1E);
    func_08008B58(0x296);
    func_0805EE78(0x1E);
    if (func_08008D28(0x25) == 1)
    {
        func_08006E08();
        func_08007188(D_02007560[0], D_02007560[1], D_02007560[2], 0);
        func_080014A8(0, func_0800BEC8);
        return;
    }
    func_08000F88(0x133);
    func_08008B70(1, 4, 1);
    func_08000BD8(2, 1);
    D_03004BBC.sprite2_flags |= 0x400;
    func_080019B4(0x14);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    func_0805EE78(0x1E);
    func_08008B58(0x297);
    func_0805EE78(0x1E);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 2;
    D_03004BBC.sprite1_target_y = 2;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 2;
    D_03004BBC.sprite1_target_y = 5;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_flags = 0;
    func_080019EC(0x82);
    func_0805EE78(0x3C);
    for (i = 0; i < 64; i++)
    {
        func_08008324(0, -0x10000);
        func_0805EE78(1);
    }
    func_0805EE78(0x3C);
    func_0805EE78(0x1E);
    func_08008B58(0x298);
    func_0805EE78(0x1E);
    func_08008B70(2, 8, 2);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 4;
    D_03004BBC.sprite3_target_y = 2;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    func_08000BD8(3, 0);
    func_0805EE78(0x1E);
    func_08008B58(0x299);
    func_0805EE78(0x1E);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 3;
    D_03004BBC.sprite3_target_y = 2;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 3;
    D_03004BBC.sprite3_target_y = 1;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    func_0805EE78(0x3C);
    func_0805EE78(0x1E);
    func_08008B58(0x29A);
    func_0805EE78(0x1E);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 2;
    D_03004BBC.sprite3_target_y = 1;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    func_080019EC(0x6F);
    func_0805EE78(0x3C);
    D_03004BBC.sprite2_dir = 0;
    func_080089A0(2, 0xFD);
    D_03004BBC.sprite2_flags |= 0x400;
    func_080019EC(0x5A);
    while (!(D_03004BBC.sprite2_flags & 4))
        func_0805EE78(1);
    D_03004BBC.sprite2_flags = 0;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 2;
    D_03004BBC.sprite3_target_y = 5;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_flags = 0;
    func_08007188(0x11C, 2, 8, 2);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
}
