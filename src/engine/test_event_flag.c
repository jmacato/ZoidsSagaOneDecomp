#include "engine/event_flags.h"

u16 test_event_flag(u16 selector)
{
    register u32 shifted asm("r0") = (u32)selector << 16;
    register u16 *flags asm("r1") = (u16 *)player_state;
    register u32 offset asm("r2");
    register u16 *word asm("r2");
    register const u16 *masks asm("r3");
    register const u16 *mask asm("r1");

    asm volatile("" : "+r"(flags));
    offset = (shifted >> 20) * 2;
    flags += 6;
    word = (u16 *)(offset + (u32)flags);
    masks = event_flag_masks;
    mask = (const u16 *)(((shifted & 0xF0000) >> 15) + (u32)masks);
    return *word & *mask;
}
