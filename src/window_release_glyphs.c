#include "text.h"

void window_release_glyphs(u8 window)
{
    u16 index = 0;

    do {
        u8 slot = text_windows[window].glyph_slots[index];

        if (slot != 0xFF)
            text_tile_usage[slot] |= 0xFF;
        index++;
    } while (index <= 0x33F);
}
