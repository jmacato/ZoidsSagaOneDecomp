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
    u8 pad_1E[0x30];
    u16 kind;
    u8 pad_50[0x38];
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

struct Unit
{
    u16 pos;
    u8 pad_2[2];
    u16 kinds[3];
};

extern struct Def D_086F6CA0[];
extern struct Def D_086F7620[];

void func_0805EDC0(void *, s32, u32);
void func_08001A54(const void *, s32, s32);
void func_08000CEC(s32, struct Sprite *, s32);
u16 func_08045784(u16, u8);
u16 func_080457BC(u16, u8);

void func_080455E4(struct Unit *unit, u8 side, u8 mode)
{
    struct Load load;
    struct Sprite spr;
    u16 kind;

    func_0805EDC0(&spr, 0, 0x88);
    spr.flags = 0x9001;
    kind = unit->kinds[side];
    switch (side)
    {
    case 0:
    case 2:
        load.src = D_086F6CA0[kind].tiles;
        load.dst = (void *)(0x06010000 + (side << 12));
        func_08001A54(&load, 0, 1);
        load.src = D_086F6CA0[kind].palette;
        load.dst = (void *)(0x05000200 + side * 32);
        func_08001A54(&load, 0, 1);
        spr.frames = D_086F6CA0[kind].frames;
        spr.anims = D_086F6CA0[kind].anims;
        break;
    case 1:
        load.src = D_086F7620[kind].tiles;
        load.dst = (void *)(0x06010000 + (side << 12));
        func_08001A54(&load, 0, 1);
        load.src = D_086F7620[kind].palette;
        load.dst = (void *)0x05000220;
        func_08001A54(&load, 0, 1);
        spr.frames = D_086F7620[kind].frames;
        spr.anims = D_086F7620[kind].anims;
        break;
    }
    switch (side)
    {
    case 0:
        spr.attr |= 0x800;
        break;
    case 1:
        spr.attr |= 0x1000;
        spr.attr |= 0x800;
        break;
    case 2:
        spr.attr |= 0x2000;
        spr.attr |= 0xC00;
        break;
    }
    switch ((u8)(mode & 0x20))
    {
    case 0:
        spr.x = func_08045784(unit->pos, side) << 16;
        spr.y = func_080457BC(unit->pos, side) << 16;
        break;
    case 0x20:
        spr.flags |= 0x100;
        spr.x = (0x80 - func_08045784(unit->pos, side)) << 16;
        spr.y = func_080457BC(unit->pos, side) << 16;
        break;
    }
    spr.kind = kind;
    spr.tile = side << 7;
    func_08000CEC(side + 0x14, &spr, 0);
}
