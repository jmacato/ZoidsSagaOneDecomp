#include "text.h"

#include "engine/tasks.h"
#include "graphics/transfer.h"

extern u16 D_0200D91C;
extern void *D_02009044;
extern void *D_02009040;
extern Transfer D_0200910C;
extern u8 D_0300239C[];
extern const u8 D_083B9310[];
extern const Transfer D_086BF890[];

void func_0803E134(u8 bg, u16 offset, u16 screen)
{
    u16 i;
    u16 j;
    Transfer load;

    D_0200D91C = (screen << 8) | (bg << 2);
    D_02009044 = D_0300239C + (screen << 11);
    {
        register void **destination asm("r4") = &D_02009040;
        register u32 video asm("r3");
        register u32 address asm("r0");

        asm("" : : "r"(destination));
        video = 0x06000000;
        asm("" : : "r"(video));
        address = bg << 14;
        asm("" : "+r"(address));
        address += video;
        asm("" : "+r"(address));
        D_02009040 = (void *)address;
        D_02009040 = (u8 *)D_02009040 + (offset << 5);
    }
    window_tile_offset = offset;
    D_0200910C.source = (const u8 *)window_tilemap;
    D_0200910C.destination = D_02009044;
    D_0200910C.byte_count = 0x800;
    font_current_range = 0xFF;
    window_clear_screen();
    window_clear_tilemap();
    for (i = 0; i < 8; i++)
    {
        text_windows[i].active = 0;
        text_windows[i].cursor_x = 0;
        text_windows[i].cursor_y = 0;
        text_windows[i].unknown0c = 0;
        for (j = 0; j <= 0x33F; j++)
            text_windows[i].glyph_slots[j] |= 0xFF;
    }
    /* The compressed transfer leaves its byte count unset, as the original does. */
    load.source = D_083B9310;
    load.destination = D_02009040;
    queue_transfer(&load, 0, 1);
    queue_transfer(D_086BF890, 0xB, 0);
    *(vu16 *)0x04000008 = D_0200D91C;
    yield_task_for_updates(1);
}
