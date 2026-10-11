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
    u8 pad_112[0x32];
    u32 sprite2_anim;
    u8 pad_148[0x16];
    u16 sprite2_x;
    u16 sprite2_y;
    u8 pad_162[0x36];
    u16 sprite3_flags;
    u8 pad_19A[0x32];
    u32 sprite3_anim;
    u8 pad_1D0[0x16];
    u16 sprite3_x;
    u16 sprite3_y;
    u8 pad_1EA[0x36];
    u16 sprite4_flags;
    u8 pad_222[0x86];
    u16 sprite5_flags;
};

extern struct Obj D_03004BBC;

extern const u8 D_08667C34[];
extern const u8 D_08667C98[];
extern const u8 D_08667D10[];
extern const u8 D_08667D38[];
extern const u8 D_08667D74[];
void func_08008024(void);
void func_08016128(void);
void func_08016150(void);
void func_08016178(void);
void func_08016880(void);
void func_080169A8(void);
void func_080169E8(void);
void func_08016A20(void);

void func_08016378(void)
{
    u16 i;
    u32 j;

    func_08011E24();
    func_08008B58(0xF2);
    func_08011F18(3, 0x3E0, 0x2A0, 0x20, 2, 1);
    func_08011F18(3, 0x440, 0x2A0, 0x20, 2, 1);
    func_08011F18(3, 0x440, 0x200, 0x20, 2, 1);
    func_08008B70(3, 0xFF, 0xFF);
    func_08008B58(0xF3);
    func_08011E08();
    func_080076C0(0x4D, 0x10, 0x15, 5, D_08667C34);
    func_08001A08(1);
    D_02000B54 = 0;
    func_080019B4(1);
    func_08008B70(0, 0xFF, 0xFF);
    func_08011E24();
    func_08003D78(4, func_080169A8);
    func_08011F18(2, 0x220, 0x2E0, 0x20, 2, 1);
    func_08011F18(2, 0x200, 0x2A0, 0x20, 2, 1);
    func_08008B58(0xF4);
    func_080019EC(0x6F);
    func_08008B70(3, 0x10, 0x15);
    func_08000BD8(4, 0);
    D_03004BBC.sprite4_flags = D_03004BBC.sprite4_flags | 0x400 | 0;
    while (!(D_03004BBC.sprite4_flags & 4))
        func_0805EE78(1);
    func_08008B70(3, 0xFF, 0xFF);
    do
        func_0805EE78(1);
    while (!func_08001A28(0x6F));
    func_080019EC(0x62);
    func_08000BD8(5, 1);
    D_03004BBC.sprite5_flags |= 0x400;
    while (!(D_03004BBC.sprite5_flags & 4))
        func_0805EE78(1);
    func_08000BD8(5, 2);
    do
        func_0805EE78(1);
    while (!func_08001A28(0x62));
    func_08008B58(0xF5);
    func_08003D78(4, func_080169E8);
    func_08003D78(5, func_08016A20);
    func_08011E08();
    func_08003DD8(4);
    func_08003DD8(5);
    func_080076C0(0x42, 8, 5, 6, D_08667C98);
    func_08008B70(0, 6, 5);
    func_08001A08(7);
    D_02000B54 = 0;
    func_080019B4(7);
    func_08011E24();
    func_08008B58(0xF6);
    func_08000BD8(6, 2);
    func_08008B58(0xF7);
    func_08003D78(4, func_08016128);
    func_08003D78(5, func_08016150);
    func_08003D78(6, func_08016178);
    func_08011F18(0, 0x60, 0xC0, 0x10, 2, 0);
    func_08008B70(0, 0xFF, 0xFF);
    func_08000BD8(6, 0);
    func_08008B58(0xF8);
    func_08011E08();
    func_080076C0(0x32, 0xD, 3, 2, D_08667D10);
    func_08011E24();
    func_08011F18(0, 0x1A0, 0x40, 0x20, 1, 0);
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
    func_080076C0(0x52, 8, 2, 3, D_08667D38);
    func_08008B70(0, 0xFFFF, 0xFFFF);
    func_08011E24();
    func_08008B58(0xF9);
    func_08011F18(2, 0x80, 0xC0, 0x10, 1, 1);
    func_08008B70(2, 0xFF, 0xFF);
    func_08008B58(0xFA);
    func_08011E08();
    func_080076C0(0x56, 4, 1, 3, D_08667D74);
    func_08008B70(0, 0xFF, 0xFF);
    func_08011E24();
    func_08000BD8(3, 2);
    D_03004BBC.sprite3_flags |= 0x400;
    func_080019EC(0x6F);
    while (!(D_03004BBC.sprite3_flags & 4))
    {
        if (D_03004BBC.sprite3_anim == 0x10040)
        {
            D_03004BBC.sprite1_flags |= 0x8000;
            func_08008B70(0, D_03004BBC.sprite3_x, D_03004BBC.sprite3_y);
            D_03004BBC.sprite1_state = 0xB;
            D_03004BBC.sprite1_target_x = 4;
            D_03004BBC.sprite1_target_y = 2;
            D_03004BBC.sprite1_speed = 0x10000;
            D_03004BBC.sprite1_delay = D_0200000C.delay << 3;
            D_03004BBC.sprite1_mode = 1;
            func_080019EC(0x49);
        }
        func_0805EE78(1);
    }
    func_08000BD8(3, 0);
    D_03004BBC.sprite3_flags &= 0xFBFF;
    func_08011F18(1, 0x80, 0x60, 0x20, 1, 1);
    for (j = 0; j < 32; j++)
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
    }
    func_08008B58(0xFB);
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_08016880;
}
