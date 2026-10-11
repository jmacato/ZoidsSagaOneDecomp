#include "engine/bios.h"
#include "graphics/sprites.h"

u32 set_sprite_animation(u32 selector, u32 animation_bits)
{
    register u32 result asm("r0") = selector;
    register u32 selected asm("r3") = result;
    register Sprite *sprite asm("r4");
    register u16 zero asm("r3");
    register const u16 *script asm("r1");
    register const u16 *frame_script asm("r3");
    u16 flags;
    register u32 duration asm("r1");
    register Sprite *pool asm("r3");
    register u32 offset asm("r2");
    u16 animation;

    asm volatile("" : "+r"(selected));
    selected = (u16)selected;
    asm volatile("" : "+r"(selected), "+r"(animation_bits));
    animation = animation_bits;
    offset = selected * sizeof(Sprite);
    pool = sprite_pool;
    sprite = (Sprite *)(offset + (u32)pool);

    flags = sprite->flags & ~4;
    zero = 0;
    asm volatile("" : "+r"(zero), "+r"(flags));
    sprite->flags = flags;
    sprite->animation_id = animation;
    script = sprite->animations[animation];
    sprite->current_animation = script;
    sprite->animation_step = zero;
    frame_script = script;
    sprite->first_frame = frame_script[0];
    if (sprite->animation_speed & 0x8000)
        duration = frame_script[1] << -sprite->animation_speed;
    else
        duration = (s32)frame_script[1] >> sprite->animation_speed;
    sprite->frame_timer = duration;
    if ((u16)duration == 0)
        sprite->frame_timer = 1;
    if (sprite->flags & 0x4000) {
        register u32 frame asm("r0") = 0;
        register const SpritePiece *piece asm("r2");

        asm volatile("" : "+r"(frame));
        piece = sprite->frames[frame_script[frame]];

        sprite->graphics_bytes = (piece->width >> 1) * (piece->height >> 1) * 2;
        sprite->current_graphics = sprite->graphics_source + (piece->tile << 5);
        result = bios_cpu_set(sprite->current_graphics, sprite->graphics_destination, *(volatile u16 *)&sprite->graphics_bytes >> 1);
    }
    return result;
}
