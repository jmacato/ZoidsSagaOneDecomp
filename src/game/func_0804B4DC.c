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
};

struct Sprite
{
    u16 flags;
    u8 pad_2[0x4A];
    u16 field_4C;
    u8 pad_4E[0x3A];
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
void func_08049AB8(struct Actor *, s32, s32);

void func_0804B4DC(struct Actor *actor)
{
    if (actor->field_4C != 0 && func_08049B50(actor))
    {
        if (func_08049B70(actor))
        {
            actor->flags |= 0x8000;
            actor->field_50 = 1;
            actor->field_56 = 0;
            func_08000BD8(actor->field_4E, actor->field_60);
            actor->flags &= 0xF7FF;
            if (actor->field_6A != 0)
                func_080440D8(actor->field_6A);
            if (actor->field_6C != 0)
                func_080019EC(actor->field_6C);
        }
        if (actor->field_56 >= actor->field_52)
        {
            if (actor->field_50 != 2)
            {
                func_08049B14(&D_03004BBC[((actor->field_54 >> 10) & 0x1F) + D_0200DA97], 3);
                actor->flags |= 0x800;
                actor->field_50 = 2;
            }
            if (actor->flags & 4)
            {
                actor->flags &= 0x7FFF;
                actor->field_50 = 0;
                actor->field_4C = 0;
                actor->field_64 = 0;
            }
        }
        else
        {
            vu16 *field = &actor->field_54;
            u32 dx = *field >> 5;
            s32 dy;

            if ((u8)dx & 0x10)
            {
                dx &= 0xF;
                dx <<= 14;
                dx |= 0xFFFC0000;
            }
            else
            {
                dx &= 0x1F;
                dx <<= 14;
            }
            if (*field & 0x10)
            {
                u32 m = *field;

                dy = (((u8)m & 0xF) << 14) | 0xFFFC0000;
            }
            else
            {
                u32 m = *field;

                dy = ((u8)m & 0x1F) << 14;
            }
            func_08049AB8(actor, dx, dy);
        }
    }
}
