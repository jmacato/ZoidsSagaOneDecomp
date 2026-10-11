#include "types.h"

struct Actor
{
    u16 flags;
    u8 pad_2[6];
    s32 x;
    u8 pad_C[0x40];
    u16 field_4C;
    u16 field_4E;
    u16 field_50;
    u16 field_52;
    u16 field_54;
    u16 field_56;
    u16 field_58;
};

struct Sprite
{
    u16 flags;
    u8 pad_2[0x4A];
    u16 field_4C;
    u8 pad_4E[0x3A];
};

extern struct Sprite D_03004C44[];

s32 func_08001080(void);

void func_08049D58(struct Actor *actor)
{
    if (actor->flags & 0x8000)
    {
        if (actor->field_50 == 0)
        {
            actor->field_56 = 0;
            actor->field_58 = 0;
            actor->field_50 = 1;
            actor->field_52 = 0xFF;
        }
        else
        {
            s32 step;

            if (actor->field_58 == (u8)actor->field_54)
            {
                struct Sprite *sprite = &D_03004C44[actor->field_4E];

                if (sprite->field_4C != 0)
                    sprite->flags |= 0x8000;
            }
            step = actor->field_54 >> 8;
            actor->x -= step << 16;
            actor->field_56 += step;
            actor->field_58++;
            if (actor->field_56 > 0xA0)
            {
                if (actor->field_52 == 0xFF)
                {
                    actor->field_52 = func_08001080() & 0xF;
                }
                else if (actor->field_52 != 0)
                {
                    actor->field_52--;
                }
                else
                {
                    actor->field_52 = 0xFF;
                    actor->x += actor->field_56 << 16;
                    actor->field_56 = 0;
                    actor->field_4C = 0;
                }
            }
        }
    }
}
