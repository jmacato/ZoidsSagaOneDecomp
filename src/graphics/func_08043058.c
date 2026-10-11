#include "types.h"

void func_08043058(void)
{
    u16 i;

    for (i = 0; i <= 0x3F; i++)
    {
        register u32 offset asm("r1") = i * 2;
        register vu16 *color asm("r4");
        register u32 value asm("r0");
        register u32 red asm("r2");
        register u32 blue_reduced asm("r3");
        u16 green;
        u16 blue;
        u32 red_reduced;
        u16 green_reduced;

        asm("" : "+r"(offset));
        color = (vu16 *)(offset + 0x05000000);
        value = *color;
        red = 0x1F;
        asm("" : "+r"(red) : "r"(value));
        red &= value;
        value <<= 16;
        asm("" : "+r"(value));
        green = (value >> 21) & 0x1F;
        blue = (value >> 26) & 0x1F;
        red_reduced = red >> 3;
        green_reduced = green >> 3;
        blue_reduced = blue >> 3;
        asm("" : : "r"(blue_reduced));
        value = green_reduced << 5;
        asm("" : "+r"(value));
        red_reduced |= value;
        value = blue_reduced << 10;
        asm("" : "+r"(value));
        *color = red_reduced | value;
        asm("" : : "r"(color));
    }
    for (i = 0; i <= 0xFF; i++)
    {
        register u32 offset asm("r0") = i * 2;
        register u32 base asm("r1") = 0x05000200;
        register vu16 *color asm("r4");
        register u32 value asm("r0");
        register u32 red asm("r2");
        register u32 blue_reduced asm("r3");
        u16 green;
        u16 blue;
        u32 red_reduced;
        u16 green_reduced;

        asm("" : "+r"(offset) : "r"(base));
        color = (vu16 *)(offset + base);
        value = *color;
        red = 0x1F;
        asm("" : "+r"(red) : "r"(value));
        red &= value;
        value <<= 16;
        asm("" : "+r"(value));
        green = (value >> 21) & 0x1F;
        blue = (value >> 26) & 0x1F;
        red_reduced = red >> 3;
        green_reduced = green >> 3;
        blue_reduced = blue >> 3;
        asm("" : : "r"(blue_reduced));
        value = green_reduced << 5;
        asm("" : "+r"(value));
        red_reduced |= value;
        value = blue_reduced << 10;
        asm("" : "+r"(value));
        *color = red_reduced | value;
        asm("" : : "r"(color));
    }
}
