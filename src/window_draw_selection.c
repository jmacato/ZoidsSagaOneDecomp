#include "text.h"

void window_draw_selection(u8 window)
{
    TextWindow *base = text_windows;
    TextWindow *state;
    u32 offset;
    u8 x;
    u8 y;

    asm volatile("" : "+r"(base));
    offset = window * sizeof(TextWindow);
    state = (TextWindow *)(offset + (u32)base);

    switch (state->style) {
    case 1:
        {
            x = state->x + 1;
            y = state->y + 1;

            y += (state->unknown0d - state->unknown0c) * 2;
            window_write_tile(x, y, 59, 0);
            window_write_tile(x, y + 1, 60, 0);
            x += 1 + state->columns;
            window_write_tile(x, y, 61, 0);
            window_write_tile(x, y + 1, 62, 0);
        }
        break;
    case 8:
        {
            x = state->x + state->cursor_x;
            y = state->y;

            window_write_tile(x, y, 63, 2);
            window_write_tile(x, y + 3, 63, 0);
        }
        break;
    }
}
