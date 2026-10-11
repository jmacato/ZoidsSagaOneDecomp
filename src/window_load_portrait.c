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
    u32 x;
    u32 y;
    u8 pad_10[4];
    void *first;
    void *second;
    u16 tile;
    u8 pad_1E[0x6A];
};

extern struct Portrait D_086D08C0[];
extern u8 D_084506B4[];
extern u8 D_084506C0[];
extern u8 D_08450700[];
extern u8 D_0845070C[];

void func_0805EDC0(void *, s32, u32);
void func_08001A54(struct Transfer *, s32, s32);
void func_08000CEC(s32, struct Task *, s32);

void window_load_portrait(u8 window, u16 portrait, u8 expression)
{
    struct Transfer transfer;
    struct Task task;
    struct Task *pointer = &task;
    u16 index;

    func_0805EDC0(pointer, 0, 0x88);
    pointer->flags = 0x1000;
    pointer->attributes = 0xF000;
    index = portrait * 9 + expression;
    transfer.source = D_086D08C0[index].tiles;
    transfer.destination = font_glyph_buffer;
    if (transfer.source)
    {
        func_08001A54(&transfer, 0, 1);
        transfer.source = D_086D08C0[index].palette;
        transfer.destination = font_glyph_buffer + 0x480;
        func_08001A54(&transfer, 0, 1);
        pointer->first = D_086D08C0[index].first;
        pointer->second = D_086D08C0[index].second;
    }
    else
    {
        transfer.source = D_084506B4;
        func_08001A54(&transfer, 0, 1);
        transfer.source = D_084506C0;
        transfer.destination = font_glyph_buffer + 0x480;
        func_08001A54(&transfer, 0, 1);
        pointer->first = D_0845070C;
        pointer->second = D_08450700;
    }
    pointer->attributes |= 0xF000;
    if (text_windows[window].palette & 4)
    {
        pointer->x = text_windows[window].x << 19;
        pointer->y = text_windows[window].y << 19;
    }
    else if (text_windows[window].style & 4)
    {
        pointer->x = text_windows[window].x << 19;
        pointer->y = text_windows[window].y << 19;
    }
    else
    {
        pointer->x = (text_windows[window].x + 1) << 19;
        pointer->y = (text_windows[window].y + 1) << 19;
    }
    pointer->tile = 0x3DC;
    func_08000CEC(0, pointer, 0);
}
