#include "text.h"

void window_clear_screen(void)
{
    u16 *tilemap = window_screen_tilemap;
    u16 row;

    for (row = 0; row <= 19; row++) {
        u16 offset = row * 32;
        u16 column;

        for (column = 0; column <= 29; column++)
            tilemap[offset + column] = window_tile_offset + 0xF000;
    }
}
