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
    u8 pad_1E[0x6A];
};

struct Load
{
    const void *src;
    void *dst;
    u16 size;
};

struct ZoidDef
{
    u8 pad_0[0x30];
    const void *tiles;
    const void *palette;
    u32 frames;
    u32 anims;
    u8 pad_40[0xC];
};

extern struct ZoidDef D_0867006C[];
extern u16 D_086D41B4[];
extern u16 D_0200DA74;

void func_0805EDC0(void *, s32, u32);
void func_08001A54(struct Load *, s32, s32);
void func_08000CEC(u8, struct Sprite *, s32);

void func_08044F98(s32 unused, u8 slot, u8 zoid, u16 x, u16 y, u16 flip)
{
    struct Load load;
    struct Sprite spr;
    u16 tile;
    u16 end;
    s32 index;

    func_0805EDC0(&spr, 0, 0x88);
    spr.flags = 0x1000;
    spr.attr = 0x800;
    tile = D_0200DA74;
    load.src = D_0867006C[zoid].tiles;
    load.dst = (void *)(0x06010000 + tile * 32);
    load.size = 0x800;
    func_08001A54(&load, 0, 0);
    end = D_0200DA74 + 0x40;
    load.src = D_0867006C[zoid].palette;
    load.dst = (void *)(0x05000200 + (slot - 10) * 32);
    load.size = 0x20;
    func_08001A54(&load, 0, 0);
    spr.attr |= (slot - 10) << 12;
    spr.x = (D_086D41B4[index = slot - 14] + x) << 16;
    spr.y = ((D_086D41B4 + 6)[index] + y) << 16;
    spr.flags |= 0x20;
    if (!flip)
        spr.flags |= 0x100;
    spr.frames = D_0867006C[zoid].frames;
    spr.anims = D_0867006C[zoid].anims;
    spr.tile = tile;
    if (end > D_0200DA74)
        D_0200DA74 = end;
    func_08000CEC(slot, &spr, 0);
}
