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
    u8 pad_328[0x8];
    u16 sprite6_flags;
    u8 pad_332[0x36];
    u16 sprite6_mode;
};

extern struct Obj D_03004BBC;

extern const u8 D_0832AAC4[];
void func_08008024(void);
void func_0800C680(void);
void func_0800C6A4(void);

void func_080375B0(s32);
void func_08037424(s32);
void func_080375F0(void);

void func_0800E07C(void)
{
    u16 i;

    for (;;)
    {
        if (func_08001040(0x123))
        {
            func_080375B0(0);
            func_08037424(0);
            func_080375F0();
            break;
        }
        if (func_08001040(0x124))
        {
            func_080375B0(1);
            func_08037424(0);
            func_080375F0();
            break;
        }
        if (func_08001040(0x125))
        {
            func_080375B0(2);
            func_08037424(0);
            func_080375F0();
            break;
        }
        func_0805EE78(1);
    }
    D_03004BBC.sprite1_state = 1;
    func_08003D78(4, func_0800C6A4);
    func_0805EE78(0x3C);
    func_0805EE78(1);
    func_080079E8(6, 8, 6, 6, D_0832AAC4);
    D_03004BBC.sprite1_flags |= 0x400;
    func_0805EE78(1);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    func_08008B58(0x41);
    func_0805EE78(0x3C);
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 8;
    D_03004BBC.sprite2_target_y = 6;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_flags = 0;
    D_03004BBC.sprite3_state = 0xA;
    D_03004BBC.sprite3_target_x = 8;
    D_03004BBC.sprite3_target_y = 9;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 8;
    D_03004BBC.sprite3_target_y = 6;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_flags = 0;
    D_03004BBC.sprite4_state = 0xA;
    D_03004BBC.sprite4_target_x = 8;
    D_03004BBC.sprite4_target_y = 9;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 8;
    D_03004BBC.sprite4_target_y = 6;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_flags = 0;
    D_03004BBC.sprite5_state = 0xA;
    D_03004BBC.sprite5_target_x = 8;
    D_03004BBC.sprite5_target_y = 9;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 8;
    D_03004BBC.sprite5_target_y = 6;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_flags = 0;
    func_0805EE78(0x3C);
    func_08009938();
    func_08008B58(0x42);
    func_0805EE78(0x3C);
    D_03004BBC.sprite1_flags &= 0xFBFF;
    func_08000BD8(1, 1);
    func_0805EE78(0x3C);
    func_080019EC(0x82);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 8;
    D_03004BBC.sprite1_target_y = 7;
    D_03004BBC.sprite1_speed = 0x4000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 5;
    D_03004BBC.sprite1_mode = 0xFFFF;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 8;
    D_03004BBC.sprite1_target_y = 8;
    D_03004BBC.sprite1_speed = 0x8000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 4;
    D_03004BBC.sprite1_mode = 0;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 8;
    D_03004BBC.sprite1_target_y = 0xB;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite6_mode = 0;
    func_08000BD8(6, 2);
    D_03004BBC.sprite6_flags |= 0x400;
    func_080019EC(0x6D);
    func_0805EE78(0x3C);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 8;
    D_03004BBC.sprite1_target_y = 0xC;
    D_03004BBC.sprite1_speed = 0x8000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 4;
    D_03004BBC.sprite1_mode = 0;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    func_08003D78(4, func_0800C6A4);
    func_0805EE78(0x3C);
    func_08007188(9, 4, 1, 1);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
}
