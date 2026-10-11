#include "text.h"

void window_command(u8 window, u8 command, u8 high, u8 low);

void window_scroll_glyphs(u8 window)
{
    u8 saved[28];
    u8 *dst = text_windows[window].glyph_slots;
    u8 *src = dst + text_windows[window].columns;
    u8 i;
    u8 row;

    for (i = 0; i < text_windows[window].columns; i++)
        saved[i] = dst[i];
    for (row = 0; row < (text_windows[window].height - 2) / 2; row++)
    {
        for (i = 0; i < text_windows[window].width; i++)
        {
            *dst = *src;
            dst++;
            src++;
        }
    }
    window_command(window, 4, 0, 0);
    window_commit();
    for (i = 0; i < text_windows[window].columns; i++)
        window_release_cell(window, i, 0, text_windows[window].width, text_windows[window].height, saved);
}
