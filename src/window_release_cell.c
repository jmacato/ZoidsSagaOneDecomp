#include "text.h"

void window_release_cell(u8 window, u16 x, u16 y, u32 unused3, u32 unused4, u8 *slots)
{
    text_tile_usage[slots[x + y * text_windows[window].columns]] = 0xFF;
}
