#include "types.h"

extern struct
{
    void *first;
} D_02000000;

extern struct
{
    u8 pad_0[0x18];
    u16 delay;
} D_0200000C;

struct Obj
{
    u8 pad_0[0x88];
    u16 flags_88;
    u8 pad_8A[0x6];
    u32 x;
    u32 y;
    u8 pad_98[0x28];
    u16 field_C0;
    u8 pad_C2[0x26];
    u16 field_E8;
    u8 pad_EA[0x8];
    u16 target_x;
    u16 target_y;
    u16 delay;
    u8 pad_F8[0xC];
    u32 speed;
    u8 pad_108[0x8];
    u16 flags;
    u8 pad_112[0x32];
    u32 state;
    u8 pad_148[0x16];
    u16 field_4E;
    u16 field_50;
};

extern struct Obj D_03004BBC;
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
void func_080076C0(s32, s32, s32, s32, u8 *);
void func_0800BEA4(void);
void func_080014A8(s32, void *);
void func_08001A08(s32);
void func_080019B4(s32);
void func_08011F18(s32, s32, s32, s32, s32, s32);
extern u8 D_08668094[];
s32 func_08001A28(s32);
void func_08017918(void);

void func_08017648(void)
{
    struct Obj *obj;
    u16 *flags;

    func_0805EE78(0x20);
    func_08000BD8(2, 2);
    obj = &D_03004BBC;
    flags = &obj->flags;
    obj->flags |= 0x400;
    func_080019EC(0x6F);
    while (!(D_03004BBC.flags & 4))
    {
        if (obj->state == 0x10040)
        {
            obj->flags_88 |= 0x8000;
            func_08008B70(0, obj->field_4E, obj->field_50);
            obj->field_E8 = 0xB;
            obj->target_x = 0x2E;
            obj->target_y = 3;
            obj->speed = 0x10000;
            obj->delay = D_0200000C.delay << 3;
            obj->field_C0 = 1;
            func_080019EC(0x49);
        }
        func_0805EE78(1);
    }
    func_08000BD8(2, 0);
    D_03004BBC.flags &= 0xFBFF;
    func_0805EE78(0x1E);
    func_08011F18(0, 0x560, 0x40, 0x20, 1, 1);
    func_08008B58(0x102);
    func_080019EC(0x5B);
    do
        func_0805EE78(1);
    while (!func_08001A28(0x5B));
    func_0805EE78(0x1E);
    func_080019EC(0x5B);
    do
        func_0805EE78(1);
    while (!func_08001A28(0x5B));
    func_0805EE78(0xF);
    func_080019EC(0x5B);
    do
        func_0805EE78(1);
    while (!func_08001A28(0x5B));
    func_0805EE78(6);
    func_08008B58(0x103);
    func_08011F18(0, 0x500, 0x40, 0x20, 1, 1);
    func_08011E08();
    func_080076C0(0x65, 7, 8, 2, D_08668094);
    func_08011E24();
    func_08011F18(0, 0xE0, 0xC0, 0x20, 1, 0);
    func_08008B58(0x104);
    func_08008B70(1, 0xB, 4);
    func_08011F18(1, 0x160, 0xA0, 0x20, 2, 1);
    func_08011F18(1, 0xE0, 0x140, 0x20, 2, 1);
    func_08008B70(1, 0xFF, 0xFF);
    func_08001A08(4);
    D_02000B54 = 0;
    func_080019B4(4);
    func_08008B58(0x105);
    func_08003D78(4, func_08017918);
    func_08011E08();
    func_08003DD8(4);
    func_080076C0(0x5E, 0x27, 3, 2, D_08668094);
    func_08001A08(9);
    D_02000B54 = 0;
    func_080019B4(9);
    func_08008B70(1, 0x24, 3);
    func_08011E24();
    func_0805EE78(0xF);
    func_08000BD8(2, 3);
    func_0805EE78(0xF);
    func_08008B58(0x106);
    func_08011F18(1, 0x440, 0x60, 0x20, 2, 1);
    func_08008B70(1, 0xFF, 0xFF);
    func_08008B58(0x107);
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    func_08007188(0x5E, 0x27, 3, 0xFFFF);
    func_080014A8(1, func_0800BEA4);
}
