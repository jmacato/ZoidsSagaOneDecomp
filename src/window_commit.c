#include "text.h"

#include "engine/tasks.h"
#include "graphics/transfer.h"

extern Transfer D_0200910C;
extern void *D_02009044;
extern u8 D_03005BAE;

void window_commit(void)
{
    Transfer transfer;
    u16 i;
    register u16 *input asm("r3");
    register u8 *graphics asm("r5");
    register u8 *palette asm("r6");
    register Transfer *descriptor asm("r4");

    D_0200910C.source = window_tilemap;
    D_0200910C.destination = D_02009044;
    D_0200910C.byte_count = 0x800;
    D_03005BAE = 2;
    queue_transfer(&D_0200910C, 0, 0);
    i = 0;
    input = &window_input_flags;
    asm("" : : "r"(input));
    graphics = font_glyph_buffer;
    asm("" : "+r"(graphics));
    palette = graphics + 0x480;
    asm("" : : "r"(palette));
    descriptor = &transfer;
    asm("" : : "r"(descriptor));
    for (; i < 8; i++)
    {
        if (text_windows[i].active)
        {
            if (text_windows[i].flags & 2)
            {
                {
                    register u32 flags asm("r1") = *input;
                    register u32 bits asm("r2");
                    register u32 value asm("r0");

                    asm("" : "+r"(flags));
                    bits = 0x8000;
                    asm("" : "+r"(bits));
                    value = bits;
                    asm("" : "+r"(value));
                    value |= flags;
                    asm("" : "+r"(value));
                    *input = value;
                }
                transfer.source = graphics;
                transfer.destination = (void *)0x06017B80;
                descriptor->byte_count = 0x480;
                queue_transfer(&transfer, 0, 0);
                transfer.source = palette;
                transfer.destination = (void *)0x050003E0;
                descriptor->byte_count = 0x20;
                queue_transfer(&transfer, 0, 0);
                break;
            }
            *input &= 0x7FFF;
        }
    }
    yield_task_for_updates(1);
}
