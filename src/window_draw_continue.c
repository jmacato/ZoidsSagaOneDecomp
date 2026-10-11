#include "text.h"

void window_draw_continue(u8 window)
{
    u8 tile = text_windows[window].palette + 27;
    u8 x = text_windows[window].x + text_windows[window].width - 2;
    u8 y = text_windows[window].y + text_windows[window].height - 1;

    window_write_tile(x, y, tile, 0);
}
