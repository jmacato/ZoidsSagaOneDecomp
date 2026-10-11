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
    u8 pad_0[0xC0];
    u16 field_C0;
    u8 pad_C2[0x26];
    u16 field_E8;
    u8 pad_EA[8];
    u16 target_x;
    u16 target_y;
    u16 delay;
    u8 pad_F8[0xC];
    u32 speed;
    u8 pad_108[8];
    u16 flags_2;
    u8 pad_112[0x32];
    u32 state_2;
    u8 pad_148[0x16];
    u16 field_15E;
    u16 field_160;
};

extern struct Obj D_03004BBC;

extern const u8 D_086682B0[];

void func_08018E2C(void);
void func_08018E60(void);
void func_08018E94(void);
void func_08018EC0(void);
void func_08018E20(void);
void func_08018D80(void);

void func_08018B74(void)
{
    struct Obj *obj;

    func_08008B58(0x11F);
    func_08011F18(1, 0x580, 0x240, 0x20, 1, 1);
    func_08011F18(1, 0x560, 0x1E0, 0x20, 1, 1);
    func_08008B70(1, 0xFF, 0xFF);
    func_08008B58(0x120);
    func_08003D78(4, func_08018E2C);
    func_0805EE78(0x20);
    func_08003D78(5, func_08018E60);
    func_0805EE78(0x20);
    func_08008B70(4, 0x2E, 0x17);
    func_08011F18(4, 0x5A0, 0x2A0, 0x20, 1, 1);
    func_08000BD8(5, 2);
    func_08008B58(0x121);
    func_08003D78(4, func_08018E94);
    func_08003D78(5, func_08018EC0);
    func_08011F18(4, 0x5A0, 0x240, 0x20, 2, 1);
    func_08008B70(4, 0xFF, 0xFF);
    func_08008B58(0x122);
    func_08011E08();
    func_080076C0(0x5E, 0x28, 3, 2, D_086682B0);
    func_08003D78(4, func_08018E20);
    func_08011F18(0, 0x5C0, 0x60, 0x20, 1, 1);
    obj = &D_03004BBC;
    obj->field_E8 = 0xB;
    obj->target_x = obj->field_15E;
    obj->target_y = obj->field_160;
    obj->speed = 0x10000;
    obj->delay = D_0200000C.delay << 3;
    obj->field_C0 = 1;
    func_08000BD8(2, 1);
    obj->flags_2 |= 0x400;
    func_080019EC(0x6F);
    while (!(D_03004BBC.flags_2 & 4))
    {
        if (obj->state_2 == 0x10010)
            func_08008B70(0, 0xFF, 0xFF);
        if (obj->state_2 == 0x10052)
            func_080019EC(0x44);
        func_0805EE78(1);
    }
    func_08000BD8(2, 0);
    D_03004BBC.flags_2 &= 0xFBFF;
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_08018D80;
}
