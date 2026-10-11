#include "types.h"

struct Entry
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
    u8 pad_2[6];
    u32 x;
    u32 y;
    u8 pad_10[4];
    void *first;
    void *second;
    u8 pad_1C[0x6C];
};

extern struct Entry D_0867006C[];

void func_0805EDC0(void *, s32, u32);
void func_0805D270(void *, void *, u32);
void func_08000CEC(s32, struct Task *, s32);

void region_0804D654(u32 incoming_index, u32 incoming_x, u32 incoming_y)
{
    u16 index = (u16)incoming_index;
    u16 x = (u16)incoming_x;
    u16 y = (u16)incoming_y;
    struct Task task;
    struct Task *pointer = &task;
    struct Entry *entry;
    struct Entry *table;

    func_0805EDC0(&task, 0, 0x88);
    pointer->flags = 0x8000;
    table = D_0867006C;
    entry = &table[index];
    func_0805D270(entry->palette, (void *)0x05000200, 0x10);
    func_0805D270(entry->tiles, (void *)0x06010000, 0x400);
    task.first = entry->first;
    task.second = entry->second;
    task.x = x << 16;
    task.y = y << 16;
    func_08000CEC(1, &task, 0);
}
