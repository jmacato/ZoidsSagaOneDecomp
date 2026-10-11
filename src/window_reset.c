#include "text.h"

void window_reset(void)
{
    u16 index;

    window_clear_screen();
    text_current_window = text_windows;
    for (index = 0; index <= 7; index++)
        window_close(index);
    window_clear_tilemap();
    for (index = 0; index <= 191; index++)
        text_tile_usage[index] |= 255;
}
