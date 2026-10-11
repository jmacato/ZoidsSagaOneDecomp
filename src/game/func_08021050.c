#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

struct Obj
{
    u8 pad_0[0xD2];
    u16 mode;
    u8 pad_D4[2];
    u16 x;
    u16 y;
    u8 pad_DA[0xE];
    u16 field_E8;
};

extern struct Obj D_03004BBC;
extern struct
{
    u8 pad_0[0xA];
    u16 level;
} D_02000B5C;

void func_08011E04(void);
void func_08023F94(void);
void func_080210F4(void);
void func_08003D78(s32, void *);
void func_08000F88(s32);

void func_08021050(void)
{
    if (D_02000B5C.level > 2)
    {
        struct Obj *obj = &D_03004BBC;
        u16 *flag = &obj->field_E8;
        u16 one = 1;

        D_02000000.counter |= 2;
        *flag = one;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08023F94);
        func_08000F88(0x1C4);
        func_08000F88(0x199);
    }
    else if (D_03004BBC.mode == 2 && D_03004BBC.x == 0xC && D_03004BBC.y == 0x10)
    {
        D_02000000.counter |= 2;
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_080210F4);
    }
}
