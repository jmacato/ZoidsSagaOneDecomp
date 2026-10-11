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
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[4];
    u16 kind;
    u8 pad_10[0xB8];
    struct Sprite *sprite;
    u8 index;
};

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    struct Obj *obj;
    u32 side;
    u32 slot;
    u8 pad_14[4];
    s32 done;
    u8 pad_1C[0x10];
    u8 level;
};

struct Info
{
    u8 pad_0[0x34];
    void *palette;
    u8 pad_38[0x14];
};

struct Place
{
    u8 palette;
    u8 pad_1[0xF];
};

extern struct Sprite D_03004BBC[];
extern struct Info D_0867006C[];
extern const struct Place D_0866B2E0[][6];

void func_08032164(s32, u8, s32, s32);
void func_0805D270(const void *, void *, u32);
void func_08031E90(u16 *, u8, s32);

void func_0802DAF4(void *unused, struct Task *task)
{
    struct Obj *obj = task->obj;
    struct Sprite *sprite = obj->sprite;
    u16 buffer[16];

    switch (task->state)
    {
    case 0:
        task->level = 2;
        task->state = 100;
        func_08032164(6, obj->index, sprite->x, sprite->y);
    case 100:
        func_0805D270(D_0867006C[obj->kind].palette, buffer, 0x10);
        func_08031E90(buffer, task->level, 0x1D);
        func_0805D270(buffer, (void *)(0x05000200 + D_0866B2E0[task->side][task->slot].palette * 32), 0x10);
        task->level += 2;
        if (task->level > 0x17)
            task->state = 200;
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
            obj->flags |= 0x4000;
        }
        break;
    }
    }
}
