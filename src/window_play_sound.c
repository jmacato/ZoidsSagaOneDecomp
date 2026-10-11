#include "text.h"

void func_080019EC(u16 sound);

void window_play_sound(u8 window, u8 sound)
{
    if ((text_windows[window].flags & 4) != 0 || window == 255)
        func_080019EC(sound + 60);
}
