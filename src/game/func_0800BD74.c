#include "types.h"

struct Sprite
{
    u8 pad_0[0x4A];
    u16 field_4A;
    u16 field_4C;
    u8 pad_4E[0x3A];
};

extern struct Sprite D_03004BBC[];

void func_0800BD74(u16 index)
{
    struct Sprite *base = D_03004BBC;
    struct Sprite *sprite = &base[index];
    u16 *count = &sprite->field_4C;

    if (*count == 0)
        sprite->field_4A = 0;
    else
        (*count)--;
}
