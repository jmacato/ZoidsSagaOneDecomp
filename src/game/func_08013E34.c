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
    u8 pad_108[0x8];
    u16 sprite2_flags;
    u8 pad_112[0x32];
    u32 sprite2_anim;
    u8 pad_148[0x16];
    u16 sprite2_x;
    u16 sprite2_y;
    u8 pad_162[0x1CE];
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
    u8 pad_3B0[0x8];
    u16 sprite7_flags;
    u8 pad_3BA[0x32];
    u32 sprite7_anim;
    u8 pad_3F0[0x16];
    u16 sprite7_x;
    u16 sprite7_y;
};

extern struct Obj D_03004BBC;

extern const u8 D_08667220[];
extern const u8 D_08667284[];
extern const u8 D_08667310[];
void func_08008024(void);
void func_08014204(void);
void func_08014220(void);
void func_0801423C(void);

void func_08013E34(void)
{
    u16 i;
    u32 j;

    func_0805EE78(0x20);
    func_08008B58(0x9E);
    func_080019EC(0x68);
    func_08011F18(1, 0x120, 0x40, 0x20, 4, 1);
    do
        func_0805EE78(1);
    while (!func_08001A28(0x68));
    func_08008B58(0x9F);
    func_08011E08();
    func_080076C0(0x30, 8, 2, 5, D_08667220);
    func_08008B70(0, 0xFF, 0xFF);
    func_08011E24();
    func_08008B58(0xA0);
    func_08000BD8(4, 1);
    func_0805EE78(0x3C);
    func_08011F18(3, 0xA0, 0x40, 0x10, 1, 1);
    func_08000BD8(4, 2);
    func_0805EE78(0x3C);
    func_08011F18(4, 0x80, 0x30, 0x10, 1, 1);
    func_08008B58(0xA1);
    func_08011F18(4, 0x80, 0xA0, 0x10, 1, 1);
    func_08008B58(0xA2);
    func_08011E08();
    func_080076C0(0x31, 4, 2, 7, D_08667284);
    func_08008B70(0, 0xFF, 0xFF);
    func_08011E24();
    func_08008B58(0xA3);
    func_08011E08();
    func_080076C0(0x1E, 0x13, 0x16, 2, D_08667310);
    func_08001A08(4);
    D_02000B54 = 0;
    func_080019B4(4);
    func_08011E24();
    func_08008B58(0xA4);
    func_08011F18(0, 0x260, 0x2C0, 0x20, 1, 1);
    D_03004BBC.sprite1_state = 0xB;
    D_03004BBC.sprite1_target_x = D_03004BBC.sprite2_x;
    D_03004BBC.sprite1_target_y = D_03004BBC.sprite2_y;
    D_03004BBC.sprite1_speed = 0x10000;
    D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
    D_03004BBC.sprite1_mode = 1;
    func_08000BD8(2, 1);
    D_03004BBC.sprite2_flags |= 0x400;
    func_080019EC(0x6F);
    while (!(D_03004BBC.sprite2_flags & 4))
    {
        if (D_03004BBC.sprite2_anim == 0x10010)
        {
            func_08008B70(0, 0xFF, 0xFF);
        }
        if (D_03004BBC.sprite2_anim == 0x10052)
        {
            func_080019EC(0x44);
        }
        func_0805EE78(1);
    }
    func_08000BD8(2, 0);
    D_03004BBC.sprite2_flags &= 0xFBFF;
    func_08011E08();
    func_080076C0(0x31, 4, 2, 7, D_08667284);
    func_08008B70(0, 0xFF, 0xFF);
    func_08011E24();
    func_08008B58(0xA5);
    func_08003D78(4, func_08014204);
    func_08003D78(5, func_08014220);
    func_08011F18(4, 0xA0, 0x60, 0x20, 1, 1);
    func_08000BD8(2, 1);
    func_08008B58(0xA6);
    func_080019EC(0x68);
    func_08011F18(1, 0, 0x40, 0x20, 2, 1);
    func_08008B70(1, 0xFF, 0xFF);
    do
        func_0805EE78(1);
    while (!func_08001A28(0x68));
    func_08001A08(0xA);
    D_02000B54 = 0;
    func_080019B4(0xA);
    func_08000BD8(7, 2);
    D_03004BBC.sprite7_flags |= 0x400;
    func_080019EC(0x6F);
    while (!(D_03004BBC.sprite7_flags & 4))
    {
        if (D_03004BBC.sprite7_anim == 0x10040)
        {
            D_03004BBC.sprite6_flags |= 0x8000;
            func_08008B70(5, D_03004BBC.sprite7_x, D_03004BBC.sprite7_y);
            D_03004BBC.sprite6_state = 0xB;
            D_03004BBC.sprite6_target_x = 4;
            D_03004BBC.sprite6_target_y = 2;
            D_03004BBC.sprite6_speed = 0x10000;
            D_03004BBC.sprite6_delay = D_0200000C.delay << 3;
            D_03004BBC.sprite6_mode = 1;
            func_080019EC(0x49);
        }
        func_0805EE78(1);
    }
    func_08000BD8(7, 0);
    D_03004BBC.sprite7_flags &= 0xFBFF;
    for (j = 0; j < 32; j++)
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
    }
    func_08008B58(0xA7);
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_0801423C;
}
