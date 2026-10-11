#include "types.h"

struct Sprite
{
    u8 pad_0[0x4A];
    u16 field_4A;
    u8 pad_4C[0xC];
    u16 parent;
    u8 pad_5A[4];
    u16 message;
    u8 pad_60[0x28];
};

extern struct Sprite D_03004BBC[];
extern u8 D_0874FA90[];

void func_0803E488(u8 *, u16);

void func_0800B8E4(u16 index)
{
    struct Sprite *base = D_03004BBC;
    struct Sprite *sprite = &base[index];
    u16 *parent = &sprite->parent;
    struct Sprite *owner = &base[*parent];

    if (owner->message != 0)
        func_0803E488(D_0874FA90, owner->message);
    sprite->field_4A = 0;
    base[*parent].field_4A = 0;
}
