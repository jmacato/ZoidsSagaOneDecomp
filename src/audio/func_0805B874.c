#include "types.h"

#pragma GCC optimize("no-toplevel-reorder")

struct AudioNote
{
    u8 flags;
    u8 type;
    u8 pad_02[42];
    void *owner;
    void *previous;
    struct AudioNote *next;
};

struct AudioTrack
{
    u8 flags;
    u8 pad_01[31];
    struct AudioNote *notes;
};

struct AudioEngine
{
    u8 pad_00[44];
    void (*release)(u32);
};

extern struct AudioEngine *D_03007FF0;

void func_0805B864(u32 kind);

__attribute__((optimize("no-reorder-blocks", "no-move-loop-invariants", "no-tree-loop-im"))) void
func_0805B874(void *player, struct AudioTrack *track)
{
    register struct AudioTrack *owner asm("r5");
    register struct AudioNote *note asm("r4");
    register u32 zero asm("r6");
    asm("add %0, %1, #0" : "=r"(owner) : "r"(track) : "cc");
    {
        register u32 flags asm("r1") = owner->flags;
        register u32 mask asm("r0");
        asm("" : "+r"(flags) : : "r0");
        mask = 0x80;
        asm goto("tst %0, %1\n\tbeq %l[done]" : "+r"(mask) : "r"(flags) : "cc" : done);
    }
    note = owner->notes;
    asm("" : "+r"(note));
    if (note == 0)
        goto detached;
    zero = 0;
    asm("" : "+r"(zero));
    do
    {
        asm("" : "+r"(note));
        register u32 flags asm("r0") = note->flags;
        asm("" : "+r"(flags));
        if (flags)
        {
            register u32 kind asm("r0") = note->type;
            register u32 mask asm("r3");
            asm("" : "+r"(kind) : : "r3");
            mask = 7;
            asm("" : "+r"(mask));
            asm goto("and %0, %1\n\tbeq %l[clear]" : "+r"(kind) : "r"(mask) : "cc" : clear);
            {
                register struct AudioEngine **slot asm("r3");
                asm("ldr %0, sound_info_pool + 2" : "=r"(slot));
                register void (*release)(u32) asm("r3") = (*slot)->release;
                /* The original callback veneer consumes its target through r3. */
                asm volatile("" : : "r"(release));
                func_0805B864(kind);
            }
        clear:
            asm("" : "+r"(zero), "+r"(note));
            note->flags = zero;
        }
        asm("" : "+r"(note), "+r"(zero) : : "memory");
        note->owner = (void *)zero;
        asm("" : "+r"(note), "+r"(zero) : : "memory");
        note = note->next;
        asm("" : "+r"(note));
    } while (note);
detached:
    asm("" : "+r"(note));
    owner->notes = note;
done:
    return;
}

struct SoundInfoPool
{
    u16 padding;
    struct AudioEngine **slot;
} __attribute__((packed));

/* Keep the hardware pointer beside the code, after the original zero padding. */
static const struct SoundInfoPool sound_info_pool
    __attribute__((used, section(".text"), aligned(2))) = {0, &D_03007FF0};
