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
    union
    {
        s32 x;
        u16 timer;
    } u;
    s32 y;
};

extern struct Sprite D_03004BBC[];

void func_08032164(s32, u8, s32, s32);

void func_0802DBE4(void *unused, struct Task *task)
{
    struct Obj *obj = task->obj;
    struct Sprite *sprite = obj->sprite;

    switch (task->state)
    {
    case 0:
        task->u.x = (double)sprite->x + 524288.0;
        task->y = (double)sprite->y - 1048576.0;
        func_08032164(1, obj->index, task->u.x, task->y);
        task->u.timer = 0x18;
        task->state = 100;
        break;
    case 100:
        if (--task->u.timer == 0)
        {
            sprite->flags &= 0x7FFF;
            task->state = 200;
        }
        break;
    case 200:
    {
        struct Sprite *base = D_03004BBC;
        struct Sprite *target = &base[obj->index];

        if (target->flags & 4)
        {
            target->flags &= 0x7FFF;
            task->done = 1;
            task->state = 910;
        }
        break;
    }
    }
}
