#include "types.h"

struct Map
{
    const void *palette;
    const void *tiles;
    const void *layout;
    const void *collision;
    const void *objects;
    u16 width;
    u16 height;
};

extern struct
{
    u8 pad_0[4];
    u16 map;
    u8 pad_6[2];
    u16 *layout;
    u8 pad_C[4];
    u16 x;
    u16 y;
    u8 pad_14[4];
    u16 scale;
} D_0200000C;

extern struct
{
    u8 pad_0[0x10];
    u32 x;
    u32 y;
} D_03004B9C;

extern const struct Map D_081E6F94[];
extern u16 D_0300239C[];
extern u8 D_0200E8A4[];
extern u8 D_02018E44[];

void func_0805D288(const void *, void *);
void func_0805D28C(const void *, void *);
void func_08001D04(s32);
void func_08001150(const void *, s32, s32, s32, s32, s32, s32);
void func_080019D8(void);

s32 func_08007E4C(s32 x, s32 y)
{
    u32 offset = 0x800;
    u16 width;
    u16 map = D_0200000C.map;
    s32 margin;
    s32 pos;
    s32 py;
    u16 x0;
    u16 y0;
    const struct Map *table;
    const struct Map *entry;
    u16 *layout;
    u16 i;
    u16 j;

    if (D_0200000C.scale == 4)
        margin = 13;
    else
        margin = 14;
    pos = D_0200000C.scale * x - margin;
    x0 = !(pos & 0x8000) ? (pos <= D_081E6F94[map].width - 0x1F ? (u16)pos : (u16)(D_081E6F94[map].width - 0x1E)) : 0;
    py = D_0200000C.scale * y - 8;
    if (!(py & 0x8000))
    {
        if (py <= D_081E6F94[map].height - 0x15)
            y0 = py;
        else
            y0 = D_081E6F94[map].height - 0x14;
    }
    else
        y0 = 0;
    table = D_081E6F94;
    entry = &table[map];
    func_0805D288(entry->palette, (void *)0x05000000);
    func_08001D04(1);
    func_0805D288(D_081E6F94[map].tiles, (void *)0x06008000);
    func_08001D04(1);
    func_0805D28C(D_081E6F94[map].layout, D_0200E8A4);
    func_08001D04(1);
    func_0805D28C(D_081E6F94[map].collision, D_02018E44);
    func_08001D04(1);
    D_0200000C.x = x0;
    D_0200000C.y = y0;
    D_03004B9C.x = x0 << 19;
    D_03004B9C.y = y0 << 19;
    layout = D_0200000C.layout;
    width = entry->width;
    for (j = y0; j != (u16)(y0 + 20); j++)
    {
        for (i = x0; i != (u16)(x0 + 30); i++)
            D_0300239C[((j & 31) << 5) + (i & 31) + offset] = layout[j * width + i];
    }
    func_08001150(D_081E6F94[map].objects, 0x20, 0x20, 0x20, 0, 0x60, 0);
    func_080019D8();
}
