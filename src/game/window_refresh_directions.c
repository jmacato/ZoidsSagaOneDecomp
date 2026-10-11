#include "text.h"

void window_refresh_directions(u8 window, u8 mode)
{
    if (text_windows[window].style & 1)
    {
        u8 rows = (text_windows[window].height - 2) / 2 - 1;

        switch (mode)
        {
        case 2:
        case 5:
        case 6:
            window_draw_direction(window, 0x20, 0);
            window_draw_direction(window, 0x10, 0);
            break;
        case 3:
            window_draw_direction(window, 0x20, 0);
            break;
        case 4:
            window_draw_direction(window, 0x10, 0);
            break;
        }
        if (text_windows[window].unknown0c != 0)
            window_draw_direction(window, 0x40, 0);
        else
            window_draw_direction(window, 0x40, 1);
        if (text_windows[window].unknown0c + rows < text_windows[window].cursor_y)
            window_draw_direction(window, 0x80, 0);
        else
            window_draw_direction(window, 0x80, 1);
    }
}
