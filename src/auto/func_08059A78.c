#include "m2c.h"

u32 func_08059A78(void)
{
    u8 temp_r1;

    temp_r1 = *(u8 *)0x0300232A;
    return (u32) ((0 - temp_r1) | temp_r1) >> 0x1F;
}
