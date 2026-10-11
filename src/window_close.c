#include "text.h"

void window_close(u8 window)
{
    u16 index;

    if ((text_windows[window].flags & 2) != 0)
        window_input_flags &= 0x7FFF;
    text_windows[window].id = window;
    text_windows[window].unknown06 = 0;
    text_windows[window].active = 0;
    window_release_glyphs(window);
    index = 0;
    do {
        text_windows[window].glyph_slots[index] |= 0xFF;
        index++;
    } while (index <= 191);
    text_windows[window].cursor_x = 0;
    text_windows[window].cursor_y = 0;
    text_windows[window].unknown0c = 0;
    text_windows[window].flags = 0;
}
