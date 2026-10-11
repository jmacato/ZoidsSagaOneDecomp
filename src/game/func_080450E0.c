#include "types.h"

struct Graphic
{
    u32 *tiles;
    void *palette;
    void *first;
    void *second;
};

struct Transfer
{
    void *source;
    void *destination;
    u32 size;
};

struct Task
{
    u16 flags;
    u8 pad_2[4];
    u16 attributes;
    s32 x;
    s32 y;
    u8 pad_10[4];
    void *first;
    void *second;
    u16 tile;
    u8 pad_1E[0x24];
    u16 field_42;
    u8 pad_44[0x44];
};

extern struct Graphic D_086F7FA0;
extern u16 D_0200DA74;

void func_0805EDC0(void *, s32, u32);
void func_08001A54(struct Transfer *, s32, s32);
void func_08000CEC(s32, struct Task *, s32);

void func_080450E0(u16 x, u16 y)
{
    struct Transfer transfer;
    struct Task task;
    struct Task *pointer = &task;
    u16 tile;
    u16 end;

    func_0805EDC0(pointer, 0, 0x88);
    pointer->flags = 0x1000;
    pointer->attributes = 0xA800;
    tile = D_0200DA74;
    transfer.source = D_086F7FA0.tiles;
    transfer.destination = (void *)(0x06010000 + tile * 32);
    func_08001A54(&transfer, 0, 1);
    end = (*D_086F7FA0.tiles >> 13) + D_0200DA74;
    transfer.source = D_086F7FA0.palette;
    transfer.destination = (void *)0x05000340;
    func_08001A54(&transfer, 0, 1);
    pointer->x = x << 16;
    pointer->y = y << 16;
    task.field_42 = 1;
    pointer->first = D_086F7FA0.first;
    pointer->second = D_086F7FA0.second;
    pointer->tile = tile;
    if (end > D_0200DA74)
        D_0200DA74 = end;
    func_08000CEC(0x17, pointer, 0);
}
