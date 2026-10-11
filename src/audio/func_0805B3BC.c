#include "types.h"

struct AudioTrack;

struct AudioList
{
    u8 pad_0[0x20];
    struct AudioTrack *head;
};

struct AudioTrack
{
    u8 pad_0[0x2C];
    struct AudioList *owner;
    struct AudioTrack *previous;
    struct AudioTrack *next;
};

void func_0805B3BC(struct AudioTrack *track)
{
    register struct AudioTrack *current asm("r0") = track;
    register struct AudioList *owner asm("r3") = current->owner;

    asm("" : : "r"(owner));
    if (owner != 0)
    {
        register struct AudioTrack *next asm("r1") = current->next;
        register struct AudioTrack *previous asm("r2") = current->previous;

        asm("" : : "r"(next), "r"(previous));
        if (previous != 0)
            previous->next = next;
        else
            owner->head = next;
        if (next != 0)
            next->previous = previous;
        {
            register u32 zero asm("r1") = 0;

            asm("" : : "r"(current), "r"(zero));
            current->owner = (struct AudioList *)zero;
        }
    }
}
