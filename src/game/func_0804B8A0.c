#include "types.h"

struct Sprite
{
    u8 pad_0[0x4C];
    u16 visible;
    u16 link;
    u8 pad_50[4];
    u16 state;
    u16 timer;
    u16 speed;
    u16 field_5A;
    u8 pad_5C[8];
    u16 field_64;
    u8 pad_66[6];
    u16 sound;
    u8 pad_6E[0xA];
    u32 field_78;
    u32 field_7C;
    u8 pad_80[8];
};

extern struct Sprite D_03004C44[];
extern u32 D_0200E288;
extern u32 D_0200E284;

void func_080440D8(s32);
void func_080019EC(u16);

void func_0804B8A0(struct Sprite *sprite)
{
    switch (sprite->state)
    {
    case 0:
        sprite->timer = 0;
        sprite->speed = 0x24;
        sprite->field_5A = 0;
        sprite->field_78 = D_0200E288;
        sprite->field_7C = 0;
        sprite->state++;
        sprite->field_78 += sprite->speed << 13;
        break;
    case 1:
        if (sprite->speed == 0)
        {
            register u16 *state asm("r0") = &sprite->state;
            register u32 next_state asm("r1") = *state + 1;

            asm("" : "+r"(state) : "r"(next_state));
            *state = next_state;
            state = (u16 *)((u32)state + 2);
            asm("" : "+r"(state));
            *state = 0;
            sprite->speed = 0;
        }
        else
        {
            sprite->timer++;
            sprite->speed -= 2;
            sprite->field_78 += sprite->speed << 13;
        }
        break;
    case 2:
        sprite->state++;
        (D_03004C44 + sprite->link)->visible = 1;
        sprite->field_78 += sprite->speed << 13;
        break;
    case 3:
        if (sprite->timer == 5)
        {
            sprite->state++;
            sprite->speed = 0xFFC0;
            sprite->timer = 0;
        }
        sprite->timer++;
        break;
    case 4:
        if (sprite->timer == 10)
        {
            sprite->state++;
            sprite->timer = 0;
            func_080440D8(5);
            if (sprite->sound)
                func_080019EC(sprite->sound);
        }
        sprite->timer++;
        sprite->speed += 2;
        sprite->field_78 += sprite->speed << 13;
        break;
    case 5:
        sprite->visible = 0;
        sprite->field_64 = 0;
        break;
    }
    D_0200E288 = sprite->field_78;
    D_0200E284 = sprite->field_7C;
}
