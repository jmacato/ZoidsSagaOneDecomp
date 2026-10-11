#include "types.h"

struct Actor
{
    u16 flags;
    u8 pad_2[6];
    s32 x;
    s32 y;
    u8 pad_10[0x24];
    u16 field_34;
    u8 pad_36[0x16];
    u16 field_4C;
    u16 field_4E;
    u16 field_50;
    u16 field_52;
    u16 field_54;
    u16 field_56;
    u16 field_58;
    u16 field_5A;
    u16 field_5C;
    u16 field_5E;
    u16 field_60;
    u16 field_62;
    u16 field_64;
    u16 field_66;
    u16 field_68;
    u16 field_6A;
    u16 field_6C;
    u8 pad_6E[0xA];
    s32 field_78;
    s32 field_7C;
    s32 field_80;
};

struct Sprite
{
    u16 flags;
    u8 pad_2[0x4A];
    u16 field_4C;
    u8 pad_4E[0x16];
    u16 field_64;
    u8 pad_66[0x22];
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

void func_0804B770(struct Actor *actor)
{
    if (actor->field_52 == 0)
        actor->field_64 = 0;
    if (actor->field_4C != 0 && func_08049B50(actor))
    {
        if (func_08049B70(actor))
        {
            actor->flags |= 0x8000;
            actor->field_50 = 1;
            actor->x = actor->field_78;
            actor->y = actor->field_7C;
            func_08049A74(actor, 0xF00000, 0);
            actor->field_56 = 0;
            if (actor->field_6A != 0)
                func_080440D8(actor->field_6A);
            if (actor->field_6C != 0)
                func_080019EC(actor->field_6C);
        }
        else
        {
            if (actor->field_56 > 0xF0 - (actor->field_54 >> 8))
            {
                func_08049B14(&D_03004BBC[(actor->field_54 & 0xFF) + D_0200DA97], 3);
                D_03004BBC[(actor->field_54 & 0xFF) + D_0200DA97].field_64 = 0;
                actor->flags &= 0x7FFF;
                actor->field_50 = 0;
                actor->field_4C = 0;
                if (actor->field_52 != 0)
                    actor->field_52--;
            }
            else
            {
                func_08049A74(actor, 0xFFE80000, 0);
            }
        }
    }
}
