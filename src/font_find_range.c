#include "text.h"

u8 font_find_range(u16 code)
{
    u8 index = 0;
    const FontRange *ranges = (const FontRange *)0x086BF920;

    do {
        if (ranges[index].first <= code &&
            ranges[index].first + ranges[index].count > code) {
            return index;
        }
        index++;
    } while (index <= 110);
    return 0xFF;
}
