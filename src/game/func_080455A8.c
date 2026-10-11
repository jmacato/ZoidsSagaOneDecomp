#include "types.h"

struct Sprite
{
    u16 flags;
    u16 attributes;
    u8 pad_4[0x84];
};

extern struct Sprite D_03004BBC[];

void func_080455A8(u8 index, u32 unused, u8 flip)
{
    struct Sprite *sprites = D_03004BBC;
    struct Sprite *sprite = &sprites[index];

    sprite->flags |= 0x20;
    if (flip & 1)
        sprite->attributes |= 0x200;
}
