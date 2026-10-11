#include "types.h"

extern struct
{
    void *first;
} D_02000000;

struct Obj
{
    u8 pad_0[0x90];
    u32 x;
    u32 y;
    u8 pad_98[0x50];
    u16 field_E8;
};

extern struct Obj D_03004BBC;

void func_08011E04(void);
void func_0801C684(void);
void func_0801CA80(void);
void func_08003D78(s32, void *);
void func_08000F88(s32);

void func_0801B6B4(void)
{
    struct Obj *obj = &D_03004BBC;

    if (obj->x == 0x280000 && obj->y > 0x2FFFFF && obj->y <= 0x500000)
    {
        obj->field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_0801C684);
        func_08000F88(0x19D);
    }
    else if (obj->x == 0x1B80000 && obj->y > 0x2FFFFF && obj->y <= 0x500000)
    {
        obj->field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_0801CA80);
        func_08000F88(0x19D);
    }
}
