#include "types.h"

extern u16 D_03002356;
extern u8 D_0200DA9A;

u8 func_08042094(void)
{
    D_03002356 = 16 - D_0200DA9A;
    D_0200DA9A += 2;
    if (D_0200DA9A > 16)
        return 1;
    return 0;
}
