#include "graphics/sprites.h"

void maybe_sort_sprite_order(void)
{
    if (sprite_sort_mode == 1)
        sort_sprite_order();
}
