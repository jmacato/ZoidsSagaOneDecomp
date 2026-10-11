#include "text.h"

void window_emit_character(u8 window, u16 character)
{
    text_windows[window].callback(window, 3, character >> 8, character);
}
