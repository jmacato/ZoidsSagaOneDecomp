#include "types.h"

extern u8 D_0200EB84[];

u16 func_08045B10(u8 side, u8 unit, u8 weapon)
{
    register u8 *base asm("r5") = D_0200EB84;
    register u32 unit_offset asm("r4");
    register u32 side_offset asm("r3");
    register u8 *count_base asm("r1");
    register u32 offset asm("r0");
    u16 count;
    u16 limit;
    u16 result;

    asm("" : : "r"(base));
    unit_offset = unit * 0x2CC;
    side_offset = side * 0x10D8;
    asm("" : : "r"(unit_offset), "r"(side_offset));
    offset = unit_offset + side_offset;
    count_base = base + 0x1C;
    asm("" : "+r"(count_base));
    count = *(u16 *)(offset + (u32)count_base);
    limit = *(u16 *)(weapon * 20 + unit_offset + side_offset + (u32)base + 0x64);
    if (count >= limit)
        result = 0;
    else
        result = count + 1;
    return result;
}
