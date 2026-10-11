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
    u8 pad_190[0x8];
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
    u8 pad_438[0x40];
    u16 sprite8_mode;
    u8 pad_47A[0x26];
    u16 sprite8_state;
    u8 pad_4A2[0x8];
    u16 sprite8_target_x;
    u16 sprite8_target_y;
    u16 sprite8_delay;
    u8 pad_4B0[0xC];
    u32 sprite8_speed;
};

extern struct Obj D_03004BBC;

extern const u8 D_0832ABDC[];
void func_08008024(void);
void func_0800C680(void);
void func_0800C6A4(void);
void func_0800FBA0(void);
void func_0800FE14(void);
void func_08010088(void);

void func_0800E8B8(void)
{
    u16 i;

    func_0805EE78(0x3C);
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 0x17;
    D_03004BBC.sprite1_target_y = 0x1A;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    func_08008B70(1, 0x17, 0x1A);
    func_08008B70(2, 0x17, 0x1A);
    func_08008B70(3, 0x17, 0x1A);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 0x16;
    D_03004BBC.sprite4_target_y = 0x19;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 0x17;
    D_03004BBC.sprite3_target_y = 0x18;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 0x18;
    D_03004BBC.sprite2_target_y = 0x19;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    func_08000BD8(4, 3);
    func_08000BD8(3, 1);
    func_08000BD8(2, 2);
    func_0805EE78(0x3C);
    func_08008B58(0x49);
    func_0805EE78(0x3C);
    func_08003D78(4, func_0800FBA0);
    func_08003D78(5, func_0800FE14);
    func_08003D78(6, func_08010088);
    func_0805EE78(0x3C);
    func_0805EE78(0x3C);
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 0x17;
    D_03004BBC.sprite1_target_y = 0x17;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 0x1B;
    D_03004BBC.sprite1_target_y = 0x17;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 0x1B;
    D_03004BBC.sprite1_target_y = 0xA;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    func_08000BD8(1, 3);
    func_0805EE78(0x1E);
    func_08000BD8(1, 2);
    func_0805EE78(0x1E);
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 0x15;
    D_03004BBC.sprite1_target_y = 0xA;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    func_08000BD8(1, 0);
    func_0805EE78(0x3C);
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 0x17;
    D_03004BBC.sprite1_target_y = 0xA;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    func_08000BD8(1, 0);
    func_0805EE78(0x1E);
    func_08000BD8(1, 3);
    func_0805EE78(0x1E);
    func_08000BD8(1, 2);
    func_0805EE78(0x1E);
    func_0805EE78(0x3C);
    func_0805EE78(0x3C);
    func_08000BD8(1, 3);
    func_0805EE78(0x1E);
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    func_08000BD8(1, 1);
    func_0805EE78(0x1E);
    func_0805EE78(0x3C);
    func_08008B58(0x4A);
    func_0805EE78(0x3C);
    D_03004BBC.sprite6_state = 0xA;
    D_03004BBC.sprite6_target_x = 0x11;
    D_03004BBC.sprite6_target_y = 9;
    D_03004BBC.sprite6_speed = 0x10000;
    D_03004BBC.sprite6_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite6_mode = 1;
    D_03004BBC.sprite7_state = 0xA;
    D_03004BBC.sprite7_target_x = 0x11;
    D_03004BBC.sprite7_target_y = 8;
    D_03004BBC.sprite7_speed = 0x10000;
    D_03004BBC.sprite7_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite7_mode = 1;
    D_03004BBC.sprite8_state = 0xA;
    D_03004BBC.sprite8_target_x = 0x11;
    D_03004BBC.sprite8_target_y = 7;
    D_03004BBC.sprite8_speed = 0x10000;
    D_03004BBC.sprite8_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite8_mode = 1;
    while (D_03004BBC.sprite6_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite6_state = 0xA;
    D_03004BBC.sprite6_target_x = 0x11;
    D_03004BBC.sprite6_target_y = 0xB;
    D_03004BBC.sprite6_speed = 0x10000;
    D_03004BBC.sprite6_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite6_mode = 1;
    while (D_03004BBC.sprite7_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite7_state = 0xA;
    D_03004BBC.sprite7_target_x = 0x11;
    D_03004BBC.sprite7_target_y = 0xC;
    D_03004BBC.sprite7_speed = 0x10000;
    D_03004BBC.sprite7_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite7_mode = 1;
    while (D_03004BBC.sprite8_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite8_state = 0xA;
    D_03004BBC.sprite8_target_x = 0x11;
    D_03004BBC.sprite8_target_y = 0xA;
    D_03004BBC.sprite8_speed = 0x10000;
    D_03004BBC.sprite8_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite8_mode = 1;
    while (D_03004BBC.sprite6_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite6_state = 0xA;
    D_03004BBC.sprite6_target_x = 0x14;
    D_03004BBC.sprite6_target_y = 0xB;
    D_03004BBC.sprite6_speed = 0x10000;
    D_03004BBC.sprite6_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite6_mode = 1;
    while (D_03004BBC.sprite7_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite7_state = 0xA;
    D_03004BBC.sprite7_target_x = 0x13;
    D_03004BBC.sprite7_target_y = 0xC;
    D_03004BBC.sprite7_speed = 0x10000;
    D_03004BBC.sprite7_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite7_mode = 1;
    while (D_03004BBC.sprite8_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite8_state = 0xA;
    D_03004BBC.sprite8_target_x = 0x13;
    D_03004BBC.sprite8_target_y = 0xA;
    D_03004BBC.sprite8_speed = 0x10000;
    D_03004BBC.sprite8_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite8_mode = 1;
    while (D_03004BBC.sprite8_state != 1)
        func_0805EE78(1);
    func_0805EE78(0xA);
    func_08000BD8(4, 2);
    func_0805EE78(0xA);
    func_08000BD8(3, 2);
    func_0805EE78(0xA);
    func_08000BD8(1, 2);
    func_0805EE78(0xA);
    func_08000BD8(2, 2);
    func_0805EE78(0x3C);
    func_08008B58(0x4B);
    func_0805EE78(0x3C);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 0x1A;
    D_03004BBC.sprite5_target_y = 0xB;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_state = 0xA;
    D_03004BBC.sprite5_target_x = 0x1A;
    D_03004BBC.sprite5_target_y = 0xD;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_state = 0xA;
    D_03004BBC.sprite5_target_x = 0x16;
    D_03004BBC.sprite5_target_y = 0xD;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_state = 0xA;
    D_03004BBC.sprite5_target_x = 0x16;
    D_03004BBC.sprite5_target_y = 0xC;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    func_08000BD8(5, 0);
    func_0805EE78(0xA);
    func_08000BD8(4, 1);
    func_0805EE78(0x3C);
    func_08008B58(0x4C);
    func_0805EE78(0x3C);
    D_03004BBC.sprite5_state = 0xA;
    D_03004BBC.sprite5_target_x = 0x14;
    D_03004BBC.sprite5_target_y = 0xC;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    func_0805EE78(0xA);
    func_08000BD8(4, 2);
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    func_08000BD8(5, 0);
    func_0805EE78(0xA);
    func_08000BD8(6, 1);
    func_0805EE78(0x3C);
    func_08008B58(0x4D);
    func_0805EE78(0x3C);
    D_03004BBC.sprite6_state = 0xA;
    D_03004BBC.sprite6_target_x = 0x11;
    D_03004BBC.sprite6_target_y = 0xB;
    D_03004BBC.sprite6_speed = 0x10000;
    D_03004BBC.sprite6_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite6_mode = 1;
    while (D_03004BBC.sprite6_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite6_state = 0xA;
    D_03004BBC.sprite6_target_x = 0x11;
    D_03004BBC.sprite6_target_y = 9;
    D_03004BBC.sprite6_speed = 0x10000;
    D_03004BBC.sprite6_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite6_mode = 1;
    D_03004BBC.sprite8_state = 0xA;
    D_03004BBC.sprite8_target_x = 0x11;
    D_03004BBC.sprite8_target_y = 0xA;
    D_03004BBC.sprite8_speed = 0x10000;
    D_03004BBC.sprite8_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite8_mode = 1;
    D_03004BBC.sprite7_state = 0xA;
    D_03004BBC.sprite7_target_x = 0x11;
    D_03004BBC.sprite7_target_y = 0xC;
    D_03004BBC.sprite7_speed = 0x10000;
    D_03004BBC.sprite7_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite7_mode = 1;
    while (D_03004BBC.sprite6_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite6_state = 0xA;
    D_03004BBC.sprite6_target_x = 4;
    D_03004BBC.sprite6_target_y = 9;
    D_03004BBC.sprite6_speed = 0x10000;
    D_03004BBC.sprite6_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite6_mode = 1;
    while (D_03004BBC.sprite8_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite8_state = 0xA;
    D_03004BBC.sprite8_target_x = 0x11;
    D_03004BBC.sprite8_target_y = 9;
    D_03004BBC.sprite8_speed = 0x10000;
    D_03004BBC.sprite8_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite8_mode = 1;
    D_03004BBC.sprite7_state = 0xA;
    D_03004BBC.sprite7_target_x = 0x11;
    D_03004BBC.sprite7_target_y = 9;
    D_03004BBC.sprite7_speed = 0x10000;
    D_03004BBC.sprite7_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite7_mode = 1;
    while (D_03004BBC.sprite8_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite8_state = 0xA;
    D_03004BBC.sprite8_target_x = 5;
    D_03004BBC.sprite8_target_y = 9;
    D_03004BBC.sprite8_speed = 0x10000;
    D_03004BBC.sprite8_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite8_mode = 1;
    while (D_03004BBC.sprite7_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite7_state = 0xA;
    D_03004BBC.sprite7_target_x = 5;
    D_03004BBC.sprite7_target_y = 9;
    D_03004BBC.sprite7_speed = 0x10000;
    D_03004BBC.sprite7_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite7_mode = 1;
    D_03004BBC.sprite5_state = 0xA;
    D_03004BBC.sprite5_target_x = 0x14;
    D_03004BBC.sprite5_target_y = 0xA;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_state = 0xA;
    D_03004BBC.sprite5_target_x = 0x16;
    D_03004BBC.sprite5_target_y = 0xA;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    func_08000BD8(4, 0);
    func_0805EE78(0xA);
    func_08000BD8(3, 0);
    func_0805EE78(0x3C);
    func_08008B58(0x4E);
    func_0805EE78(0x3C);
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 0x18;
    D_03004BBC.sprite1_target_y = 0xA;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    func_0805EE78(0xA);
    D_03004BBC.sprite5_state = 0xA;
    D_03004BBC.sprite5_target_x = 0x17;
    D_03004BBC.sprite5_target_y = 0xA;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    func_08000BD8(1, 2);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 0x17;
    D_03004BBC.sprite5_target_y = 9;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_flags = 0;
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 0x17;
    D_03004BBC.sprite1_target_y = 0xA;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 0x17;
    D_03004BBC.sprite1_target_y = 9;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_flags = 0;
    D_03004BBC.sprite2_state = 0xA;
    D_03004BBC.sprite2_target_x = 0x17;
    D_03004BBC.sprite2_target_y = 0xA;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 0x17;
    D_03004BBC.sprite2_target_y = 9;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_flags = 0;
    D_03004BBC.sprite3_state = 0xA;
    D_03004BBC.sprite3_target_x = 0x17;
    D_03004BBC.sprite3_target_y = 0xA;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 0x17;
    D_03004BBC.sprite3_target_y = 9;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_flags = 0;
    D_03004BBC.sprite4_state = 0xA;
    D_03004BBC.sprite4_target_x = 0x17;
    D_03004BBC.sprite4_target_y = 0xA;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 0x17;
    D_03004BBC.sprite4_target_y = 9;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_flags = 0;
    func_08003D78(4, func_0800C6A4);
    func_0805EE78(0x3C);
    func_0805EE78(1);
    func_080079E8(0x1D, 4, 3, 5, D_0832ABDC);
    func_0805EE78(1);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    func_0805EE78(0x3C);
    func_08008B58(0x4F);
    func_0805EE78(0x3C);
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 8;
    D_03004BBC.sprite1_target_y = 3;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_state = 0xA;
    D_03004BBC.sprite2_target_x = 6;
    D_03004BBC.sprite2_target_y = 3;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 8;
    D_03004BBC.sprite1_target_y = 2;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 0xE;
    D_03004BBC.sprite1_target_y = 2;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    D_03004BBC.sprite2_state = 0xA;
    D_03004BBC.sprite2_target_x = 8;
    D_03004BBC.sprite2_target_y = 3;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_state = 0xA;
    D_03004BBC.sprite2_target_x = 8;
    D_03004BBC.sprite2_target_y = 2;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 0xE;
    D_03004BBC.sprite2_target_y = 2;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_flags = 0;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_flags = 0;
    for (i = 0; i < 32; i++)
    {
        func_08008324(-0x20000, 0);
        func_0805EE78(1);
    }
    func_0805EE78(0x3C);
    func_08008B58(0x50);
    func_0805EE78(0x3C);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 0xE;
    D_03004BBC.sprite3_target_y = 2;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 0xE;
    D_03004BBC.sprite4_target_y = 2;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_flags = 0;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_flags = 0;
    func_08003D78(4, func_0800C6A4);
    func_0805EE78(0x3C);
    func_08007188(0x1C, 0xD, 0xC, 2);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
}
