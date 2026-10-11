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
    u8 pad_8A[0x36];
    u16 field_C0;
    u8 pad_C2[0x14];
    u16 x;
    u16 y;
    u8 pad_DA[0xE];
    u16 field_E8;
    u8 pad_EA[8];
    u16 target_x;
    u16 target_y;
    u16 delay;
    u8 pad_F8[0xC];
    u32 speed;
    u8 pad_108[8];
    u16 flags;
    u8 pad_112[0x32];
    u32 field_144;
    u8 pad_148[0x16];
    u16 field_15E;
    u16 field_160;
};

extern struct Obj D_03004BBC;

void func_0805EE78(s32);
void func_08000BD8(s32, s32);
void func_080019EC(s32);
void func_08008B70(s32, s32, s32);
void func_08008B58(s32);
void func_08011E08(void);
void func_08008024(void);
void func_08003DD8(s32);
void func_08007188(s32, s32, s32, s32);
void func_0800BEA4(void);
void func_080014A8(s32, void *);

void func_0801C35C(void)
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
        if (obj->field_144 == 0x10040)
        {
            obj->flags_88 |= 0x8000;
            func_08008B70(0, obj->field_15E, obj->field_160);
            obj->field_E8 = 0xB;
            obj->target_x = 4;
            obj->target_y = 0x15;
            obj->speed = 0x10000;
            obj->delay = D_0200000C.delay << 3;
            obj->field_C0 = 1;
            func_080019EC(0x49);
        }
        func_0805EE78(1);
    }
    func_08000BD8(2, 0);
    D_03004BBC.flags &= 0xFBFF;
    func_08008B58(0x193);
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    func_08007188(0xB0, 4, 0x15, 0xFFFF);
    func_080014A8(1, func_0800BEA4);
}
