#include "text.h"

void window_write_tile(u16 x, u16 y, u16 tile, u8 flip)
{
    if (x <= 0xFF && y <= 0xFF)
    {
        register u16 *destination asm("r2") = window_tilemap;
        register u16 *offset asm("r1");
        register u32 value asm("r0");

        asm("" : "+r"(destination));
        destination = (u16 *)((y * 32 + x) * 2 + (u32)destination);
        asm("" : : "r"(destination));
        offset = &window_tile_offset;
        asm("" : : "r"(offset));
        value = tile + 0xF000;
        asm("" : "+r"(value));
        {
            register u32 adjustment asm("r1") = *offset;

            asm("" : "+r"(adjustment));
            value += adjustment;
        }
        value |= flip << 10;
        asm("" : "+r"(value));
        *destination = value;
    }
}
