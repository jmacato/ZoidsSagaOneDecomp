#include "types.h"

struct Map
{
    const void *palette;
    const void *tiles;
    const void *layout;
    const void *collision;
    const void *objects;
    u16 width;
    u8 pad_16[2];
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

s32 func_08007D04(void)
{
    u32 offset = 0x800;
    u16 width;
    u16 map = D_0200000C.map;
    u16 x0 = D_0200000C.x;
    u16 y0 = D_0200000C.y;
    const struct Map *table = D_081E6F94;
    const struct Map *entry = &table[map];
    u16 *layout;
    u16 x;
    u16 y;

    func_0805D288(entry->palette, (void *)0x05000000);
    func_08001D04(1);
    func_0805D288(D_081E6F94[map].tiles, (void *)0x06008000);
    func_08001D04(1);
    func_0805D28C(D_081E6F94[map].layout, D_0200E8A4);
    func_08001D04(1);
    func_0805D28C(D_081E6F94[map].collision, D_02018E44);
    func_08001D04(1);
    D_03004B9C.x = x0 << 19;
    D_03004B9C.y = y0 << 19;
    layout = D_0200000C.layout;
    width = entry->width;
    for (y = y0; y != (u16)(y0 + 20); y++)
    {
        for (x = x0; x != (u16)(x0 + 30); x++)
            D_0300239C[((y & 31) << 5) + (x & 31) + offset] = layout[y * width + x];
    }
    func_08001150(D_081E6F94[map].objects, 0x20, 0x20, 0x20, 0, 0x60, 0);
    func_080019D8();
}
