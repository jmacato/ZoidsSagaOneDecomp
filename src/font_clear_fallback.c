#include "text.h"

void font_clear_fallback(void)
{
    u16 index;

    for (index = 0; index <= 0x2FFF; index++) {
        ((u8 *)0x0200911C)[index] = 0;
    }
}
