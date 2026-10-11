#include "types.h"

struct AudioNote
{
    u8 flags;
    u8 pad_01[51];
    struct AudioNote *next;
};

struct AudioTrack
{
    u8 flags;
    u8 pad_01[31];
    struct AudioNote *notes;
};

void func_0805B3BC(struct AudioNote *note);

void func_0805B3DC(void *player, struct AudioTrack *track)
{
    register struct AudioTrack *owner asm("r5");
    register struct AudioNote *note asm("r4");
    asm("add %0, %1, #0" : "=r"(owner) : "r"(track) : "cc");
    note = owner->notes;
    asm("" : "+r"(note));
    while (note)
    {
        asm("" : "+r"(note));
        register u32 flags asm("r1") = note->flags;
        register u32 mask asm("r0");
        asm("" : "+r"(flags) : : "r0");
        mask = 0xC7;
        /* Thumb-1 has no GCC flag outputs, so branch directly on the mask test. */
        asm goto("tst %0, %1\n\tbeq %l[unlink]" : "+r"(mask) : "r"(flags) : "cc" : unlink);
        mask = 0x40;
        asm("" : "+r"(mask));
        flags |= mask;
        note->flags = flags;
    unlink:
    {
        register struct AudioNote *argument asm("r0");
        asm("add %0, %1, #0" : "=r"(argument) : "r"(note) : "cc");
        func_0805B3BC(argument);
    }
        note = note->next;
        asm("" : "+r"(note));
    }
    {
        register u32 zero asm("r0") = 0;
        asm("" : "+r"(zero));
        owner->flags = zero;
    }
}
