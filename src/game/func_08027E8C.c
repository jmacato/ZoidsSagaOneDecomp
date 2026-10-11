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
    u8 pad_0[0xB8];
    u16 sprite1_dir;
    u8 pad_BA[0x2];
    u16 sprite1_anim;
    u8 pad_BE[2];
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
    u8 pad_14A[0x14];
    u16 sprite2_x;
    u16 sprite2_y;
    u8 pad_162[0xE];
    u16 sprite2_state;
    u8 pad_172[0x8];
    u16 sprite2_target_x;
    u16 sprite2_target_y;
    u16 sprite2_delay;
    u8 pad_180[0xC];
    u32 sprite2_speed;
    u8 pad_190[0x10];
    u32 sprite3_field_8;
    u32 sprite3_pos_x;
    u8 pad_1A8[0x28];
    u16 sprite3_mode;
    u8 pad_1D2[0x26];
    u16 sprite3_state;
    u8 pad_1FA[0x8];
    u16 sprite3_target_x;
    u16 sprite3_target_y;
    u16 sprite3_delay;
    u8 pad_208[0xC];
    u32 sprite3_speed;
    u8 pad_218[0x10];
    u32 sprite4_field_8;
    u8 pad_22C[0x2C];
    u16 sprite4_mode;
    u8 pad_25A[0x26];
    u16 sprite4_state;
    u8 pad_282[0x8];
    u16 sprite4_target_x;
    u16 sprite4_target_y;
    u16 sprite4_delay;
    u8 pad_290[0xC];
    u32 sprite4_speed;
    u8 pad_2A0[0x10];
    u32 sprite5_field_8;
    u8 pad_2B4[0x2C];
    u16 sprite5_mode;
    u8 pad_2E2[0x26];
    u16 sprite5_state;
    u8 pad_30A[0x8];
    u16 sprite5_target_x;
    u16 sprite5_target_y;
    u16 sprite5_delay;
    u8 pad_318[0xC];
    u32 sprite5_speed;
    u8 pad_328[0x10];
    u32 sprite6_field_8;
    u8 pad_33C[0x2C];
    u16 sprite6_mode;
    u8 pad_36A[0x26];
    u16 sprite6_state;
    u8 pad_392[0x8];
    u16 sprite6_target_x;
    u16 sprite6_target_y;
    u16 sprite6_delay;
    u8 pad_3A0[0xC];
    u32 sprite6_speed;
    u8 pad_3B0[0x120];
    u32 sprite9_field_8;
    u8 pad_4D4[0x2C];
    u16 sprite9_mode;
    u8 pad_502[0x26];
    u16 sprite9_state;
    u8 pad_52A[0x8];
    u16 sprite9_target_x;
    u16 sprite9_target_y;
    u16 sprite9_delay;
    u8 pad_538[0xC];
    u32 sprite9_speed;
    u8 pad_548[0x10];
    u32 sprite10_field_8;
    u8 pad_55C[0x2C];
    u16 sprite10_mode;
    u8 pad_58A[0x26];
    u16 sprite10_state;
    u8 pad_5B2[0x8];
    u16 sprite10_target_x;
    u16 sprite10_target_y;
    u16 sprite10_delay;
    u8 pad_5C0[0xC];
    u32 sprite10_speed;
    u8 pad_5D0[0x10];
    u32 sprite11_field_8;
    u8 pad_5E4[0x2C];
    u16 sprite11_mode;
    u8 pad_612[0x26];
    u16 sprite11_state;
    u8 pad_63A[0x8];
    u16 sprite11_target_x;
    u16 sprite11_target_y;
    u16 sprite11_delay;
    u8 pad_648[0xC];
    u32 sprite11_speed;
    u8 pad_658[0x10];
    u32 sprite12_field_8;
    u8 pad_66C[0x2C];
    u16 sprite12_mode;
    u8 pad_69A[0x26];
    u16 sprite12_state;
    u8 pad_6C2[0x8];
    u16 sprite12_target_x;
    u16 sprite12_target_y;
    u16 sprite12_delay;
    u8 pad_6D0[0xC];
    u32 sprite12_speed;
    u8 pad_6E0[0x8];
    u16 sprite13_flags;
    u8 pad_6EA[0x2E];
    u16 sprite13_dir;
    u8 pad_71A[0x2];
    union
    {
        u32 all;
        struct
        {
            u16 frame;
            u16 id;
        } half;
    } sprite13_anim;
    u8 pad_720[0x50];
    u16 sprite14_flags;
    u8 pad_772[0xA];
    u32 sprite14_pos_x;
};

