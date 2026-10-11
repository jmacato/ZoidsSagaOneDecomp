#include "types.h"

struct Info
{
    u8 pad_0[0x30];
    void *tiles;
    void *palette;
    void *first;
    void *second;
    u8 pad_40[0xC];
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

extern struct Info D_0867006C[];

void func_0805EDC0(void *, s32, u32);
void func_0805D270(void *, void *, u32);
void func_08001834(u16 *, u8);
void func_08000CEC(u16, struct Task *, s32);

void func_0803193C(u16 id, u8 palette, u16 tile, u16 slot, s32 x, s32 y)
{
    struct Task task;
    struct Task *pointer = &task;

    func_0805EDC0(&task, 0, 0x88);
    pointer->flags = 0x8000;
    pointer->field_6 = 0x800;
    func_0805D270(D_0867006C[id].palette, (void *)(0x05000200 + palette * 32), 0x10);
    func_0805D270(D_0867006C[id].tiles, (void *)(0x06010000 + tile * 32), 0x400);
    task.first = D_0867006C[id].first;
    task.second = D_0867006C[id].second;
    task.x = x;
    task.y = y;
    task.tile = tile;
    func_08001834(&task.field_6, palette);
    task.flags |= 0x1002;
    func_08000CEC(slot, &task, 0);
}
