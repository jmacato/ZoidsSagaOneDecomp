#include "types.h"

struct Graphic
{
    u8 pad_0[8];
    void *first;
    void *second;
};

struct Task
{
    u16 flags;
    u8 pad_2[4];
    u16 field_6;
    s32 x;
    s32 y;
    u8 pad_10[4];
    void *first;
    void *second;
    u16 tile;
    u8 pad_1E[0x6A];
};

extern struct Graphic D_0866B7F8[];

void func_0805EDC0(void *, s32, u32);
void func_08001834(u16 *, u8);
void func_08000CEC(u8, struct Task *, s32);

void func_080322F0(u8 id, u8 slot, u16 tile, u8 palette, s32 x, s32 y)
{
    struct Task task;
    struct Task *pointer = &task;

    func_0805EDC0(&task, 0, 0x88);
    pointer->flags = 0x8000;
    pointer->field_6 = 0x800;
    task.first = D_0866B7F8[id].first;
    task.second = D_0866B7F8[id].second;
    task.x = x;
    task.y = y;
    task.tile = tile;
    func_08001834(&task.field_6, palette);
    task.flags |= 0x1C02;
    func_08000CEC(slot, &task, 0);
}
