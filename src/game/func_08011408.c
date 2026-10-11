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
u8 func_08008D28(s32);
void func_08006E08(void);
void func_080129CC(void);
struct Obj
{
    u8 pad_0[0xC0];
    u16 sprite1_mode;
    u8 pad_C2[0x26];
    u16 sprite1_state;
    u8 pad_EA[0x8];
    u16 sprite1_target_x;
    u16 sprite1_target_y;
    u16 sprite1_delay;
    u8 pad_F8[0xC];
    u32 sprite1_speed;
    u8 pad_108[0x40];
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
    u8 pad_218[0x8];
    u16 sprite4_flags;
    u8 pad_222[0x36];
    u16 sprite4_mode;
    u8 pad_25A[0x26];
    u16 sprite4_state;
    u8 pad_282[0x8];
    u16 sprite4_target_x;
    u16 sprite4_target_y;
    u16 sprite4_delay;
    u8 pad_290[0xC];
    u32 sprite4_speed;
    u8 pad_2A0[0x8];
    u16 sprite5_flags;
    u8 pad_2AA[0x36];
    u16 sprite5_mode;
    u8 pad_2E2[0x26];
    u16 sprite5_state;
    u8 pad_30A[0x8];
    u16 sprite5_target_x;
    u16 sprite5_target_y;
    u16 sprite5_delay;
    u8 pad_318[0xC];
    u32 sprite5_speed;
    u8 pad_328[0x8];
    u16 sprite6_flags;
    u8 pad_332[0x36];
    u16 sprite6_mode;
    u8 pad_36A[0x26];
    u16 sprite6_state;
    u8 pad_392[0x8];
    u16 sprite6_target_x;
    u16 sprite6_target_y;
    u16 sprite6_delay;
    u8 pad_3A0[0xC];
    u32 sprite6_speed;
    u8 pad_3B0[0x40];
    u16 sprite7_mode;
    u8 pad_3F2[0x26];
    u16 sprite7_state;
    u8 pad_41A[0x8];
    u16 sprite7_target_x;
    u16 sprite7_target_y;
    u16 sprite7_delay;
    u8 pad_428[0xC];
    u32 sprite7_speed;
    u8 pad_438[0x8];
    u16 sprite8_flags;
    u8 pad_442[0x32];
    u32 sprite8_anim;
    u8 pad_478[0x16];
    u16 sprite8_x;
    u16 sprite8_y;
};

extern struct Obj D_03004BBC;

void func_08008024(void);
void func_0800C680(void);
void func_0800C6A4(void);

