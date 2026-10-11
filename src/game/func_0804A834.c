#include "types.h"

struct Obj
{
    u16 flags;
    u8 pad_2[0x32];
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
    u8 pad_6E[0x1A];
};

extern struct Obj D_03004C44[];

u8 func_08049B50(struct Obj *);
u8 func_08049B70(struct Obj *);
void func_080440D8(u8);
void func_080019EC(u16);
void func_08049B14(struct Obj *, s32);
void func_08049A74(struct Obj *, s32, s32);

void func_0804A834(struct Obj *obj)
{
    s32 dx;
    s32 dy;

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
            if (obj->motion & 0x200)
                dx = (((obj->motion >> 5) & 0xF) << 16) | 0xFFF00000;
            else
                dx = ((obj->motion >> 5) & 0xF) << 16;
            if (obj->motion & 0x10)
            {
                u32 m = ((volatile struct Obj *)obj)->motion;

                dy = (((u8)m & 0xF) << 16) | 0xFFF00000;
            }
            else
                dy = (obj->motion & 0xF) << 16;
            func_08049A74(obj, dx, dy);
        }
    }
}
