#include "engine/bios.h"
#include "graphics/sprites.h"

void advance_sprite_animation(u16 selector, u16 stop_at_end)
{
    u16 stop = stop_at_end;
    register Sprite *sprite asm("r3");
    register u32 flags asm("r1");
    register u32 previous asm("r6");
    register u32 step asm("r4");
    register const u16 *script asm("r5");
    register u32 offset asm("r1");
    u32 remaining;
    register Sprite *pool asm("r0");
    register u32 duration asm("r1");
    register u32 frame_offset asm("r2");
    register u32 scaled_duration asm("r0");

    offset = selector * sizeof(Sprite);
    pool = sprite_pool;
    sprite = (Sprite *)(offset + (u32)pool);
    flags = sprite->flags;
    if (!(flags & 0x8000))
        return;
    asm volatile("" : "+r"(flags));
    if (flags & 0x14)
        return;
    remaining = sprite->frame_timer - 1;
    sprite->frame_timer = remaining;
    if ((u16)remaining != 0)
        return;
    previous = sprite->animation_step;
    sprite->animation_step = previous + 2;
    step = *(volatile u16 *)&sprite->animation_step;
    script = sprite->current_animation;
    if (script[step] == 0xFFFF) {
        if (stop) {
            register u32 stopped asm("r0") = 4;

            asm volatile("" : "+r"(stopped));
            stopped |= flags;
            sprite->flags = stopped;
            offset = 0x10000;
            asm volatile("" : "+r"(offset));
            stopped = previous + offset;
            asm volatile("" : "+r"(stopped));
            sprite->animation_step = stopped;
            return;
        }
        sprite->animation_step = stop;
        step = *(volatile u16 *)&sprite->animation_step;
    }
    if (sprite->animation_speed & 0x8000) {
        frame_offset = step * 2;
        duration = ((const u16 *)(frame_offset + (u32)script))[1];
        asm volatile("" : "+r"(duration));
        duration <<= -sprite->animation_speed;
    } else {
        register u32 index asm("r0") = step * 2;

        duration = (s32)((const u16 *)(index + (u32)script))[1] >> sprite->animation_speed;
        frame_offset = index;
    }
    sprite->frame_timer = duration;
    scaled_duration = duration << 16;
    asm volatile("" : "+r"(scaled_duration));
    if (scaled_duration == 0)
        sprite->frame_timer = 1;
    if (sprite->flags & 0x4000) {
        register const u16 *frame_pointer asm("r0") = (const u16 *)(frame_offset + (u32)script);
        register u32 frame asm("r2") = *frame_pointer;
        register const SpritePiece *piece asm("r2");
        register const SpritePiece **frames asm("r1");
        register u32 frame_address asm("r0");

        asm volatile("" : "+r"(frame));
        frames = sprite->frames;
        frame_address = frame * sizeof(*frames);
        piece = *(const SpritePiece **)(frame_address + (u32)frames);

        sprite->graphics_bytes = (piece->width >> 1) * (piece->height >> 1) * 2;
        sprite->current_graphics = sprite->graphics_source + (piece->tile << 5);
        bios_cpu_set(sprite->current_graphics, sprite->graphics_destination, *(volatile u16 *)&sprite->graphics_bytes >> 1);
    }
}
