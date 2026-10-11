#include "types.h"

#pragma GCC optimize("no-reorder-blocks")
register u8 *pattern_track asm("r1");

void func_0805B46C(void)
{
    register u32 depth asm("r2") = pattern_track[2];
    asm("" : "+r"(depth));
    asm goto("cmp %0, #3\n\tbhs %l[stop_track]" : : "r"(depth) : "cc" : stop_track);
    {
        depth <<= 2;
        asm("" : "+r"(depth));
        register u8 *slot asm("r3") = pattern_track + depth;
        asm("" : "+r"(slot));
        depth = *(u32 *)(pattern_track + 0x40);
        asm volatile("" : "+r"(depth));
        depth += 4;
        asm volatile("" : "+r"(depth));
        *(u32 *)(slot + 0x44) = depth;
        asm volatile("" : : : "memory");
        depth = pattern_track[2];
        asm volatile("" : "+r"(depth));
        depth++;
        asm volatile("" : "+r"(depth));
        pattern_track[2] = depth;
        asm volatile("b func_0805B44C" : : "r"(depth) : "memory");
        __builtin_unreachable();
    }
stop_track:
    asm volatile("b func_0805B3DC" : : : "memory");
    __builtin_unreachable();
}

const u16 pattern_padding __attribute__((section(".text"), aligned(2))) = 0;
