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
    s32 base_y;
    u8 pad_84[4];
};

extern struct Obj D_03004C44[];

u8 func_08049B50(struct Obj *);
u8 func_08049B70(struct Obj *);
void func_080440D8(u8);
void func_080019EC(u16);
void func_08049B14(struct Obj *, s32);
void func_08049AB8(struct Obj *, s32, s32);
u16 func_08042FA4(u8);

void func_0804AD34(struct Obj *obj)
{
    u32 x;
    u32 bits;

    if (obj->active && func_08049B50(obj))
    {
        if (func_08049B70(obj))
        {
            obj->flags |= 0x8000;
            obj->state = 1;
            obj->field_56 = 0;
            obj->base_y = obj->y;
            if (obj->effect)
                func_080440D8(obj->effect);
            if (obj->sound)
                func_080019EC(obj->sound);
        }
        if ((obj->timer >> 1) >= obj->range)
            func_08049B14(&D_03004C44[obj->target], 0);
        if (obj->flags & 4)
        {
            obj->active = 0;
            obj->field_64 = 0;
        }
        else
        {
            bits = obj->motion >> 5;
            if ((u8)bits & 0x10)
                x = ((bits & 0xF) << 16) | 0xFFF00000;
            else
                x = (bits & 0x1F) << 16;
            func_08049AB8(obj, x, 0);
            obj->y = obj->base_y + ((u32)(func_08042FA4((u8)obj->field_56 + 0x80) << 16) >> 3);
        }
    }
}
