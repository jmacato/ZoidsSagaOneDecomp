#include "types.h"

struct AudioTrack
{
    u8 flags;
    u8 unknown01[0x15];
    u8 field16;
    u8 field17;
    u8 mode;
    u8 field19;
    u8 field1A;
};

void func_0805BB28(void *unused, struct AudioTrack *track)
{
    register u32 bits asm("r2") = 0;
    register u32 flags asm("r3");

    asm("" : : "r"(bits));
    track->field16 = bits;
    track->field1A = bits;
    bits = track->mode;
    if (bits == 0)
        bits = 0xC;
    else
        bits = 3;
    asm("" : "+r"(bits));
    flags = track->flags;
    flags |= bits;
    track->flags = flags;
    /* The command callers retain flags in r3. */
    asm volatile("" : : "r"(flags));
}
