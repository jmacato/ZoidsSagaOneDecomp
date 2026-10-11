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
    u16 field_56;
    u8 pad_58[8];
    u16 field_60;
    u8 pad_62[2];
    u16 field_64;
    u8 pad_66[4];
    u16 field_6A;
    u16 field_6C;
};

struct Sprite
{
    u8 pad_0[0x88];
};

extern struct Sprite D_03004BBC[];
extern struct Sprite D_03004C44[];
extern u8 D_0200DA97;

u8 func_08049B50(struct Actor *);
u8 func_08049B70(struct Actor *);
void func_080440D8(u8);
void func_080019EC(u16);
void func_08049B14(struct Sprite *, s32);
void func_08049A5C(struct Actor *);

void func_08000BD8(u16, u16);
void func_08049A74(struct Actor *, s32, s32);

void func_0804A388(struct Actor *actor)
{
    if (actor->field_4C != 0 && func_08049B50(actor))
    {
        if (func_08049B70(actor))
        {
            actor->flags |= 0x8000;
            actor->field_50 = 1;
            actor->field_56 = 0;
            if (actor->field_6A != 0)
                func_080440D8(actor->field_6A);
            if (actor->field_6C != 0)
                func_080019EC(actor->field_6C);
        }
        else
        {
            if (actor->field_56 >= actor->field_54 >> 10)
            {
                actor->flags &= 0x7FFF;
                actor->field_4C = 0;
                actor->field_64 = 0;
            }
            else
            {
                s32 dy;

                if (!(actor->field_54 & 0x10))
                    dy = ~((actor->field_54 & 0xF) << 16) + 1;
                else
                    dy = (actor->field_54 & 0xF) << 16;
                func_08049A74(actor, ((actor->field_54 >> 5) & 0x1F) << 16, dy);
            }
            actor->field_56++;
        }
    }
}
