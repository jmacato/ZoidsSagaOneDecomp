#include "text.h"

void window_clear_tilemap(void)
{
    u16 index;

    for (index = 0; index <= 1023; index++)
        window_tilemap[index] = 0xF000 + window_tile_offset;
}
