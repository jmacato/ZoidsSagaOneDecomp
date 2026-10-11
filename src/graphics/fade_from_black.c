#include "graphics/fade.h"

void wait_for_frame_updates(u16);

u32 fade_from_black(u16 mask, void (*callback)(void))
{
    register u32 result asm("r0");
    u16 frame = 0;
    u16 level = 0x1F;
    u16 *fade;
    register u32 end asm("r10");

    display_fade_level = level;
    *(vu16 *)0x04000050 = 0x3FFF;
    if (mask == 0xFFFF)
    {
        callback();
        wait_for_frame_updates(1);
        /* Preserve the register value that the original frame routine returns. */
        asm("" : "=r"(result));
        display_fade_level = 0;
    }
    else
    {
        fade = &display_fade_level;
        end = 0xFFFF;
        do
        {
            register u32 next_level asm("r4") = level - 1;

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
        } while (level != end);
    }
    return result;
}
