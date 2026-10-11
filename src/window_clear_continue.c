#include "text.h"

void window_clear_continue(u8 window)
{
    u32 tile = text_windows[window].palette * 8;
    u8 x = text_windows[window].x + text_windows[window].width - 2;
    u8 y = text_windows[window].y + text_windows[window].height - 1;

    window_write_tile(x, y, tile + 7, 0);
}
