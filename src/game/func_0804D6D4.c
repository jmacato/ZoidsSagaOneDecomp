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

extern struct Def D_086F6CA0[];
extern struct Def D_086F7620[];

void func_0805EDC0(void *, s32, u32);
void func_08001A54(const void *, s32, s32);
void func_08000CEC(s32, struct Sprite *, s32);
s32 func_08045784(s32, s32);
s32 func_080457BC(s32, s32);

s32 func_0804D6D4(u32 incoming_pos, u32 incoming_kind, u32 incoming_side)
{
    u16 pos = (u16)incoming_pos;
    u16 kind = (u16)incoming_kind;
    u16 side = (u16)incoming_side;
    struct Load load;
    struct Sprite spr;
    s16 p;
    s16 s;

    func_0805EDC0(&spr, 0, 0x88);
    spr.flags = 0x9001;
    switch ((s16)side)
    {
    case 0:
    case 2:
        if (!D_086F6CA0[(s16)kind].tiles)
            return 0;
        load.src = D_086F6CA0[(s16)kind].tiles;
        load.dst = (void *)(0x06010000 + ((s16)side << 12));
        func_08001A54(&load, 0, 1);
        load.src = D_086F6CA0[(s16)kind].palette;
        load.dst = (void *)(0x05000200 + (s16)side * 32);
        func_08001A54(&load, 0, 1);
        spr.frames = D_086F6CA0[(s16)kind].frames;
        spr.anims = D_086F6CA0[(s16)kind].anims;
        break;
    case 1:
        if (!D_086F7620[(s16)kind].tiles)
            return 0;
        load.src = D_086F7620[(s16)kind].tiles;
        load.dst = (void *)(0x06010000 + ((s16)side << 12));
        func_08001A54(&load, 0, 1);
        load.src = D_086F7620[(s16)kind].palette;
        load.dst = (void *)0x05000220;
        func_08001A54(&load, 0, 1);
        spr.frames = D_086F7620[(s16)kind].frames;
        spr.anims = D_086F7620[(s16)kind].anims;
        break;
    }
    switch ((s16)side)
    {
    case 0:
        spr.attr |= 0x400;
        break;
    case 1:
        spr.attr |= 0x1800;
        break;
    case 2:
        spr.attr |= 0x2C00;
        break;
    }
    p = pos;
    s = side;
    spr.x = func_08045784(p, s) << 16;
    spr.y = func_080457BC(p, s) << 16;
    spr.tile = s << 7;
    func_08000CEC(s + 2, &spr, 0);
    return 1;
}
