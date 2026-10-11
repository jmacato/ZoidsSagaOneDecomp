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
    u8 pad_0[0x258];
    u16 sprite4_mode;
    u8 pad_25A[0x26];
    u16 sprite4_state;
    u8 pad_282[0x8];
    u16 sprite4_target_x;
    u16 sprite4_target_y;
    u16 sprite4_delay;
    u8 pad_290[0xC];
    u32 sprite4_speed;
};

extern struct Obj D_03004BBC;


void func_08025E6C(void)
{
    u16 i;

    func_0805EE78(0xB4);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 4;
    D_03004BBC.sprite4_target_y = 1;
    D_03004BBC.sprite4_speed = 0x20000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite4_mode = 2;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 4;
    D_03004BBC.sprite4_target_y = 7;
    D_03004BBC.sprite4_speed = 0x20000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite4_mode = 2;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 0x10;
    D_03004BBC.sprite4_target_y = 7;
    D_03004BBC.sprite4_speed = 0x20000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite4_mode = 2;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 0x10;
    D_03004BBC.sprite4_target_y = 1;
    D_03004BBC.sprite4_speed = 0x20000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite4_mode = 2;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 0x12;
    D_03004BBC.sprite4_target_y = 1;
    D_03004BBC.sprite4_speed = 0x20000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite4_mode = 2;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 0x10;
    D_03004BBC.sprite4_target_y = 1;
    D_03004BBC.sprite4_speed = 0x20000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite4_mode = 2;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 0x10;
    D_03004BBC.sprite4_target_y = 7;
    D_03004BBC.sprite4_speed = 0x20000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite4_mode = 2;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 4;
    D_03004BBC.sprite4_target_y = 7;
    D_03004BBC.sprite4_speed = 0x20000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite4_mode = 2;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 4;
    D_03004BBC.sprite4_target_y = 1;
    D_03004BBC.sprite4_speed = 0x20000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite4_mode = 2;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 2;
    D_03004BBC.sprite4_target_y = 1;
    D_03004BBC.sprite4_speed = 0x20000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite4_mode = 2;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    for (;;)
    {
        D_03004BBC.sprite4_state = 0xB;
        D_03004BBC.sprite4_target_x = 5;
        D_03004BBC.sprite4_target_y = 1;
        D_03004BBC.sprite4_speed = 0x20000;
        D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
        D_03004BBC.sprite4_mode = 2;
        while (D_03004BBC.sprite4_state != 1)
            func_0805EE78(1);
        func_08000BD8(4, 0);
        func_0805EE78(0x1E);
        D_03004BBC.sprite4_state = 0xB;
        D_03004BBC.sprite4_target_x = 4;
        D_03004BBC.sprite4_target_y = 1;
        D_03004BBC.sprite4_speed = 0x20000;
        D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
        D_03004BBC.sprite4_mode = 2;
        while (D_03004BBC.sprite4_state != 1)
            func_0805EE78(1);
        func_08000BD8(4, 0);
        func_0805EE78(0x1E);
        D_03004BBC.sprite4_state = 0xB;
        D_03004BBC.sprite4_target_x = 3;
        D_03004BBC.sprite4_target_y = 1;
        D_03004BBC.sprite4_speed = 0x20000;
        D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
        D_03004BBC.sprite4_mode = 2;
        while (D_03004BBC.sprite4_state != 1)
            func_0805EE78(1);
        func_08000BD8(4, 0);
        func_0805EE78(0x1E);
        D_03004BBC.sprite4_state = 0xB;
        D_03004BBC.sprite4_target_x = 4;
        D_03004BBC.sprite4_target_y = 1;
        D_03004BBC.sprite4_speed = 0x20000;
        D_03004BBC.sprite4_delay = D_0200000C.delay << 2;
        D_03004BBC.sprite4_mode = 2;
        while (D_03004BBC.sprite4_state != 1)
            func_0805EE78(1);
        func_08000BD8(4, 0);
        func_0805EE78(0x1E);
    }
}
