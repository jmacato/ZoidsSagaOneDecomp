#include "zoids/stats.h"

s32 calculate_stat_percentage(s32 value, s16 percentage)
{
    s32 result;
    u8 round_integer = 0;

    if ((value & 0xFFFF0000) == 0) {
        round_integer = 1;
        value <<= 16;
    }
    result = signed_divide(value, 100) * percentage;
    if (round_integer != 0) {
        u32 fraction = result & 0xFFFF;

        result >>= 16;
        if (fraction > 0x7FFF)
            result++;
    }
    return result;
}
