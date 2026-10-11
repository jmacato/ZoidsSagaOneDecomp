#include "types.h"

struct Actor
{
    u8 pad_0[0x4C];
    u16 field_4C;
    u8 pad_4E[0x16];
    u16 field_64;
};

void func_08049A5C(struct Actor *);

s32 func_08049B14(struct Actor *actor, u8 flags)
{
    if (!(flags & 1) && actor->field_64 == 0)
        return 0;
    if (flags & 2)
        func_08049A5C(actor);
    actor->field_4C = 1;
    return 1;
}
