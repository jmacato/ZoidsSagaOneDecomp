#include "types.h"

struct Body
{
    u8 pad_0[8];
    s32 y;
};

struct Unit
{
    struct Body *body;
    u8 pad_4[0x2C8];
};

extern struct Unit D_0200EC54[];

void func_080317E4(s32);
s32 func_08032A88(s32, u16);

void func_0803178C(void)
{
    u16 i;

    func_080317E4(0);
    for (i = 0; i <= 5; i++)
    {
        if (func_08032A88(0, i) != 0)
            D_0200EC54[i].body->y -= 0x780000;
    }
}
