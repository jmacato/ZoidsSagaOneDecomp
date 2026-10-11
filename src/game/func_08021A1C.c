#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

struct Obj
{
    u8 pad_0[0xD6];
    u16 x;
    u16 y;
    u8 pad_DA[0xE];
    u16 field_E8;
};

extern struct Obj D_03004BBC;

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_08000BD8(s32, s32);
s32 func_08000F88(s32);
void func_08011E04(void);
void func_08021AC0(void);
void func_08003D78(s32, void *);

void func_08021A1C(void)
{
    func_0800BEE4();
    if (func_08001040(0x1BC) != 0)
        func_08000BD8(2, 1);
    if (func_08000F88(0x1BA) != 0 && func_08001040(0x1C2) == 0)
    {
        if (func_08001040(0x1BC) == 0 || func_08001040(0x1BD) == 0 || func_08001040(0x1BE) == 0)
        {
            struct Obj *obj = &D_03004BBC;

            if (obj->x == 0x17 && obj->y == 0x17)
            {
                u16 *flag = &obj->field_E8;
                u16 one = 1;

                D_02000000.counter |= 2;
                *flag = one;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_08021AC0);
            }
        }
    }
}