void func_08011408(void)
{
    u16 i;
    u8 result;

    func_08008B70(1, 0, 3);
    D_03004BBC.sprite2_state = 0xA;
    D_03004BBC.sprite2_target_x = 2;
    D_03004BBC.sprite2_target_y = 3;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    func_08008B70(2, 0, 3);
    D_03004BBC.sprite3_state = 0xA;
    D_03004BBC.sprite3_target_x = 1;
    D_03004BBC.sprite3_target_y = 3;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_state = 0xA;
    D_03004BBC.sprite3_target_x = 1;
    D_03004BBC.sprite3_target_y = 4;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    func_08008B70(4, 0, 3);
    D_03004BBC.sprite5_state = 0xA;
    D_03004BBC.sprite5_target_x = 1;
    D_03004BBC.sprite5_target_y = 3;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_state = 0xA;
    D_03004BBC.sprite5_target_x = 1;
    D_03004BBC.sprite5_target_y = 2;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    func_08008B70(3, 0, 3);
    D_03004BBC.sprite4_state = 0xA;
    D_03004BBC.sprite4_target_x = 1;
    D_03004BBC.sprite4_target_y = 3;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    func_08000BD8(3, 3);
    func_08000BD8(5, 3);
    for (i = 0; i < 24; i++)
    {
        func_08008324(0x10000, 0);
        func_0805EE78(1);
    }
    for (i = 0; i < 32; i++)
    {
        func_08008324(0, -0x10000);
        func_0805EE78(1);
    }
    D_03004BBC.sprite7_state = 0xB;
    D_03004BBC.sprite7_target_x = D_03004BBC.sprite8_x;
    D_03004BBC.sprite7_target_y = D_03004BBC.sprite8_y;
    D_03004BBC.sprite7_speed = 0x10000;
    D_03004BBC.sprite7_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite7_mode = 1;
    func_08000BD8(8, 1);
    D_03004BBC.sprite8_flags |= 0x400;
    func_080019EC(0x6F);
    while (!(D_03004BBC.sprite8_flags & 4))
    {
        if (D_03004BBC.sprite8_anim == 0x10010)
            func_08008B70(6, 0xFF, 0xFF);
        if (D_03004BBC.sprite8_anim == 0x10052)
            func_080019EC(0x44);
        func_0805EE78(1);
    }
    func_08000BD8(8, 0);
    D_03004BBC.sprite8_flags &= 0xFBFF;
    func_0805EE78(0x3C);
    func_08008B58(0x5A);
    func_0805EE78(0x3C);
    func_08008B70(5, 4, 5);
    D_03004BBC.sprite6_state = 0xA;
    D_03004BBC.sprite6_target_x = 4;
    D_03004BBC.sprite6_target_y = 3;
    D_03004BBC.sprite6_speed = 0x10000;
    D_03004BBC.sprite6_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite6_mode = 1;
    while (D_03004BBC.sprite6_state != 1)
        func_0805EE78(1);
    func_08000BD8(6, 2);
    func_0805EE78(0x3C);
    func_08008B58(0x5B);
    func_0805EE78(0x3C);
    result = func_08008D28(1);
    func_080019B4(0x1E);
    func_0805EE78(1);
    if (result == 1)
    {
    func_08006E08();
    func_08007188(D_02007560[0], D_02007560[1], D_02007560[2], 0);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
        return;
    }
    func_08000F88(0x12E);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    func_0805EE78(0x3C);
    func_08008B58(0x5C);
    func_0805EE78(0x3C);
    D_03004BBC.sprite6_state = 0xB;
    D_03004BBC.sprite6_target_x = 4;
    D_03004BBC.sprite6_target_y = 5;
    D_03004BBC.sprite6_speed = 0x10000;
    D_03004BBC.sprite6_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite6_mode = 1;
    while (D_03004BBC.sprite6_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite6_flags &= 0x7FFF;
    func_0805EE78(0x3C);
    func_08008B58(0x5D);
    func_0805EE78(0x3C);
    D_03004BBC.sprite2_state = 0xA;
    D_03004BBC.sprite2_target_x = 4;
    D_03004BBC.sprite2_target_y = 3;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 4;
    D_03004BBC.sprite2_target_y = 2;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = D_03004BBC.sprite8_x;
    D_03004BBC.sprite2_target_y = D_03004BBC.sprite8_y;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    func_08000BD8(8, 1);
    D_03004BBC.sprite8_flags |= 0x400;
    func_080019EC(0x6F);
    while (!(D_03004BBC.sprite8_flags & 4))
    {
        if (D_03004BBC.sprite8_anim == 0x10010)
            func_08008B70(1, 0xFF, 0xFF);
        if (D_03004BBC.sprite8_anim == 0x10052)
            func_080019EC(0x44);
        func_0805EE78(1);
    }
    func_08000BD8(8, 0);
    D_03004BBC.sprite8_flags &= 0xFBFF;
    D_03004BBC.sprite3_state = 0xA;
    D_03004BBC.sprite3_target_x = 4;
    D_03004BBC.sprite3_target_y = 4;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 4;
    D_03004BBC.sprite3_target_y = 2;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = D_03004BBC.sprite8_x;
    D_03004BBC.sprite3_target_y = D_03004BBC.sprite8_y;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    func_08000BD8(8, 1);
    D_03004BBC.sprite8_flags |= 0x400;
    func_080019EC(0x6F);
    while (!(D_03004BBC.sprite8_flags & 4))
    {
        if (D_03004BBC.sprite8_anim == 0x10010)
            func_08008B70(2, 0xFF, 0xFF);
        if (D_03004BBC.sprite8_anim == 0x10052)
            func_080019EC(0x44);
        func_0805EE78(1);
    }
    func_08000BD8(8, 0);
    D_03004BBC.sprite8_flags &= 0xFBFF;
    func_0805EE78(0x3C);
    func_08008B58(0x5E);
    func_0805EE78(0x3C);
    func_08008B70(0, 0, 4);
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 2;
    D_03004BBC.sprite1_target_y = 4;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 2;
    D_03004BBC.sprite4_target_y = 4;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_flags &= 0x7FFF;
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 2;
    D_03004BBC.sprite5_target_y = 4;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_flags &= 0x7FFF;
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 4;
    D_03004BBC.sprite1_target_y = 4;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 4;
    D_03004BBC.sprite1_target_y = 2;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = D_03004BBC.sprite8_x;
    D_03004BBC.sprite1_target_y = D_03004BBC.sprite8_y;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    func_08000BD8(8, 1);
    D_03004BBC.sprite8_flags |= 0x400;
    func_080019EC(0x6F);
    while (!(D_03004BBC.sprite8_flags & 4))
    {
        if (D_03004BBC.sprite8_anim == 0x10010)
            func_08008B70(0, 0xFF, 0xFF);
        if (D_03004BBC.sprite8_anim == 0x10052)
            func_080019EC(0x44);
        func_0805EE78(1);
    }
    func_08000BD8(8, 0);
    D_03004BBC.sprite8_flags &= 0xFBFF;
    func_08003D78(4, func_0800C6A4);
    func_0805EE78(0x3C);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    func_08007188(0x30, 8, 1, 0);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    func_080129CC();
}
