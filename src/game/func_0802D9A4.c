#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[6];
    s32 x;
    s32 y;
    u8 pad_10[0x78];
};

struct Obj
{
    u8 pad_0[0xC8];
    struct Sprite *sprite;
    u8 index;
};

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    struct Obj *obj;
    u8 pad_C[0xC];
    s32 done;
    u8 pad_1C[0x10];
    s32 base;
    s32 count;
    s32 x;
    s32 y;
};

extern struct Sprite D_03004BBC[];

void func_08032164(s32, u8, s32, s32);

void func_0802D9A4(void *unused, struct Task *task)
{
    struct Obj *obj = task->obj;
    struct Sprite *sprite = obj->sprite;

    switch (task->state)
    {
    case 0:
        task->base = sprite->x;
        task->count = 0;
        task->state = 100;
        task->x = (double)sprite->x + 524288.0;
        task->y = (double)sprite->y - 1048576.0;
        func_08032164(0, obj->index, task->x, task->y);
    case 100:
        sprite->x = (u32)((double)task->base - 131072.0);
        task->state = 110;
        break;
    case 110:
        sprite->x = task->base;
        task->state = 120;
        break;
    case 120:
        sprite->x = (u32)((double)task->base + 131072.0);
        task->state = 130;
        break;
    case 130:
        sprite->x = task->base;
        task->state = 100;
        if (++task->count > 2)
            task->state = 200;
        break;
    case 200:
        if (D_03004BBC[obj->index].flags & 4)
            task->state = 900;
        break;
    case 900:
        D_03004BBC[obj->index].flags &= 0x7FFF;
        task->done = 1;
        task->state = 910;
        break;
    }
}
