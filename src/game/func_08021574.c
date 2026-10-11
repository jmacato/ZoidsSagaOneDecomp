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
void func_080250FC(void);

void func_08021574(void)
{
    struct Obj *obj = &D_03004BBC;

    if (obj->x == 0x2000000 && obj->y == 0x1400000)
    {
        u16 *flag = &obj->field_E8;
        u16 one = 1;

        D_02000000.counter |= 2;
        *flag = one;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_080250FC);
    }
}