extern struct Obj D_03004BBC;

extern struct
{
    u8 pad_0[0xCD0];
    u8 zoid;
    s8 pilot;
} D_02000B5C;

void func_08001988(void);
void func_0800196C(void);
void func_08000DB8(void);
void func_0800C430(void);
void func_08026634(u8);
void func_08009A20(void);
void func_08029F40(void);

extern const u8 D_0832B22C[];
extern const u8 D_0832B290[];
void func_0800BEC8(void);
void func_0800C680(void);
void func_0800C6A4(void);
void func_0800C6C8(void);
void func_0800C6E8(void);

void func_08027E8C(void)
{
    u8 i;
    u8 j;

    func_080019EC(0x6B);
    func_0805EE78(0x3C);
    for (i = 0; i < 4; i++)
    {
        D_03004BBC.sprite14_flags &= 0xFBFF;
        func_08000BD8(0xE, 0);
        D_03004BBC.sprite14_flags |= 0x400;
        func_08008B70(0xD, D_03004BBC.sprite2_x, D_03004BBC.sprite2_y);
        D_03004BBC.sprite14_pos_x++;
        func_080019EC(0x5B);
        while (!(D_03004BBC.sprite14_flags & 4))
            func_0805EE78(1);
        func_08008B70(0xD, 0xFF, 0xFF);
        func_0805EE78(0x28);
    }
    func_0805EE78(0x3C);
    func_08008B58(0x2A7);
    func_0805EE78(0x1E);
    for (i = 0; i < 4; i++)
    {
        D_03004BBC.sprite14_flags &= 0xFBFF;
        func_08000BD8(0xE, 0);
        D_03004BBC.sprite14_flags |= 0x400;
        func_08008B70(0xD, D_03004BBC.sprite2_x, D_03004BBC.sprite2_y);
        D_03004BBC.sprite14_pos_x++;
        func_080019EC(0x5B);
        while (!(D_03004BBC.sprite14_flags & 4))
            func_0805EE78(1);
        func_08008B70(0xD, 0xFF, 0xFF);
        func_0805EE78(0x28);
    }
    for (i = 0; i < 32; i++)
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
    }
    func_0805EE78(0x3C);
    func_080019B4(6);
    func_0805EE78(0x3C);
    func_08008B58(0x2A8);
    func_0805EE78(0x1E);
    func_08008B70(0xB, 5, 9);
    D_03004BBC.sprite12_state = 0xB;
    D_03004BBC.sprite12_target_x = 5;
    D_03004BBC.sprite12_target_y = 5;
    D_03004BBC.sprite12_speed = 0x10000;
    D_03004BBC.sprite12_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite12_mode = 1;
    while (D_03004BBC.sprite12_state != 1)
        func_0805EE78(1);
    func_08000BD8(0xC, 3);
    func_08000BD8(3, 2);
    func_08000BD8(4, 2);
    func_08000BD8(5, 2);
    func_08000BD8(6, 2);
    func_080019B4(0x14);
    func_0805EE78(0x3C);
    func_08008B58(0x2A9);
    func_0805EE78(0x1E);
    func_08008B70(8, 7, 9);
    func_08008B70(9, 6, 9);
    func_08008B70(0xA, 7, 0xA);
    D_03004BBC.sprite9_state = 0xB;
    D_03004BBC.sprite9_target_x = 7;
    D_03004BBC.sprite9_target_y = 4;
    D_03004BBC.sprite9_speed = 0x10000;
    D_03004BBC.sprite9_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite9_mode = 1;
    D_03004BBC.sprite10_state = 0xB;
    D_03004BBC.sprite10_target_x = 6;
    D_03004BBC.sprite10_target_y = 4;
    D_03004BBC.sprite10_speed = 0x10000;
    D_03004BBC.sprite10_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite10_mode = 1;
    D_03004BBC.sprite11_state = 0xB;
    D_03004BBC.sprite11_target_x = 7;
    D_03004BBC.sprite11_target_y = 5;
    D_03004BBC.sprite11_speed = 0x10000;
    D_03004BBC.sprite11_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite11_mode = 1;
    func_0805EE78(0x3C);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 0xA;
    D_03004BBC.sprite4_target_y = 6;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 0xA;
    D_03004BBC.sprite5_target_y = 5;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    D_03004BBC.sprite6_state = 0xB;
    D_03004BBC.sprite6_target_x = 9;
    D_03004BBC.sprite6_target_y = 5;
    D_03004BBC.sprite6_speed = 0x10000;
    D_03004BBC.sprite6_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite6_mode = 1;
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 9;
    D_03004BBC.sprite3_target_y = 4;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 0xA;
    D_03004BBC.sprite5_target_y = 4;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 0xA;
    D_03004BBC.sprite4_target_y = 5;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    func_08000BD8(3, 2);
    func_08000BD8(4, 2);
    func_08000BD8(5, 2);
    func_08000BD8(6, 2);
    while (D_03004BBC.sprite11_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite12_state = 0xB;
    D_03004BBC.sprite12_target_x = 6;
    D_03004BBC.sprite12_target_y = 5;
    D_03004BBC.sprite12_speed = 0x10000;
    D_03004BBC.sprite12_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite12_mode = 1;
    while (D_03004BBC.sprite12_state != 1)
        func_0805EE78(1);
    func_08000BD8(9, 3);
    func_08000BD8(0xA, 3);
    func_08000BD8(0xB, 3);
    func_08000BD8(0xC, 3);
    func_0805EE78(0x3C);
    func_08008B58(0x2AA);
    func_0805EE78(0x1E);
    for (i = 0; i < 8; i++)
    {
        D_03004BBC.sprite3_field_8 -= 0x10000;
        D_03004BBC.sprite9_field_8 += 0x10000;
        func_0805EE78(1);
    }
    func_0805EE78(0x1E);
    func_08008B58(0x2AB);
    func_0805EE78(0x1E);
    for (i = 0; i < 8; i++)
    {
        D_03004BBC.sprite5_field_8 -= 0x10000;
        D_03004BBC.sprite10_field_8 += 0x10000;
        func_0805EE78(1);
    }
    func_0805EE78(0x1E);
    func_08008B58(0x2AC);
    func_0805EE78(0x1E);
    for (i = 0; i < 8; i++)
    {
        D_03004BBC.sprite6_field_8 -= 0x10000;
        D_03004BBC.sprite11_field_8 += 0x10000;
        func_0805EE78(1);
    }
    func_0805EE78(0x1E);
    func_08008B58(0x2AD);
    func_0805EE78(0x1E);
    for (i = 0; i < 8; i++)
    {
        D_03004BBC.sprite4_field_8 -= 0x10000;
        D_03004BBC.sprite12_field_8 += 0x10000;
        func_0805EE78(1);
    }
    func_0805EE78(0x1E);
    func_08008B58(0x2AE);
    func_0805EE78(0x1E);
    for (i = 0; i < 8; i++)
    {
        D_03004BBC.sprite3_field_8 += 0x10000;
        D_03004BBC.sprite9_field_8 -= 0x10000;
        D_03004BBC.sprite5_field_8 += 0x10000;
        D_03004BBC.sprite10_field_8 -= 0x10000;
        D_03004BBC.sprite6_field_8 += 0x10000;
        D_03004BBC.sprite11_field_8 -= 0x10000;
        D_03004BBC.sprite4_field_8 += 0x10000;
        D_03004BBC.sprite12_field_8 -= 0x10000;
        func_0805EE78(1);
    }
    func_0805EE78(0x1E);
    func_08008B58(0x2AF);
    func_0805EE78(0x1E);
    if (func_08008D28(0x28) == 1)
    {
        func_08006E08();
        func_08007188(D_02007560[0], D_02007560[1], D_02007560[2], 0);
        func_080014A8(0, func_0800BEC8);
        return;
    }
    func_08000F88(0x136);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    for (j = 0; j < 128; j++)
    {
        func_08008324(0, -0x10000);
        func_0805EE78(1);
    }
    func_0805EE78(0x3C);
    func_080019B4(5);
    func_08000BD8(3, 0);
    func_08000BD8(4, 0);
    func_08000BD8(5, 0);
    func_08000BD8(6, 0);
    func_08000BD8(9, 0);
    func_08000BD8(0xA, 0);
    func_08000BD8(0xB, 0);
    func_08000BD8(0xC, 0);
    func_08000BD8(0xD, 1);
    func_080019EC(0x6F);
    D_03004BBC.sprite13_anim.half.frame = 0x20;
    D_03004BBC.sprite13_anim.half.id = 1;
    for (j = 0; j <= 3;)
    {
        if (D_03004BBC.sprite13_anim.all == 0x10052)
        {
            func_080019EC(0x6F);
            D_03004BBC.sprite13_anim.half.frame = 0x20;
            D_03004BBC.sprite13_anim.half.id = 1;
            j++;
        }
        func_0805EE78(1);
    }
    for (;;)
    {
        if (D_03004BBC.sprite13_anim.all == 0x10054)
            func_080019EC(0x4C);
        if (D_03004BBC.sprite13_anim.all == 0x10060)
            break;
        func_0805EE78(1);
    }
    func_08008B70(0xC, 0xFF, 0xFF);
    func_0805EE78(0x3C);
    func_08008B58(0x2B0);
    func_0805EE78(0x1E);
    func_080019EC(0x85);
    for (i = 0; i < 5; i++)
    {
        func_08003D78(4, func_0800C6E8);
        func_0805EE78(0xA);
        func_08003D78(4, func_0800C6C8);
        func_0805EE78(0xA);
    }
    func_0805EE78(0x3C);
    func_080019EC(0x6F);
    D_03004BBC.sprite13_dir = 0;
    func_080089A0(0xD, 0x102);
    D_03004BBC.sprite13_flags |= 0x400;
    func_08008B70(0xC, 8, 1);
    while (!(D_03004BBC.sprite13_flags & 4))
        func_0805EE78(1);
    D_03004BBC.sprite13_flags &= 0xFBFF;
    func_08000BD8(0xD, 1);
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 8;
    D_03004BBC.sprite2_target_y = 2;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    func_0805EE78(0x3C);
    func_08008B58(0x2B1);
    func_0805EE78(0x1E);
    func_0805EE78(0x3C);
    func_08008B58(0x2B2);
    func_0805EE78(0x1E);
    func_080019EC(0x6D);
    D_03004BBC.sprite2_state = 0xA;
    D_03004BBC.sprite2_target_x = 8;
    D_03004BBC.sprite2_target_y = 1;
    D_03004BBC.sprite2_speed = 0x40000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 1;
    D_03004BBC.sprite2_mode = 3;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    func_08008B70(1, 0xFF, 0xFF);
    func_080019EC(0x6B);
    func_0805EE78(0x3C);
    func_0805EE78(0x3C);
    func_08008B58(0x2B3);
    func_0805EE78(0x1E);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 9;
    D_03004BBC.sprite3_target_y = 3;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 8;
    D_03004BBC.sprite3_target_y = 3;
    D_03004BBC.sprite3_speed = 0x8000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 4;
    D_03004BBC.sprite3_mode = 0;
    D_03004BBC.sprite9_state = 0xB;
    D_03004BBC.sprite9_target_x = 7;
    D_03004BBC.sprite9_target_y = 3;
    D_03004BBC.sprite9_speed = 0x20000;
    D_03004BBC.sprite9_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite9_mode = 2;
    while (D_03004BBC.sprite9_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite9_state = 0xB;
    D_03004BBC.sprite9_target_x = 8;
    D_03004BBC.sprite9_target_y = 3;
    D_03004BBC.sprite9_speed = 0x20000;
    D_03004BBC.sprite9_delay = D_0200000C.delay << 2;
    D_03004BBC.sprite9_mode = 2;
    while (D_03004BBC.sprite9_state != 1)
        func_0805EE78(1);
    func_080019EC(0x5A);
    func_08000BD8(3, 8);
    for (i = 0; i < 32; i++)
    {
        D_03004BBC.sprite3_field_8 += 0x20000;
        func_0805EE78(1);
    }
    func_08008B70(2, D_03004BBC.sprite3_field_8 >> 21, D_03004BBC.sprite3_pos_x >> 21);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 9;
    D_03004BBC.sprite3_target_y = 3;
    D_03004BBC.sprite3_speed = 0x8000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 4;
    D_03004BBC.sprite3_mode = 0;
    D_03004BBC.sprite9_state = 0xB;
    D_03004BBC.sprite9_target_x = 8;
    D_03004BBC.sprite9_target_y = 2;
    D_03004BBC.sprite9_speed = 0x10000;
    D_03004BBC.sprite9_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite9_mode = 1;
    while (D_03004BBC.sprite9_state != 1)
        func_0805EE78(1);
    func_08000BD8(9, 1);
    func_080019B4(0xF);
    func_0805EE78(0x3C);
    func_08008B58(0x2B4);
    func_0805EE78(0x1E);
    D_03004BBC.sprite10_state = 0xB;
    D_03004BBC.sprite10_target_x = 8;
    D_03004BBC.sprite10_target_y = 3;
    D_03004BBC.sprite10_speed = 0x10000;
    D_03004BBC.sprite10_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite10_mode = 1;
    while (D_03004BBC.sprite10_state != 1)
        func_0805EE78(1);
    func_08000BD8(9, 0);
    func_0805EE78(0x3C);
    func_08008B58(0x2B5);
    func_0805EE78(0x1E);
    func_080019EC(0x6D);
    D_03004BBC.sprite9_state = 0xA;
    D_03004BBC.sprite9_target_x = 8;
    D_03004BBC.sprite9_target_y = 1;
    D_03004BBC.sprite9_speed = 0x40000;
    D_03004BBC.sprite9_delay = D_0200000C.delay << 1;
    D_03004BBC.sprite9_mode = 3;
    while (D_03004BBC.sprite9_state != 1)
        func_0805EE78(1);
    func_08008B70(8, 0xFF, 0xFF);
    D_03004BBC.sprite10_state = 0xA;
    D_03004BBC.sprite10_target_x = 8;
    D_03004BBC.sprite10_target_y = 2;
    D_03004BBC.sprite10_speed = 0x10000;
    D_03004BBC.sprite10_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite10_mode = 1;
    while (D_03004BBC.sprite10_state != 1)
        func_0805EE78(1);
    func_080019EC(0x6D);
    D_03004BBC.sprite10_state = 0xA;
    D_03004BBC.sprite10_target_x = 8;
    D_03004BBC.sprite10_target_y = 1;
    D_03004BBC.sprite10_speed = 0x40000;
    D_03004BBC.sprite10_delay = D_0200000C.delay << 1;
    D_03004BBC.sprite10_mode = 3;
    while (D_03004BBC.sprite10_state != 1)
        func_0805EE78(1);
    func_08008B70(9, 0xFF, 0xFF);
    for (i = 0; i < 32; i++)
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
    }
    func_0805EE78(0x3C);
    func_08008B58(0x2B6);
    func_0805EE78(0x1E);
    D_03004BBC.sprite11_state = 0xB;
    D_03004BBC.sprite11_target_x = 8;
    D_03004BBC.sprite11_target_y = 3;
    D_03004BBC.sprite11_speed = 0x10000;
    D_03004BBC.sprite11_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite11_mode = 1;
    while (D_03004BBC.sprite11_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite11_state = 0xB;
    D_03004BBC.sprite11_target_x = 8;
    D_03004BBC.sprite11_target_y = 2;
    D_03004BBC.sprite11_speed = 0x10000;
    D_03004BBC.sprite11_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite11_mode = 1;
    for (i = 0; i < 32; i++)
    {
        func_08008324(0, -0x10000);
        func_0805EE78(1);
    }
    while (D_03004BBC.sprite11_state != 1)
        func_0805EE78(1);
    func_080019EC(0x6D);
    D_03004BBC.sprite11_state = 0xA;
    D_03004BBC.sprite11_target_x = 8;
    D_03004BBC.sprite11_target_y = 1;
    D_03004BBC.sprite11_speed = 0x40000;
    D_03004BBC.sprite11_delay = D_0200000C.delay << 1;
    D_03004BBC.sprite11_mode = 3;
    while (D_03004BBC.sprite11_state != 1)
        func_0805EE78(1);
    func_08008B70(0xA, 0xFF, 0xFF);
    for (i = 0; i < 32; i++)
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
    }
    func_0805EE78(0x3C);
    func_08008B58(0x2B7);
    func_0805EE78(0x1E);
    D_03004BBC.sprite12_state = 0xB;
    D_03004BBC.sprite12_target_x = 8;
    D_03004BBC.sprite12_target_y = 3;
    D_03004BBC.sprite12_speed = 0x10000;
    D_03004BBC.sprite12_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite12_mode = 1;
    while (D_03004BBC.sprite12_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite12_state = 0xB;
    D_03004BBC.sprite12_target_x = 8;
    D_03004BBC.sprite12_target_y = 2;
    D_03004BBC.sprite12_speed = 0x10000;
    D_03004BBC.sprite12_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite12_mode = 1;
    for (i = 0; i < 32; i++)
    {
        func_08008324(0, -0x10000);
        func_0805EE78(1);
    }
    while (D_03004BBC.sprite12_state != 1)
        func_0805EE78(1);
    func_080019EC(0x6D);
    D_03004BBC.sprite12_state = 0xA;
    D_03004BBC.sprite12_target_x = 8;
    D_03004BBC.sprite12_target_y = 1;
    D_03004BBC.sprite12_speed = 0x40000;
    D_03004BBC.sprite12_delay = D_0200000C.delay << 1;
    D_03004BBC.sprite12_mode = 3;
    while (D_03004BBC.sprite12_state != 1)
        func_0805EE78(1);
    func_08008B70(0xB, 0xFF, 0xFF);
    func_0805EE78(0x3C);
    func_080019EC(0x6F);
    func_08000BD8(0xD, 2);
    D_03004BBC.sprite13_flags |= 0x400;
    while (!(D_03004BBC.sprite13_flags & 4))
        func_0805EE78(1);
    func_0805EE78(0x3C);
    D_03004BBC.sprite13_dir = 1;
    func_080089A0(0xD, 0xF7);
    D_03004BBC.sprite13_anim.half.frame = 0x5E;
    D_03004BBC.sprite13_anim.half.id = 1;
    func_080019EC(0x7F);
    D_03004BBC.sprite13_flags |= 0x400;
    while (!(D_03004BBC.sprite13_flags & 4))
        func_0805EE78(1);
    D_03004BBC.sprite13_flags &= 0xFBFF;
    func_08000BD8(0xD, 0);
    func_0805EE78(0x3C);
    func_08008B58(0x2B8);
    func_0805EE78(0x1E);
    func_0805EE78(0x3C);
    D_03004BBC.sprite3_state = 0xB;
    D_03004BBC.sprite3_target_x = 9;
    D_03004BBC.sprite3_target_y = 0x10;
    D_03004BBC.sprite3_speed = 0x8000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 4;
    D_03004BBC.sprite3_mode = 0;
    D_03004BBC.sprite4_state = 0xB;
    D_03004BBC.sprite4_target_x = 0xA;
    D_03004BBC.sprite4_target_y = 0x10;
    D_03004BBC.sprite4_speed = 0x8000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 4;
    D_03004BBC.sprite4_mode = 0;
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 0xA;
    D_03004BBC.sprite5_target_y = 0x10;
    D_03004BBC.sprite5_speed = 0x8000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 4;
    D_03004BBC.sprite5_mode = 0;
    D_03004BBC.sprite6_state = 0xB;
    D_03004BBC.sprite6_target_x = 9;
    D_03004BBC.sprite6_target_y = 0x10;
    D_03004BBC.sprite6_speed = 0x8000;
    D_03004BBC.sprite6_delay = D_0200000C.delay << 4;
    D_03004BBC.sprite6_mode = 0;
    for (i = 0; i < 96; i++)
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
    }
    func_08003D78(4, func_0800C6A4);
    func_0805EE78(0x3C);
    func_080076C0(0x114, 6, 2, 5, D_0832B22C);
    func_080019B4(3);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 7;
    D_03004BBC.sprite5_target_y = 2;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    func_08000BD8(5, 2);
    func_0805EE78(0x1E);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 7;
    D_03004BBC.sprite5_target_y = 3;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 6;
    D_03004BBC.sprite5_target_y = 3;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    func_08000BD8(5, 0);
    func_0805EE78(0x1E);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 5;
    D_03004BBC.sprite5_target_y = 3;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 5;
    D_03004BBC.sprite5_target_y = 2;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    func_08000BD8(5, 3);
    func_0805EE78(0x3C);
    func_08008B58(0x2B9);
    func_0805EE78(0x1E);
    func_08008B70(1, 2, 0xC);
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 2;
    D_03004BBC.sprite2_target_y = 7;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 4;
    D_03004BBC.sprite2_target_y = 4;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    func_08000BD8(2, 0);
    func_0805EE78(0x3C);
    func_08008B58(0x2BA);
    func_0805EE78(0x1E);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 5;
    D_03004BBC.sprite5_target_y = 5;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 2;
    D_03004BBC.sprite5_target_y = 5;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite5_state = 0xB;
    D_03004BBC.sprite5_target_x = 2;
    D_03004BBC.sprite5_target_y = 0xC;
    D_03004BBC.sprite5_speed = 0x10000;
    D_03004BBC.sprite5_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite5_mode = 1;
    while (D_03004BBC.sprite5_state != 1)
        func_0805EE78(1);
    func_08008B70(4, 0xFF, 0xFF);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 8;
    D_03004BBC.sprite1_target_y = 2;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 4;
    D_03004BBC.sprite2_target_y = 2;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    func_08000BD8(2, 3);
    func_0805EE78(0x3C);
    func_08008B58(0x2BB);
    func_0805EE78(0x1E);
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 5;
    D_03004BBC.sprite2_target_y = 2;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    func_0805EE78(0x3C);
    func_08008B58(0x2BC);
    func_0805EE78(0x1E);
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 6;
    D_03004BBC.sprite2_target_y = 2;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    func_08000BD8(1, 2);
    func_0805EE78(0x3C);
    func_08008B58(0x2BD);
    func_0805EE78(0x1E);
    func_08008B70(2, 6, 0xB);
    func_08008B70(3, 7, 0xC);
    func_08000BD8(3, 2);
    func_08000BD8(4, 2);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 8;
    D_03004BBC.sprite1_target_y = 3;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 5;
    D_03004BBC.sprite1_target_y = 3;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    do
        func_0805EE78(1);
    while (D_03004BBC.sprite1_state != 1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 2;
    D_03004BBC.sprite1_target_y = 3;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 2;
    D_03004BBC.sprite2_target_y = 2;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    do
        func_0805EE78(1);
    while (D_03004BBC.sprite1_state != 1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 2;
    D_03004BBC.sprite1_target_y = 0xC;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 2;
    D_03004BBC.sprite2_target_y = 0xB;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 5;
    D_03004BBC.sprite1_target_y = 0xC;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    D_03004BBC.sprite2_state = 0xB;
    D_03004BBC.sprite2_target_x = 4;
    D_03004BBC.sprite2_target_y = 0xB;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    func_0805EE78(0x3C);
    func_08008B58(0x2BE);
    func_0805EE78(0x1E);
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 6;
    D_03004BBC.sprite1_target_y = 0xC;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    D_03004BBC.sprite4_state = 0xA;
    D_03004BBC.sprite4_target_x = 7;
    D_03004BBC.sprite4_target_y = 0xB;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    D_03004BBC.sprite2_state = 0xA;
    D_03004BBC.sprite2_target_x = 0x13;
    D_03004BBC.sprite2_target_y = 0xB;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 0x13;
    D_03004BBC.sprite1_target_y = 0xC;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    D_03004BBC.sprite3_state = 0xA;
    D_03004BBC.sprite3_target_x = 6;
    D_03004BBC.sprite3_target_y = 0xC;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    do
        func_0805EE78(1);
    while (D_03004BBC.sprite3_state != 1);
    D_03004BBC.sprite4_state = 0xA;
    D_03004BBC.sprite4_target_x = 0x13;
    D_03004BBC.sprite4_target_y = 0xB;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    D_03004BBC.sprite3_state = 0xA;
    D_03004BBC.sprite3_target_x = 0x13;
    D_03004BBC.sprite3_target_y = 0xC;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    func_0805EE78(0x96);
    func_08003D78(4, func_0800C6A4);
    func_0805EE78(0x3C);
    func_080076C0(0x115, 8, 9, 4, D_0832B290);
    D_03004BBC.sprite1_state = 0xA;
    D_03004BBC.sprite1_target_x = 8;
    D_03004BBC.sprite1_target_y = 4;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    D_03004BBC.sprite2_state = 0xA;
    D_03004BBC.sprite2_target_x = 7;
    D_03004BBC.sprite2_target_y = 4;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    D_03004BBC.sprite3_state = 0xA;
    D_03004BBC.sprite3_target_x = 8;
    D_03004BBC.sprite3_target_y = 4;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    D_03004BBC.sprite4_state = 0xA;
    D_03004BBC.sprite4_target_x = 9;
    D_03004BBC.sprite4_target_y = 4;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = 8;
    D_03004BBC.sprite1_target_y = 1;
    D_03004BBC.sprite1_speed = 0x8000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 4;
    D_03004BBC.sprite1_mode = 0;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite2_state = 0xA;
    D_03004BBC.sprite2_target_x = 5;
    D_03004BBC.sprite2_target_y = 4;
    D_03004BBC.sprite2_speed = 0x10000;
    D_03004BBC.sprite2_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite2_mode = 1;
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite4_state = 0xA;
    D_03004BBC.sprite4_target_x = 0xC;
    D_03004BBC.sprite4_target_y = 4;
    D_03004BBC.sprite4_speed = 0x10000;
    D_03004BBC.sprite4_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite4_mode = 1;
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    D_03004BBC.sprite3_state = 0xA;
    D_03004BBC.sprite3_target_x = 0xB;
    D_03004BBC.sprite3_target_y = 4;
    D_03004BBC.sprite3_speed = 0x10000;
    D_03004BBC.sprite3_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite3_mode = 1;
    while (D_03004BBC.sprite2_state != 1)
        func_0805EE78(1);
    func_08000BD8(2, 1);
    while (D_03004BBC.sprite4_state != 1)
        func_0805EE78(1);
    func_08000BD8(4, 1);
    while (D_03004BBC.sprite3_state != 1)
        func_0805EE78(1);
    func_08000BD8(3, 1);
    while (D_03004BBC.sprite1_state != 1)
        func_0805EE78(1);
    func_08000BD8(1, 1);
    func_0805EE78(0x78);
    D_03004BBC.sprite1_dir = 0;
    D_03004BBC.sprite1_anim = 0;
    func_080089A0(1, 0x104);
    func_0805EE78(0xF0);
    func_08003D78(4, func_0800C6A4);
    func_0805EE78(0x3C);
    func_08001988();
    D_02000000.counter |= 8;
    func_0800196C();
    func_0805EE78(1);
    *(vu16 *)0x04000000 = 0x40;
    func_08000D1C(1);
    func_0805EE78(1);
    func_08000DB8();
    func_0805EE78(1);
    func_0805EE78(0x3C);
    func_0800C430();
    func_0805EE78(0x3C);
    D_02000000.counter &= 0xFFF7;
    func_08026634(D_02000B5C.zoid);
    func_08026634(D_02000B5C.pilot);
    D_02000B5C.zoid = 0xFF;
    D_02000B5C.pilot = -1;
    func_08009A20();
    func_08007188(0x154, 6, 1, 0);
    func_08003D78(4, func_0800C680);
    func_0805EE78(0x3C);
    func_08029F40();
}
