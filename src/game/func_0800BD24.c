#include "types.h"

struct Sprite
{
    u8 pad_0[0x4A];
    u16 field_4A;
    u8 pad_4C[0xC];
    u16 parent;
    u8 pad_5A[0x26];
    void (*callback)(u16);
    u8 pad_84[4];
};

extern struct Sprite D_03004BBC[];

void func_0800BD24(u16 index)
{
    struct Sprite *base = D_03004BBC;
    struct Sprite *sprite = &base[index];
    u16 *parent = &sprite->parent;

    if (D_03004BBC[*parent].callback)
        D_03004BBC[*parent].callback(index);
    sprite->field_4A = 0;
    base[*parent].field_4A = 0;
}
