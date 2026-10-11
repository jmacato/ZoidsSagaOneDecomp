#include "types.h"

struct Actor
{
    u16 flags;
    u8 pad_2[0x32];
    u16 field_34;
    u8 pad_36[0x16];
    u16 field_4C;
    u16 field_4E;
    u16 field_50;
    u16 field_52;
    u16 field_54;
};

struct Sprite
{
    u16 flags;
    u8 pad_2[0x4E];
    u16 field_50;
    u8 pad_52[0x36];
};

extern struct Sprite D_03004BBC[];
extern u8 D_0200DA97;

void func_08000BD8(u16, s32);

void func_08049F04(struct Actor *actor)
{
    if (actor->flags & 0x8000)
    {
        if (actor->field_50 == 0)
            actor->field_50 = 1;
        if (actor->field_34 >= actor->field_52)
            D_03004BBC[(actor->field_54 >> 8) + D_0200DA97].flags |= 0x8000;
        if (actor->flags & 4)
        {
            struct Sprite *base = D_03004BBC;
            struct Sprite *sprite = &base[(u8)actor->field_54 + D_0200DA97];

            if (sprite->field_50 == 0)
                sprite->flags |= 0x8000;
            actor->flags &= 0x7FFF;
            func_08000BD8(actor->field_4E, 0);
            actor->field_4C = 0;
        }
    }
}
