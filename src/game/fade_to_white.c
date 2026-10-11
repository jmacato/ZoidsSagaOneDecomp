#include "types.h"

extern u16 display_fade_level;

void wait_for_frame_updates(u16);

s32 fade_to_white(u16 mask)
{
    u16 frame = 0;
    u16 level = 0;
    u16 *fade;

    display_fade_level = level;
    *(vu16 *)0x04000050 = 0x3FBF;
    fade = &display_fade_level;
    do
    {
        do
        {
            frame++;
            wait_for_frame_updates(1);
        } while (frame & mask);
        *fade = level;
        level++;
    } while (level != 0x20);
}
