#include "graphics/fade.h"

void start_fade_from_black(u32 value)
{
    fade_counter = 0;
    fade_level = 31;
    display_fade_level = 31;
    *(volatile u16 *)0x04000050 = 0x3FFF;
    asm volatile("" : : "r"(value));
}
