#include "types.h"

extern u8 D_0200DA9A;
extern u16 D_03002356;

void func_080480D4(u16, u16, s32, s32);

u8 func_0804200C(void)
{
    s32 first;
    s32 second;
    if (D_0200DA9A == 0)
    {
        first = 15;
        second = 8;
    }
    else
    {
        first = 15 - ((D_0200DA9A * 15) >> 4);
        second = 8 - (D_0200DA9A >> 1);
    }
    D_03002356 = D_0200DA9A;
    func_080480D4(first, second, 0, 6);
    D_0200DA9A += 2;
    if (D_0200DA9A > 16)
        return 1;
    return 0;
}
