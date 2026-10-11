#include "types.h"

extern u16 D_03002338;

void func_08001068(u16);
u16 func_08001080(void);

s32 func_0800A54C(void)
{
    u16 random;

    func_08001068(D_03002338);
    random = func_08001080();
    if (random <= 0x3FFF)
        return 0x40;
    if ((s16)random >= 0)
        return 0x80;
    if (random <= 0xBFFF)
        return 0x20;
    return 0x10;
}
