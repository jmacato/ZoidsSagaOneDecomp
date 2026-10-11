#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

struct Obj
{
    u8 pad_0[0xE8];
    u16 field_E8;
};

extern struct Obj D_03004BBC;

void func_08011E04(void);
void func_08015F74(void);
void func_08003D78(s32, void *);
void func_08000F88(s32);

void func_080147B0(void)
{
    struct Obj *obj = (struct Obj *)&D_03004BBC;
    u16 *flag = &obj->field_E8;
    u16 one = 1;

    D_02000000.counter |= 2;
    *flag = one;
    D_02000000.first = func_08011E04;
    func_08003D78(3, func_08015F74);
    func_08000F88(0x15F);
    func_08000F88(0x16A);
}
