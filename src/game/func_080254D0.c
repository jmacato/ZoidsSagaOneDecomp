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
    u8 pad_218[0x40];
    u16 sprite4_mode;
    u8 pad_25A[0x26];
    u16 sprite4_state;
    u8 pad_282[0x8];
    u16 sprite4_target_x;
    u16 sprite4_target_y;
    u16 sprite4_delay;
    u8 pad_290[0xC];
    u32 sprite4_speed;
    u8 pad_2A0[0x40];
    u16 sprite5_mode;
    u8 pad_2E2[0x26];
    u16 sprite5_state;
    u8 pad_30A[0x8];
    u16 sprite5_target_x;
    u16 sprite5_target_y;
    u16 sprite5_delay;
    u8 pad_318[0xC];
    u32 sprite5_speed;
    u8 pad_328[0x40];
    u16 sprite6_mode;
    u8 pad_36A[0x26];
    u16 sprite6_state;
    u8 pad_392[0x8];
    u16 sprite6_target_x;
    u16 sprite6_target_y;
    u16 sprite6_delay;
    u8 pad_3A0[0xC];
    u32 sprite6_speed;
};

extern struct Obj D_03004BBC;

extern const u8 D_0832AF5C[];
extern const u8 D_0832AFE8[];
void func_0800C680(void);
void func_0800C6A4(void);
void func_0800C6C8(void);
void func_0800C6E8(void);
void func_08025E6C(void);
void func_080262E0(void);

void func_080016A8(s32);
void func_0800196C(void);
void func_0802636C(void);

