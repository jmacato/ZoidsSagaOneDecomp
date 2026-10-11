#include "types.h"

struct Obj
{
    u16 flags;
    u8 pad_2[6];
    s32 x;
    s32 y;
    u8 pad_10[0x24];
    u16 timer;
    u8 pad_36[0x16];
    u16 active;
    u16 target;
    u16 state;
    u16 range;
    u16 motion;
    u16 field_56;
    u8 pad_58[0xC];
    u16 field_64;
    u8 pad_66[4];
    u16 effect;
    u16 sound;
    u8 pad_6E[0xA];
    s32 home_x;
    s32 home_y;
    u8 pad_80[8];
};

extern struct Obj D_03004C44[];

u8 func_08049B50(struct Obj *);
u8 func_08049B70(struct Obj *);
void func_080440D8(u8);
void func_080019EC(u16);
void func_08049B14(struct Obj *, s32);
void func_08049AB8(struct Obj *, s32, s32);

void func_0804AB48(struct Obj *obj)
{
    s32 x;
    s32 y;

    if (obj->active && func_08049B50(obj))
    {
        if (func_08049B70(obj))
        {
            obj->flags |= 0x8000;
            obj->state = 1;
            obj->field_56 = 0;
            if (obj->effect)
                func_080440D8(obj->effect);
            if (obj->sound)
                func_080019EC(obj->sound);
        }
        if ((obj->timer >> 1) >= obj->range)
            func_08049B14(&D_03004C44[obj->target], 0);
        if (obj->flags & 4)
        {
            obj->flags &= 0x7FFF;
            obj->active = 0;
            obj->field_64 = 0;
        }
        else
        {
            vu16 *motion = &obj->motion;

            x = *motion >> 5;
            if ((u8)x & 0x10)
            {
                x &= 0xF;
                x <<= 14;
                x |= 0xFFFC0000;
            }
            else
            {
                x &= 0x1F;
                x <<= 14;
            }
            if (*motion & 0x10)
            {
                u32 m = *motion;

                y = (((u8)m & 0xF) << 14) | 0xFFFC0000;
            }
            else
            {
                u32 m = *motion;

                y = ((u8)m & 0x1F) << 14;
            }
            func_08049AB8(obj, x, y);
        }
    }
}
