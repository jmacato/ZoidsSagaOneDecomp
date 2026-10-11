#include "engine/bios.h"
#include "graphics/sprites.h"

u32 refresh_sprite_animation(u32 selector)
{
    register u32 result asm("r0") = selector;
    register u32 selected asm("r1") = result;
    register Sprite *sprite asm("r3");
    register Sprite *pool asm("r1");
    register u32 offset asm("r2");
    register const u16 *script asm("r4");
    register u16 step asm("r5");

    asm volatile("" : "+r"(selected));
    selected = (u16)selected;
    offset = selected * sizeof(Sprite);
    pool = sprite_pool;
    sprite = (Sprite *)(offset + (u32)pool);
    script = sprite->animations[sprite->animation_id];

    sprite->current_animation = script;
    step = sprite->animation_step;
    if (sprite->flags & 0x4000) {
        register const SpritePiece *piece asm("r2") = sprite->frames[script[step]];

        asm volatile("" : : "r"(step));
        sprite->graphics_bytes = (piece->width >> 1) * (piece->height >> 1) * 2;
        sprite->current_graphics = sprite->graphics_source + (piece->tile << 5);
        result = bios_cpu_set(sprite->current_graphics, sprite->graphics_destination, *(volatile u16 *)&sprite->graphics_bytes >> 1);
    }
    return result;
}
