#include "text.h"

void window_draw_direction(u8 window, u16 direction, u8 erase)
{
    u8 base = text_windows[window].palette << 3;
    u8 x;
    u8 y;

    if (!erase)
    {
        base += 0x22;
        switch (direction)
        {
        case 0x20:
            if (text_windows[window].unknown0f & 1)
            {
                x = text_windows[window].x;
                y = text_windows[window].height / 2 + text_windows[window].y;
                window_write_tile(x, y - 1, base + 4, 0);
                window_write_tile(x, y, base + 5, 2);
            }
            break;
        case 0x10:
            if (text_windows[window].unknown0f & 2)
            {
                x = text_windows[window].x + text_windows[window].width - 1;
                y = text_windows[window].height / 2 + text_windows[window].y;
                window_write_tile(x, y - 1, base + 6, 0);
                window_write_tile(x, y, base + 7, 2);
            }
            break;
        case 0x40:
            x = text_windows[window].width / 2 + text_windows[window].x;
            y = text_windows[window].y;
            if (text_windows[window].width & 1)
            {
                window_write_tile(x, y, base, 0);
            }
            else
            {
                window_write_tile(x - 1, y, base + 1, 0);
                window_write_tile(x, y, base + 1, 1);
            }
            break;
        case 0x80:
            x = text_windows[window].width / 2 + text_windows[window].x;
            y = text_windows[window].y + text_windows[window].height - 1;
            if (text_windows[window].width & 1)
            {
                window_write_tile(x, y, base + 2, 0);
            }
            else
            {
                window_write_tile(x - 1, y, base + 3, 0);
                window_write_tile(x, y, base + 3, 1);
            }
            break;
        }
    }
    else
    {
        base += 2;
        switch (direction)
        {
        case 0x20:
            x = text_windows[window].x;
            y = text_windows[window].height / 2 + text_windows[window].y;
            window_write_tile(x, y - 1, base + 6, 1);
            window_write_tile(x, y, base + 6, 1);
            break;
        case 0x10:
            x = text_windows[window].x + text_windows[window].width - 1;
            y = text_windows[window].height / 2 + text_windows[window].y;
            window_write_tile(x, y - 1, base + 6, 0);
            window_write_tile(x, y, base + 6, 0);
            break;
        case 0x40:
            x = text_windows[window].width / 2 + text_windows[window].x;
            y = text_windows[window].y;
            window_write_tile(x - 1, y, base + 4, 0);
            window_write_tile(x, y, base + 4, 0);
            break;
        case 0x80:
            x = text_windows[window].width / 2 + text_windows[window].x;
            y = text_windows[window].y + text_windows[window].height - 1;
            window_write_tile(x - 1, y, base + 5, 0);
            window_write_tile(x, y, base + 5, 0);
            break;
        }
    }
}
