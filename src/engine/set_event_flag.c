#include "engine/event_flags.h"

u32 set_event_flag(u32 selector)
{
    register u32 shifted asm("r2") = selector;
    register u16 *flags asm("r1");
    register u32 offset asm("r3");
    register u16 *word asm("r3");
    register const u16 *masks asm("r4");
    register const u16 *mask asm("r1");

    asm volatile("" : "+r"(shifted));
    shifted <<= 16;
    flags = (u16 *)player_state;
    asm volatile("" : "+r"(flags));
    offset = (shifted >> 20) * 2;
    flags += 6;
    word = (u16 *)(offset + (u32)flags);
    masks = event_flag_masks;
    mask = (const u16 *)(((shifted & 0xF0000) >> 15) + (u32)masks);
    *word |= *mask;
    return selector;
}
