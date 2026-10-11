#include "m2c.h"

void func_08031B10(void)
{
    s32 temp_r1;
    u8 var_r3;

    var_r3 = 0;
    do
    {
        temp_r1 = (var_r3 + 5) * 0x88;
        M2C_FIELD(temp_r1, u16 *, 0x03004BBC) = (u16) (0x7FFF & M2C_FIELD(temp_r1, u16 *, 0x03004BBC));
        var_r3 += 1;
    } while ((u32) var_r3 <= 5U);
}
