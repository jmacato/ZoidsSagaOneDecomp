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
    u8 pad_0[0xE8];
    u16 field_E8;
};

extern struct Obj D_03004BBC;

s32 func_08001040(s32);

void func_080170E8(void)
{
    s32 r = func_08001040(0x170);

    if (!r)
    {
        struct Obj *obj = &D_03004BBC;
        u16 *flag = &obj->field_E8;

        *flag = 1;
        func_08008B58(0x115);
        *flag = r;
    }
    else
    {
        struct Obj *obj = &D_03004BBC;
        u16 *flag = &obj->field_E8;

        r = 0;
        *flag = 1;
        func_08008B58(0x116);
        func_08000F88(0x174);
        *flag = r;
    }
}
