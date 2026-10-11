#include "types.h"

struct Data
{
    u8 pad_0[8];
    u32 x;
    u32 y;
};

struct Unit
{
    u8 pad_0[0xE];
    u16 kind;
    u8 pad_10[0xB8];
    struct Data *data;
    u8 sprite;
};

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    struct Unit *unit;
    u32 side;
    u32 slot;
    u8 pad_14[4];
    u32 busy;
    u8 pad_1C[0x10];
    u8 level;
};

struct Kind
{
    u8 pad_0[0x34];
    const void *palette;
    u8 pad_38[0x14];
};

struct Def
{
    u8 palette;
    u8 pad_1[0xF];
};

struct Sprite
{
    u16 flags;
    u8 pad_2[0x86];
};

extern const struct Kind D_0867006C[];
extern const struct Def D_0866B2E0[2][6];
extern struct Sprite D_03004BBC[];

void func_08032164(s32, u8, u32, u32);
void func_0805D270(const void *, void *, u32);
void func_08031E90(u8 *, u8, u8);

void func_0802CBBC(u32 unused, struct Task *task)
{
    u8 palette[32];
    struct Unit *unit = task->unit;
    struct Data *data = unit->data;

    switch (task->state)
    {
    case 0:
        func_08032164(4, unit->sprite, data->x, data->y);
        task->level = 8;
        task->state = 100;
    case 100:
        func_0805D270(D_0867006C[unit->kind].palette, palette, 0x10);
        func_08031E90(palette, task->level, 6);
        func_08031E90(palette, task->level, 5);
        func_0805D270(palette, (void *)(0x05000200 + D_0866B2E0[task->side][task->slot].palette * 32), 0x10);
        task->level += 2;
        if (task->level > 31)
            task->state = 200;
        break;
    case 200:
        task->level -= 2;
        func_0805D270(D_0867006C[unit->kind].palette, palette, 0x10);
        func_08031E90(palette, task->level, 6);
        func_08031E90(palette, task->level, 5);
        func_0805D270(palette, (void *)(0x05000200 + D_0866B2E0[task->side][task->slot].palette * 32), 0x10);
        if (task->level == 0)
            task->state = 9000;
        break;
    case 9000:
        if (D_03004BBC[unit->sprite].flags & 4)
        {
            D_03004BBC[unit->sprite].flags &= 0x7FFF;
            task->state = 0x238C;
        }
        break;
    case 0x238C:
        task->busy = 1;
        break;
    }
}
