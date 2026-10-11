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
void func_08008B58(s32);
void func_08008024(void);
void func_08003DD8(s32);
void func_08001A08(s32);
void func_080019B4(s32);
void func_08000F88(s32);

struct Obj
{
    u8 pad_0[0xB8];
    u16 dir;
    u8 pad_BA[6];
    u16 field_C0;
    u8 pad_C2[0x10];
    u16 field_D2;
    u8 pad_D4[2];
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

s32 func_08001040(s32);
void func_080144BC(void);
void func_080144DC(void);

void func_08015118(void)
{
    register struct Obj *obj asm("r2");
    u16 *busy;
    register struct Obj *initial asm("r1");
    register u32 direction asm("r3");
    u32 r;

    while (D_03004BBC.field_D2)
        func_0805EE78(1);
    r = func_08001040(0x15B);
    if (!r)
    {
        func_08000F88(0x15B);
        func_08001A08(4);
        D_02000B54 = r;
        func_080019B4(4);
        func_08008B58(0xB2);
        func_08001A08(D_0200000C.music);
        D_02000B54 = r;
        func_080019B4(D_0200000C.music);
    }
    else
        func_08008B58(0xB3);
    initial = &D_03004BBC;
    asm("" : "+r"(initial));
    direction = initial->dir;
    obj = initial;
    asm("" : : "r"(obj), "r"(direction));
    if (direction == 0)
    {
        initial->field_E8 = 11;
        {
            register u32 value asm("r0") = obj->x;
            register u16 *target asm("r1");

            asm("" : "+r"(value));
            target = &obj->target_x;
            asm("" : : "r"(target));
            *target = value;
            value = obj->y + 1;
            asm("" : : "r"(value));
            target++;
            asm("" : "+r"(target));
            *target = value;
        }
        obj->speed = 0x20000;
        obj->delay = D_0200000C.delay << 2;
        obj->field_C0 = 2;
    }
    else if (direction == 1)
    {
        obj->field_E8 = 11;
        {
            register u32 value asm("r0") = obj->x;
            register u16 *target asm("r1");

            asm("" : "+r"(value));
            target = &obj->target_x;
            asm("" : : "r"(target));
            *target = value;
            value = obj->y - 1;
            asm("" : : "r"(value));
            target++;
            asm("" : "+r"(target));
            *target = value;
        }
        obj->speed = 0x20000;
        obj->delay = D_0200000C.delay << 2;
        obj->field_C0 = 2;
    }
    else if (direction == 2)
    {
        obj->field_E8 = 11;
        obj->target_x = obj->x + 1;
        obj->target_y = obj->y;
        obj->speed = 0x20000;
        obj->delay = D_0200000C.delay << 2;
        obj->field_C0 = direction;
    }
    else
    {
        obj->field_E8 = 11;
        obj->target_x = obj->x - 1;
        obj->target_y = obj->y;
        obj->speed = 0x20000;
        obj->delay = D_0200000C.delay << 2;
        obj->field_C0 = 2;
    }
    asm("" : "+r"(obj));
    {
        register u16 *first_busy asm("r1") = &obj->field_E8;
        register u32 value asm("r0");

        value = *first_busy;
        asm("" : "+r"(value) : "r"(first_busy));
        if (value != 1)
        {
            busy = first_busy;
            do
                func_0805EE78(1);
            while (*busy != 1);
        }
    }
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_080144DC;
    func_080144BC();
}
