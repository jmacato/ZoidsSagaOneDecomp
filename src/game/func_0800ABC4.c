#include "types.h"

struct Sprite
{
    u8 pad_0[0x4E];
    u16 tile_x;
    u16 tile_y;
    u8 pad_52[4];
    u16 field_56;
    u8 pad_58[8];
    u16 wait;
    u8 pad_62[2];
    u16 object;
    u16 route;
    u16 step;
    u16 target_x;
    u16 target_y;
    u8 pad_6E[0x1A];
};

struct Point
{
    u16 x;
    u16 y;
};

struct Object
{
    u8 pad_0[8];
    u16 route;
    u8 wait;
    u8 step;
    u8 target_x;
    u8 target_y;
    u8 pad_E[2];
};

extern struct Sprite D_03004BBC[];
extern struct Point *D_08320258[];

extern struct
{
    u8 pad_0[0x50];
    struct Object objects[1];
} D_02000B5C;

void func_0800A5E4(u16, s32, s32, u16, u16);

void func_0800ABC4(u16 sprite)
{
    struct Sprite *sprites = D_03004BBC;
    struct Sprite *spr = &sprites[sprite];
    struct Point *route;

    spr->field_56 = 0;
    route = D_08320258[spr->route];
    if (spr->target_x == 0xFFFF)
    {
        if (spr->target_y == 0xFFFF)
        {
            spr->step = 0;
            spr->target_x = route[spr->step].x;
            spr->target_y = route[spr->step].y;
            if (spr->object != 0xFFFF)
            {
                D_02000B5C.objects[spr->object].wait = spr->wait;
                D_02000B5C.objects[spr->object].route = spr->route;
                D_02000B5C.objects[spr->object].step = spr->step;
                D_02000B5C.objects[spr->object].target_x = spr->target_x;
                D_02000B5C.objects[spr->object].target_y = spr->target_y;
            }
        }
        else
        {
            spr->wait = route[spr->step].y;
            if (spr->object != 0xFFFF)
            {
                D_02000B5C.objects[spr->object].wait = spr->wait;
                D_02000B5C.objects[spr->object].route = spr->route;
                D_02000B5C.objects[spr->object].step = spr->step;
                D_02000B5C.objects[spr->object].target_x = spr->target_x;
                D_02000B5C.objects[spr->object].target_y = spr->target_y;
            }
        }
    }
    else if (spr->target_x == 0xFFFE)
    {
        if (spr->target_y)
        {
            spr->target_y--;
            if (spr->object != 0xFFFF)
            {
                D_02000B5C.objects[spr->object].wait = spr->wait;
                D_02000B5C.objects[spr->object].route = spr->route;
                D_02000B5C.objects[spr->object].step = spr->step;
                D_02000B5C.objects[spr->object].target_x = spr->target_x;
                D_02000B5C.objects[spr->object].target_y = spr->target_y;
            }
        }
        else
        {
            spr->step++;
            spr->target_x = route[spr->step].x;
            spr->target_y = route[spr->step].y;
            if (spr->object != 0xFFFF)
            {
                D_02000B5C.objects[spr->object].wait = spr->wait;
                D_02000B5C.objects[spr->object].route = spr->route;
                D_02000B5C.objects[spr->object].step = spr->step;
                D_02000B5C.objects[spr->object].target_x = spr->target_x;
                D_02000B5C.objects[spr->object].target_y = spr->target_y;
            }
        }
    }
    else if (spr->target_x == spr->tile_x && spr->target_y == spr->tile_y)
    {
        spr->step++;
        spr->target_x = route[spr->step].x;
        spr->target_y = route[spr->step].y;
        if (spr->object != 0xFFFF)
        {
            D_02000B5C.objects[spr->object].wait = spr->wait;
            D_02000B5C.objects[spr->object].route = spr->route;
            D_02000B5C.objects[spr->object].step = spr->step;
            D_02000B5C.objects[spr->object].target_x = spr->target_x;
            D_02000B5C.objects[spr->object].target_y = spr->target_y;
        }
    }
    else
        func_0800A5E4(sprite, 0x40, 0, D_03004BBC[sprite].target_x, D_03004BBC[sprite].target_y);
}
