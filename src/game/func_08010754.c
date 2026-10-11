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
    u8 pad_19A[0x2E];
    u16 sprite3_dir;
    u8 pad_1CA[0x6];
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
    u8 pad_222[0x2E];
    u16 sprite4_dir;
    u8 pad_252[0x6];
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
};

extern struct Obj D_03004BBC;

extern u16 D_02007560[];
extern const u8 D_0832ACB8[];

void func_08008324(s32, s32);
u8 func_08008D28(s32);
void func_08006E08(void);
void func_080079E8(s32, s32, s32, s32, const void *);
void func_080089A0(s32, s32);
void func_0800C680(void);
void func_0800C6A4(void);
void func_0801112C(void);

void func_08010754(void)
{
    u16 i;
    u8 result;
    struct Obj *obj;
    u16 *flag;
    u16 one;

    while (D_03004BBC.sprite1_x != 4 || D_03004BBC.sprite1_y != 1)
        func_0805EE78(1);
    obj = &D_03004BBC;
    flag = &obj->sprite1_state;
    one = 1;
    *flag = 10;
    obj->sprite1_target_x = 4;
    obj->sprite1_target_y = 2;
    obj->sprite1_speed = 0x10000;
    obj->sprite1_delay = D_0200000C.delay << 3;
    obj->sprite1_mode = one;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    func_0805EE78(0x3C);
    func_08008B58(0x53);
    func_0805EE78(0x3C);
    for (i = 0; i < 64; i++)
    {
        func_08008324(0, 0x20000);
        func_0805EE78(1);
    }
    func_080019B4(9);
    func_08008B70(2, 4, 6);
    D_03004BBC.sprite3_state = 10;
    D_03004BBC.sprite3_target_x = 4;
    D_03004BBC.sprite3_target_y = 5;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_state = 10;
    D_03004BBC.sprite3_target_x = 2;
    D_03004BBC.sprite3_target_y = 5;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    func_08008B70(3, 4, 6);
    D_03004BBC.sprite4_state = 10;
    D_03004BBC.sprite4_target_x = 4;
    D_03004BBC.sprite4_target_y = 5;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 10;
    D_03004BBC.sprite4_target_x = 6;
    D_03004BBC.sprite4_target_y = 5;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_state = 10;
    D_03004BBC.sprite3_target_x = 2;
    D_03004BBC.sprite3_target_y = 3;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 10;
    D_03004BBC.sprite4_target_x = 6;
    D_03004BBC.sprite4_target_y = 3;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_state = 10;
    D_03004BBC.sprite3_target_x = 3;
    D_03004BBC.sprite3_target_y = 3;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 10;
    D_03004BBC.sprite4_target_x = 5;
    D_03004BBC.sprite4_target_y = 3;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    func_08008B70(1, 4, 6);
    D_03004BBC.sprite2_state = 10;
    D_03004BBC.sprite2_target_x = 4;
    D_03004BBC.sprite2_target_y = 4;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    for (i = 0; i < 16; i++)
    {
        func_08008324(0, -0x20000);
        func_0805EE78(1);
    }
    func_0805EE78(0x3C);
    func_08008B58(0x54);
    func_0805EE78(0x3C);
    result = func_08008D28(0);
    func_080019B4(4);
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
    func_08000F88(0x12B);
    func_080079E8(0xD, 4, 3, 5, D_0832ACB8);
    func_0805EE78(1);
    func_08008B70(0, 4, 2);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    func_0805EE78(0x3C);
    D_03004BBC.sprite3_mode = 1;
    D_03004BBC.sprite4_mode = 1;
    func_08000BD8(3, 3);
    D_03004BBC.sprite3_flags |= 0x400;
    func_08000BD8(4, 2);
    D_03004BBC.sprite4_flags |= 0x400;
    while (!(D_03004BBC.sprite3_flags & 4))
        func_0805EE78(1);
    D_03004BBC.sprite3_dir = 0;
    func_080089A0(3, 0xFD);
    D_03004BBC.sprite3_flags |= 0x400;
    D_03004BBC.sprite4_dir = 0;
    func_080089A0(4, 0xFD);
    D_03004BBC.sprite4_flags |= 0x400;
    func_080019EC(0x5A);
    while (!(D_03004BBC.sprite3_flags & 4))
        func_0805EE78(1);
    D_03004BBC.sprite3_flags = 0;
    D_03004BBC.sprite4_flags = 0;
    for (i = 0; i < 16; i++)
    {
        func_08008324(0, -0x20000);
        func_0805EE78(1);
    }
    func_0805EE78(0x3C);
    func_08008B58(0x55);
    func_0805EE78(0x3C);
    D_03004BBC.sprite1_state = 11;
    D_03004BBC.sprite1_target_x = 4;
    D_03004BBC.sprite1_target_y = 1;
    D_03004BBC.sprite1_speed = 0x20000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite1_mode = 2;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 11;
    D_03004BBC.sprite1_target_x = 5;
    D_03004BBC.sprite1_target_y = 1;
    D_03004BBC.sprite1_speed = 0x20000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite1_mode = 2;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 11;
    D_03004BBC.sprite1_target_x = 5;
    D_03004BBC.sprite1_target_y = 0;
    D_03004BBC.sprite1_speed = 0x20000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite1_mode = 2;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_flags = 0;
    func_0805EE78(0x3C);
    func_08008B58(0x56);
    func_0805EE78(0x3C);
    D_03004BBC.sprite2_state = 11;
    D_03004BBC.sprite2_target_x = 4;
    D_03004BBC.sprite2_target_y = 5;
    D_03004BBC.sprite2_speed = 0x20000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite2_mode = 2;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_state = 11;
    D_03004BBC.sprite2_target_x = 2;
    D_03004BBC.sprite2_target_y = 5;
    D_03004BBC.sprite2_speed = 0x20000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite2_mode = 2;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_state = 11;
    D_03004BBC.sprite2_target_x = 2;
    D_03004BBC.sprite2_target_y = 1;
    D_03004BBC.sprite2_speed = 0x20000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite2_mode = 2;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_state = 11;
    D_03004BBC.sprite2_target_x = 5;
    D_03004BBC.sprite2_target_y = 1;
    D_03004BBC.sprite2_speed = 0x20000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite2_mode = 2;
    func_08008B70(4, 2, 5);
    D_03004BBC.sprite5_state = 11;
    D_03004BBC.sprite5_target_x = 2;
    D_03004BBC.sprite5_target_y = 1;
    D_03004BBC.sprite5_speed = 0x20000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite5_mode = 2;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_state = 11;
    D_03004BBC.sprite2_target_x = 5;
    D_03004BBC.sprite2_target_y = 0;
    D_03004BBC.sprite2_speed = 0x20000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite2_mode = 2;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_flags = 0;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_state = 11;
    D_03004BBC.sprite2_target_x = 5;
    D_03004BBC.sprite2_target_y = 1;
    D_03004BBC.sprite2_speed = 0x20000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite2_mode = 2;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_state = 11;
    D_03004BBC.sprite2_target_x = 5;
    D_03004BBC.sprite2_target_y = 0;
    D_03004BBC.sprite2_speed = 0x20000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite2_mode = 2;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_flags = 0;
    func_08003D78(4, func_0800C6A4);
    func_0805EE78(0x3C);
    func_08007188(0x11, 4, 6, 0);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_0801112C;
}
