#include "graphics/fade.h"

int step_fade_from_black(u16 frame_mask)
{
    u32 count;
    u32 level;

    if (frame_mask == 65535) {
        display_fade_level = 0;
        return 1;
    }
    level = fade_level;
    if (level == 0)
        return 1;
    count = fade_counter + 1;
    fade_counter = count;
    if ((count & frame_mask) == 0) {
        u32 next_level = level - 1;

        fade_level = next_level;
        display_fade_level = next_level;
    }
    return 0;
}