void func_080254D0(void)
{
    u8 i;

    func_0805EE78(0x78);
    func_08003D78(4, func_08025E6C);
    func_08008B70(0, 0xA, 0x10);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 0xA;
    D_03004BBC.sprite1_target_y = 9;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    for (i = 0; i < 80; i++)
    {
        func_08008324(0, -0x10000);
        func_0805EE78(1);
    }
    func_08008B58(0x271);
    func_0805EE78(0x1E);
    func_0805EE78(0xB4);
    func_0805EE78(0x78);
    func_08008B58(0x272);
    func_0805EE78(0x1E);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 0xA;
    D_03004BBC.sprite1_target_y = 7;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    func_0805EE78(0x78);
    func_08000BD8(1, 1);
    for (i = 0; i < 112; i++)
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
    }
    func_08008B70(4, 0xA, 0x10);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 0xA;
    D_03004BBC.sprite5_target_y = 0xF;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    func_08008B70(1, 0xA, 0x10);
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 0xA;
    D_03004BBC.sprite2_target_y = 9;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 0xA;
    D_03004BBC.sprite5_target_y = 9;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 9;
    D_03004BBC.sprite5_target_y = 8;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    func_08000BD8(5, 0);
    func_08008B58(0x273);
    func_0805EE78(0x1E);
    for (i = 0; i < 96; i++)
    {
        func_08008324(0, -0x10000);
        func_0805EE78(1);
    }
    func_0805EE78(0x78);
    func_08003DD8(4);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 4;
    D_03004BBC.sprite4_target_y = 3;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    func_08000BD8(4, 1);
    func_0805EE78(0x1E);
    func_08000BD8(1, 2);
    func_08008B58(0x274);
    func_0805EE78(0x1E);
    func_080019EC(0x62);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 4;
    D_03004BBC.sprite4_target_y = 4;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    func_08000BD8(4, 3);
    func_08000BD8(1, 0);
    func_0805EE78(0x3C);
    func_08008B58(0x275);
    func_0805EE78(0x1E);
    func_080019EC(0x6B);
    func_0805EE78(0x3C);
    func_08008B58(0x276);
    func_0805EE78(0x1E);
    func_08008B58(0x277);
    func_0805EE78(0x1E);
    func_080016A8(7);
    func_0800196C();
    func_080079E8(0x121, 8, 5, 7, D_0832AF5C);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x1E);
    func_0805EE78(0x3C);
    func_08008B70(4, 8, 0xA);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 8;
    D_03004BBC.sprite5_target_y = 7;
    D_03004BBC.sprite5_speed = 0x20000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite5_mode = 2;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    func_080019B4(4);
    func_0805EE78(0x3C);
    func_08008B58(0x278);
    func_0805EE78(0x1E);
    func_08008B70(5, 8, 0xA);
    D_03004BBC.sprite6_state = 0xB;
    D_03004BBC.sprite6_target_x = 8;
    D_03004BBC.sprite6_target_y = 7;
    D_03004BBC.sprite6_speed = 0x20000;
    D_03004BBC.sprite6_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite6_mode = 2;
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 7;
    D_03004BBC.sprite5_target_y = 7;
    D_03004BBC.sprite5_speed = 0x20000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite5_mode = 2;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    func_08000BD8(5, 3);
    while (D_03004BBC.sprite6_state != 1)
        func_0805EE78(1);
    func_0805EE78(0x3C);
    func_08008B58(0x279);
    func_0805EE78(0x1E);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 8;
    D_03004BBC.sprite1_target_y = 0xA;
    D_03004BBC.sprite1_speed = 0x20000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite1_mode = 2;
    D_03004BBC.sprite6_state = 0xB;
    D_03004BBC.sprite6_target_x = 9;
    D_03004BBC.sprite6_target_y = 7;
    D_03004BBC.sprite6_speed = 0x20000;
    D_03004BBC.sprite6_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite6_mode = 2;
    while (D_03004BBC.sprite6_state != 1)
        func_0805EE78(1);
    func_08000BD8(6, 1);
    func_0805EE78(8);
    func_08000BD8(5, 1);
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_flags = 0;
    func_0805EE78(0x1E);
    func_08008B58(0x27A);
    func_0805EE78(0x1E);
    func_08003D78(4, func_0800C6A4);
    func_0805EE78(0x3C);
    func_080079E8(0x127, 0x11, 2, 5, D_0832AFE8);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    func_08008B70(0, 0xE, 2);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 6;
    D_03004BBC.sprite1_target_y = 2;
    D_03004BBC.sprite1_speed = 0x20000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite1_mode = 2;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 6;
    D_03004BBC.sprite1_target_y = 1;
    D_03004BBC.sprite1_speed = 0x20000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite1_mode = 2;
    func_08008B70(3, 0xE, 2);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 5;
    D_03004BBC.sprite4_target_y = 2;
    D_03004BBC.sprite4_speed = 0x20000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite4_mode = 2;
    func_0805EE78(0x1E);
    func_08008B70(1, 0xE, 2);
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 6;
    D_03004BBC.sprite2_target_y = 2;
    D_03004BBC.sprite2_speed = 0x20000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite2_mode = 2;
    func_0805EE78(0x1E);
    func_08008B70(2, 0xE, 2);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 7;
    D_03004BBC.sprite3_target_y = 2;
    D_03004BBC.sprite3_speed = 0x20000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite3_mode = 2;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    func_08000BD8(4, 0);
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    func_08000BD8(2, 0);
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    func_08000BD8(3, 0);
    func_080019EC(0x81);
    *(vu16 *)0x04000050 = 0x3FBF;
    func_08003D78(4, func_0800C6E8);
    func_0805EE78(0xA);
    func_08003D78(4, func_0800C6C8);
    func_0805EE78(0xA);
    func_08003D78(4, func_0800C6E8);
    func_0805EE78(0xA);
    func_08003D78(4, func_0800C6C8);
    func_0805EE78(0xA);
    func_08003D78(4, func_0800C6E8);
    func_0805EE78(0xA);
    func_08003D78(4, func_0800C6C8);
    func_0805EE78(0xA);
    *(vu16 *)0x04000050 = 0x3FFF;
    func_0805EE78(0xB4);
    func_08008B58(0x27B);
    func_0805EE78(0x1E);
    func_08003D78(4, func_080262E0);
    func_0805EE78(0x3C);
    func_08008B58(0x27C);
    func_0805EE78(0x1E);
    func_08000BD8(2, 1);
    func_0805EE78(3);
    func_08000BD8(3, 1);
    func_0805EE78(3);
    func_08000BD8(4, 1);
    func_0805EE78(3);
    func_08000BD8(1, 1);
    func_0805EE78(0x1E);
    func_08008B58(0x27D);
    func_0805EE78(0x3C);
    func_08003DD8(4);
    func_08008B70(4, 0xFF, 0xFF);
    func_0805EE78(0x3C);
    func_08008B58(0x27E);
    func_0805EE78(0x1E);
    func_08000BD8(2, 0);
    func_08000BD8(3, 0);
    func_08000BD8(4, 0);
    func_0805EE78(0x1E);
    func_08003D78(4, func_0800C6A4);
    func_0805EE78(0x3C);
    func_08007188(0x127, 6, 1, 1);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    func_0802636C();
}
