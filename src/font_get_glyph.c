#include "text.h"

const u8 *font_get_glyph(u16 code)
{
    u8 range = font_find_range(code);
    const u8 *glyph;

    if (range != 0xFF) {
        u16 index = code - font_ranges[range].first;
        u16 bank = 0;

        while (index > 31) {
            bank++;
            index -= 32;
        }
        if (range != font_current_range)
            font_current_range = range;
        glyph = font_ranges[range].tiles;
        glyph += bank << 11;
        glyph += index << 5;
    } else {
        u16 index;

        for (index = 0; index <= 31; index++)
            font_glyph_buffer[index] = font_missing_upper[index];
        for (index = 0; index <= 31; index++)
            font_glyph_buffer[index + 0x400] = font_missing_lower[index];
        glyph = font_glyph_buffer;
    }
    {
        register const u8 *result asm("r1") = glyph;

        /* The original paths join with their result in r1. */
        asm volatile("" : "+r"(result));
        return result;
    }
}
