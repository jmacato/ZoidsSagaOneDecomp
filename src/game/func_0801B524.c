#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
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

s32 func_08001040(s32);
void func_08011E04(void);
void func_08003D78(s32, void *);
void func_08000F88(s32);
void func_0801D9A0(void);

void func_0801B524(void)
{
    struct Obj *obj = &D_03004BBC;

    if (obj->x == 0x2C00000 && obj->y == 0xE00000)
    {
        u16 *flag = &obj->field_E8;
        u16 one = 1;

        D_02000000.counter |= 2;
        *flag = one;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_0801D9A0);
        func_08000F88(0x1A3);
    }
}
