#include "types.h"

void apply_display_config(const u16 *config)
{
    register volatile u16 *display asm("r2") = (volatile u16 *)0x04000000;

    *display = config[0];
    display += 4;
    *display++ = config[1];
    *display++ = config[2];
    *display++ = config[3];
    *(volatile u16 *)0x0400000E = config[4];
}
