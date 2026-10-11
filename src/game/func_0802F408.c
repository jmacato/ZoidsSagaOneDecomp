#include "types.h"

struct Obj
{
    u8 pad_0[8];
    s32 x;
    s32 y;
};

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    struct Obj *obj;
    s32 target_x;
    s32 target_y;
    u8 pad_14[4];
    s32 done;
    u8 pad_1C[0x10];
    s32 dx;
    union
    {
        s32 dy;
        u8 count;
    } u;
};

void func_0802F408(void *unused, struct Task *task)
{
    struct Obj *obj = task->obj;

    switch (task->state)
    {
    case 0:
        task->dx = task->target_x - obj->x;
        task->dx /= 15;
        task->u.dy = task->target_y - obj->y;
        task->u.dy /= 15;
        task->u.count = 0;
        task->state = 100;
    case 100:
        obj->x += task->dx;
        obj->y += task->u.dy;
        if (++task->u.count > 14)
        {
            obj->x = task->target_x;
            obj->y = task->target_y;
            task->done = 1;
            task->state = 200;
        }
        break;
    case 200:
        break;
    }
}
