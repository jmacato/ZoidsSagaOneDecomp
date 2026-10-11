#include "graphics/fade.h"

void wait_for_frame_updates(u16);

u32 fade_to_black(u16 mask, void (*callback)(void))
{
    register u32 result asm("r0");
    u16 frame = 0;
    u16 level = 0;
    u16 *fade;

    display_fade_level = level;
    *(vu16 *)0x04000050 = 0x3FFF;
    if (mask == 0xFFFF)
    {
        display_fade_level = 0x1F;
        callback();
        wait_for_frame_updates(1);
        /* Preserve the register value that the original frame routine returns. */
        asm("" : "=r"(result));
    }
    else
    {
        fade = &display_fade_level;
        do
        {
            register u32 next_level asm("r5") = level + 1;

            do
            {
                frame++;
                callback();
                wait_for_frame_updates(1);
                asm("" : "=r"(result));
            } while (frame & mask);
            *fade = level;
            level = next_level;
            /* Keep the next level live for the original instruction order. */
            asm("" : : "r"(next_level));
        } while (level != 0x20);
    }
    return result;
}
