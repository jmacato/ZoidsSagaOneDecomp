#include "types.h"

struct Sprite
{
    u8 pad_0[0x4C];
    u16 visible;
    u16 parent;
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
    u32 y;
    u32 field_7C;
    u8 pad_80[8];
};

extern struct Sprite D_03004BBC[];
extern u32 D_0200E288;
extern u32 D_0200E284;

void func_080440D8(s32);
void func_080019EC(u16);

void func_0804A120(struct Sprite *spr)
{
    switch (spr->state)
    {
    case 0:
        spr->timer = 0;
        spr->speed = 0x24;
        spr->field_5A = 0;
        spr->y = D_0200E288;
        spr->field_7C = 0;
        spr->state++;
        spr->y += spr->speed << 13;
        break;
    case 1:
        if (spr->speed == 0)
        {
            register u16 *state asm("r0") = &spr->state;
            register u32 next_state asm("r1") = *state + 1;

            asm("" : : "r"(state), "r"(next_state));
            *state = next_state;
            state = (u16 *)((u32)state + 2);
            asm("" : : "r"(state));
            *state = 0;
            spr->speed = 0;
        }
        else
        {
            spr->timer++;
            spr->speed -= 2;
            spr->y += spr->speed << 13;
        }
        break;
    case 2:
        spr->state++;
        (&D_03004BBC[1])[spr->parent].visible = 1;
        spr->y += spr->speed << 13;
        break;
    case 3:
        if (spr->timer == 5)
        {
            spr->state++;
            spr->speed = 0xFFC0;
            spr->timer = 0;
        }
        spr->timer++;
        break;
    case 4:
        if (spr->timer == 10)
        {
            spr->state++;
            spr->timer = 0;
            func_080440D8(1);
            if (spr->sound)
                func_080019EC(spr->sound);
        }
        spr->timer++;
        spr->speed += 2;
        spr->y += spr->speed << 13;
        break;
    case 5:
        if (spr->timer == 10)
        {
            spr->state++;
            spr->timer = 0;
        }
        spr->timer++;
        break;
    case 6:
    case 7:
        spr->state++;
        break;
    case 8:
        spr->visible = 0;
        spr->field_64 = 0;
        break;
    }
    D_0200E288 = spr->y;
    D_0200E284 = spr->field_7C;
}
