#include "types.h"

extern struct
{
    void *first;
} D_02000000;

struct Obj
{
    u8 pad_0[0xC0];
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
};

extern struct Obj D_03004BBC;

extern struct
{
    u8 pad_0[0x18];
    u16 delay;
} D_0200000C;

void func_0805EE78(s32);
void func_08000F88(s32);
void func_08000BD8(s32, s32);
void func_08008B58(s32);
void func_08037004(s32);
void func_08008024(void);
void func_08003DD8(s32);

void func_0800E78C(void)
{
    struct Obj *obj;
    u16 *flag;
    u16 one;

    while (D_03004BBC.x != 2 || (u16)(D_03004BBC.y - 2) > 1)
        func_0805EE78(1);
    func_08000F88(0x127);
    obj = &D_03004BBC;
    flag = &obj->field_E8;
    one = 1;
    *flag = 10;
    obj->target_x = one;
    obj->target_y = 3;
    obj->speed = 0x10000;
    obj->delay = D_0200000C.delay << 3;
    obj->field_C0 = one;
    while (D_03004BBC.field_E8 != 1)
        func_0805EE78(1);
    func_08000BD8(1, 1);
    func_0805EE78(0x1E);
    func_08008B58(0x2C0);
    func_0805EE78(0x1E);
    func_08037004(0x8F);
    D_03004BBC.field_E8 = 0;
    D_02000000.first = func_08008024;
    func_08003DD8(3);
}
