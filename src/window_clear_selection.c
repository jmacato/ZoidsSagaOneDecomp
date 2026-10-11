#include "text.h"

void window_clear_selection(u8 window)
{
    TextWindow *base = text_windows;
    TextWindow *state;
    u32 offset;

    asm volatile("" : "+r"(base));
    offset = window * sizeof(TextWindow);
    state = (TextWindow *)(offset + (u32)base);

    if ((state->style & 1) != 0) {
        u8 x = state->x + 1;
        u8 y = state->y + 1;

        y += (state->unknown0d - state->unknown0c) * 2;
        window_write_tile(x, y, 1, 0);
        window_write_tile(x, y + 1, 1, 0);
        x += 1 + state->columns;
        window_write_tile(x, y, 1, 0);
        window_write_tile(x, y + 1, 1, 0);
    }
}
