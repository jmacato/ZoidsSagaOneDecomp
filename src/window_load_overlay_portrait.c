#include "text.h"

struct Portrait
{
    void *tiles;
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
    u8 pad_8[0xC];
    void *first;
    void *second;
    u16 tile;
    u8 pad_1E[0x6A];
};

extern struct Portrait D_086D08C0[];

void func_0805EDC0(void *, s32, u32);
void func_08001A54(struct Transfer *, s32, s32);
void func_08000CEC(s32, struct Task *, s32);

void window_load_overlay_portrait(u16 portrait, u8 expression)
{
    struct Transfer transfer;
    struct Task task;
    struct Task *pointer = &task;
    u16 mask;
    u16 index;

    func_0805EDC0(&task, 0, 0x88);
    pointer->flags = 0x1000;
    mask = 0xF000;
    pointer->attributes = mask;
    index = portrait * 9 + expression;
    transfer.source = D_086D08C0[index].tiles;
    transfer.destination = (void *)0x06017B80;
    func_08001A54(&transfer, 0, 1);
    transfer.source = D_086D08C0[index].palette;
    transfer.destination = (void *)0x050003E0;
    func_08001A54(&transfer, 0, 1);
    pointer->attributes |= mask;
    pointer->first = D_086D08C0[index].first;
    pointer->second = D_086D08C0[index].second;
    pointer->tile = 0x3DC;
    func_08000CEC(0, &task, 0);
}
