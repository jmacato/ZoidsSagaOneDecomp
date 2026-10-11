#include "engine/input.h"

void read_keys(void)
{
    u16 held = ~*(volatile u16 *)0x04000130;

    pressed_keys = held & ~held_keys;
    held_keys = held;
}
