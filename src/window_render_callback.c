#include "text.h"

extern u8 *D_02009040;

u8 text_find_free_slot(void);

int window_render_callback(u8 window, u8 command, u8 high, u8 low)
{
    const u8 *glyph;
    u8 *dst;
    u16 i;
    u8 slot;
    u16 v;
    u16 j;

    switch (command)
    {
    case 1:
    case 2:
    case 6:
        break;
    case 3:
        if (text_windows[window].cursor_x >= text_windows[window].columns)
        {
            text_windows[window].cursor_x = 0;
            text_windows[window].cursor_y++;
        }
        if (text_windows[window].cursor_y > 0x1F)
        {
            text_windows[window].cursor_y = 0x20;
            break;
        }
        glyph = font_get_glyph(high << 8 | low);
        slot = text_find_free_slot();
        if (slot != 0xFF)
        {
            dst = D_02009040 + (slot * 64 + 0x800);
            for (j = 0; j < 0x20; j += 2)
            {
                v = glyph[j] | (glyph[j + 1] << 8);
                *(u16 *)(dst + j) = v;
            }
            dst += 0x20;
            glyph += 0x400;
            for (j = 0; j < 0x20; j += 2)
            {
                v = glyph[j] | (glyph[j + 1] << 8);
                *(u16 *)(dst + j) = v;
            }
            text_tile_usage[slot] = 0;
            text_windows[window].glyph_slots[text_windows[window].cursor_y * text_windows[window].columns + text_windows[window].cursor_x] = slot;
            text_windows[window].cursor_x++;
        }
        else
        {
            text_windows[window].cursor_x++;
        }
        break;
    case 4:
        window_draw_frame(window, text_windows[window].x, text_windows[window].y, text_windows[window].width, text_windows[window].height);
        window_draw_glyphs(window, text_windows[window].x + 1, text_windows[window].y + 1, text_windows[window].columns, (text_windows[window].height - 2) / 2);
        text_current_window = &text_windows[window];
        break;
    case 5:
        window_scroll_glyphs(window);
        text_windows[window].cursor_x = 0;
        break;
    case 7:
        text_windows[window].cursor_x = 0;
        text_windows[window].cursor_y = 0;
        text_windows[window].unknown0c = 0;
        text_windows[window].flags &= ~2;
        for (i = 0; i < 0xC0; i++)
        {
            u8 slot = text_windows[window].glyph_slots[i];

            if (slot != 0xFF)
            {
                text_tile_usage[slot] |= 0xFF;
                text_windows[window].glyph_slots[i] |= 0xFF;
            }
        }
        window_draw_frame(window, text_windows[window].x, text_windows[window].y, text_windows[window].width, text_windows[window].height);
        break;
    }
    return 0;
}
