#include "text.h"

void window_draw_frame(u8 window, u16 x, u16 y, u8 width, u8 height)
{
    u16 base = text_windows[window].palette << 3;
    u8 row;
    u8 col;
    u16 tile;

    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            if (col == 0)
            {
                if (row == 0)
                {
                    if (text_windows[window].palette == 1 && (text_windows[window].flags & 0x10))
                        tile = 0x20;
                    else
                        tile = base + 2;
                }
                else if (row == height - 1)
                {
                    if (text_windows[window].palette == 1 && (text_windows[window].flags & 0x10))
                        tile = 0x21;
                    else
                        tile = base + 4;
                }
                else
                    tile = base + 8;
            }
            else if (col == width - 1)
            {
                if (row == 0)
                    tile = base + 3;
                else if (row == height - 1)
                    tile = base + 5;
                else
                    tile = base + 9;
            }
            else if (row == 0)
                tile = base + 6;
            else if (row == height - 1)
                tile = base + 7;
            else
                tile = 1;
            if (text_windows[window].palette & 4)
                tile = 1;
            window_write_tile(x + col, y + row, tile, 0);
        }
    }
}
