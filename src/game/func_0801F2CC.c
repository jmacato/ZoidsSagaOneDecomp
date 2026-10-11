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
    u8 pad_108[0x118];
    u16 flags;
    u8 pad_222[0x32];
    u32 state;
    u8 pad_258[0x16];
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
void func_0801F47C(void);

void func_0801F2CC(void)
{
    struct Obj *obj;
    u16 *flags;

    func_0805EE78(0x20);
    func_08000BD8(4, 2);
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
            obj->target_x = 7;
            obj->target_y = 2;
            obj->speed = 0x10000;
            obj->delay = D_0200000C.delay << 3;
            obj->field_C0 = 1;
            func_080019EC(0x49);
        }
        func_0805EE78(1);
    }
    func_08000BD8(4, 0);
    D_03004BBC.flags &= 0xFBFF;
    func_08008B58(0x1EB);
    func_0805EE78(0x3C);
    func_08008B70(1, 2, 2);
    func_08011F18(1, 0xE0, 0x60, 0x20, 4, 1);
    func_08000BD8(2, 0);
    func_08001A08(4);
    D_02000B54 = 0;
    func_080019B4(4);
    func_08008B58(0x1EC);
    func_08008B70(2, 0xC, 2);
    func_08011F18(2, 0x120, 0x40, 0x20, 2, 1);
    func_08008B58(0x1ED);
    func_0805EE78(0xF);
    func_08000BD8(2, 3);
    func_0805EE78(0xF);
    func_08011F18(1, 0x100, 0x40, 0x20, 4, 1);
    func_08000BD8(2, 3);
    func_0805EE78(0xF);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_0801F47C;
    for (;;)
        func_0805EE78(1);
}
