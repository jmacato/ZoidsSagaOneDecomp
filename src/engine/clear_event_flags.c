#include "engine/event_flags.h"

void clear_event_flags(void)
{
    u16 selector = 0;
    u16 *flags;

    asm volatile("" : "+r"(selector));
    flags = event_flags;
    do {
        flags[selector] = 0;
        selector++;
    } while (selector <= 32);
}
