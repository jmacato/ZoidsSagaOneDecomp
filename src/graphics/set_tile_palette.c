#include "types.h"

void set_tile_palette(u16 *tile, u32 palette)
{
    u32 lower_bits = *tile & 0x0FFF;

    asm volatile("" : "+r"(lower_bits));
    *tile = (palette << 28) >> 16 | lower_bits;
}
