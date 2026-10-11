#include "text.h"

u8 text_find_free_slot(void)
{
    u8 index;

    for (index = 0; index <= 0xBF; index++) {
        if (((u8 *)0x0200904B)[index] == 0xFF) {
            return index;
        }
    }
    return 0xFF;
}
