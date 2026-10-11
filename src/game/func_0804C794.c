#include "types.h"

struct Sprite
{
    u16 flags;
    u16 flags2;
    u8 pad_4[2];
    u16 attr;
    u32 x;
    u32 y;
    u8 pad_10[4];
    u32 frames;
    u32 anims;
    u16 tile;
    u8 pad_1E[0x5A];
    u32 base_x;
    u32 base_y;
    u8 pad_80[8];
};

struct Load
{
    const void *src;
    void *dst;
    u32 pad;
};

struct Def
{
    const u32 *tiles;
    const void *palette;
    u32 frames;
    u32 anims;
};

extern struct Sprite D_03004BBC[];
extern struct Def D_086F7FD0[];
extern u16 D_0200DA74;

void func_0805EDC0(void *, s32, u32);
void func_08001A54(const void *, s32, s32);
void func_08000CEC(u8, struct Sprite *, u16);

void func_0804C794(u8 task, s32 unused, u8 kind, u16 x, u16 y, u16 layer, s32 mode)
{
    struct Load load;
    struct Sprite spr;
    u16 tile;
    u16 end;

    func_0805EDC0(&spr, 0, 0x88);
    tile = D_0200DA74;
    if (mode < 0)
    {
        struct Sprite *sprites = D_03004BBC;
        u32 index = (u32)(mode & 0x7C000000) >> 26;

        end = tile = sprites[index].tile;
        spr.attr = sprites[index].attr;
        spr.attr |= sprites[index].attr & 0xF000;
    }
    else
    {
        load.src = D_086F7FD0[kind].tiles;
        load.dst = (void *)(0x06010000 + tile * 32);
        func_08001A54(&load, 0, 1);
        end = (*D_086F7FD0[kind].tiles >> 13) + D_0200DA74;
        load.src = D_086F7FD0[kind].palette;
        load.dst = (void *)(0x05000200 + task * 32);
        func_08001A54(&load, 0, 1);
        spr.attr |= task << 12;
    }
    if (mode & 0x10)
        spr.flags |= 0x8000;
    if (mode & 8)
        spr.flags2 |= 0x400;
    if (mode & 1)
        spr.flags |= 0x800;
    if (!(mode & 2))
        spr.flags |= 0x400;
    spr.x = spr.base_x = x << 16;
    spr.y = spr.base_y = y << 16;
    spr.frames = D_086F7FD0[kind].frames;
    spr.anims = D_086F7FD0[kind].anims;
    spr.tile = tile;
    if (end > D_0200DA74)
        D_0200DA74 = end;
    func_08000CEC(task, &spr, layer);
}
