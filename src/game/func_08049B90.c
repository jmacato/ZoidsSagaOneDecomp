#include "types.h"

struct Actor
{
    u16 flags;
    u8 pad_2[0x4A];
    u16 active;
    u8 pad_4E[2];
    u16 done;
    u8 pad_52[2];
    u16 limit;
    u8 pad_56[2];
    u16 count;
    u8 pad_5A[0xA];
    u16 field_64;
    u8 pad_66[4];
    u16 item;
    u16 sound;
};

u8 func_08049B50(struct Actor *);
u8 func_08049B70(struct Actor *);
void func_080440D8(u8);
void func_080019EC(u16);
void func_08049A5C(struct Actor *);

void func_08049B90(struct Actor *actor)
{
    if (actor->active && func_08049B50(actor))
    {
        if (func_08049B70(actor))
        {
            actor->flags |= 0x8000;
            actor->done = 1;
            if (actor->item)
                func_080440D8(actor->item);
            if (actor->sound)
                func_080019EC(actor->sound);
        }
        if (actor->count > actor->limit)
        {
            func_08049A5C(actor);
            actor->field_64 = 0;
        }
    }
}
