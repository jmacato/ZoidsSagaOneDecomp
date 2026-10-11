#include "graphics/sprites.h"

extern void func_0805ED60(void *destination, const void *source, u32 size);

void copy_sprite_and_set_animation(u16 selector, const Sprite *source, u16 animation)
{
    register Sprite *pool asm("r2") = sprite_pool;

    asm volatile("" : "+r"(pool));
    func_0805ED60((Sprite *)(selector * sizeof(Sprite) + (u32)pool), source, sizeof(Sprite));
    set_sprite_animation(selector, animation);
}
