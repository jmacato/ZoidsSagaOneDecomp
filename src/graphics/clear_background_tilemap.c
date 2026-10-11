#include "engine/bios.h"
#include "graphics/sprites.h"

u32 clear_background_tilemap(void)
{
    u32 zero = 0;
    u16 selector;
    register u32 result asm("r0");
    register s32 *cameras asm("r4");

    result = bios_cpu_set(&zero, background_tilemap, 0x05000A00);
    selector = 0;
    cameras = camera_offsets;
    do {
        cameras[selector] = 0;
        selector++;
    } while (selector <= 7);
    return result;
}
