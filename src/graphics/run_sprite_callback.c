#include "graphics/sprites.h"

void run_sprite_callback(u16 selector)
{
    Sprite *sprite = &sprite_pool[selector];
    SpriteCallback callback = sprite->callback;

    if (callback != 0)
        callback(sprite, sprite);
}
