#include "text.h"

void window_draw_glyphs(u8 window, u16 x, u16 y, u8 width, u8 height)
{
    u16 slot = text_windows[window].unknown0c * text_windows[window].columns;
    u16 row;
    u16 col;
    u16 tile;

    switch (text_windows[window].style)
    {
    case 0:
    case 8:
        for (row = 0; row < height; row++)
        {
            for (col = 0; col < width; col++)
            {
                if (text_windows[window].glyph_slots[slot] != 0xFF)
                {
                    tile = (text_windows[window].glyph_slots[slot] << 1) + 0x40;
                    window_write_tile(x + col, y + row * 2, tile, 0);
                    window_write_tile(x + col, y + row * 2 + 1, tile + 1, 0);
                    slot++;
                }
                else
                {
                    window_write_tile(x + col, y + row * 2, 1, 0);
                    window_write_tile(x + col, y + row * 2 + 1, 1, 0);
                    slot++;
                }
            }
        }
        break;
    case 1:
        for (row = 0; row < height; row++)
        {
            for (col = 1; col < width + 1; col++)
            {
                if (text_windows[window].glyph_slots[slot] != 0xFF)
                {
                    tile = (text_windows[window].glyph_slots[slot] << 1) + 0x40;
                    window_write_tile(x + col, y + row * 2, tile, 0);
                    window_write_tile(x + col, y + row * 2 + 1, tile + 1, 0);
                    slot++;
                }
                else
                {
                    window_write_tile(x + col, y + row * 2, 1, 0);
                    window_write_tile(x + col, y + row * 2 + 1, 1, 0);
                    slot++;
                }
            }
        }
        break;
    }
}
