#include "types.h"

struct Song
{
    u8 id;
    u8 name[23];
};

struct Model
{
    const void *palette;
    const void *tiles;
    u32 frames;
    u32 anims;
    u8 pad_10[0xA];
    u16 x;
    u16 y;
    u8 pad_1E[2];
};

struct Sprite
{
    u8 pad_0[0x10];
    u16 x;
    u16 y;
    u32 frames;
    u32 anims;
    u16 tile;
    u8 pad_1E[2];
    u32 vram;
    const void *tiles;
    u8 pad_28[0x60];
};

extern const u8 D_08328E38[];
extern const u8 D_08328E30[];
extern const u8 D_08329F08[];
extern const u8 D_08329F14[];
extern struct Song D_08329518[];
extern struct Model D_08318CE4[];
extern struct Sprite D_03004BBC[];
extern u16 D_0300235A;
extern u16 D_03002334;
extern u16 D_02000B56;

void func_0805C18C(s32);
void func_080019EC(s32);
void func_08000DB8(void);
void func_08000D1C(s32);
void func_080014A8(s32, void *);
void func_08009A54(void);
void func_08009B30(const u8 *, s32);
void func_08009AD4(u16, s32);
void func_08001D04(s32);
u16 func_0800175C(s32, s32);
void func_08001A08(u16);
void func_08001A18(u16);
void func_08001988(void);
void func_08000BD8(s32, u16);

s32 func_08009B6C(void)
{
    u16 sel = 0;
    u16 keys;
    vu32 zero;
    vu32 *dma;

    func_0805C18C(0x800);
    *(vu16 *)0x04000000 = 0x140;
    *(vu16 *)0x04000008 = 5;
    zero = 0;
    dma = (vu32 *)0x040000D4;
    dma[0] = (u32)&zero;
    dma[1] = 0x06000000;
    dma[2] = 0x85003000;
    dma[2];
    func_080019EC(0);
    func_08000DB8();
    func_08000D1C(0);
    dma[0] = (u32)D_08328E38;
    dma[1] = 0x06004020;
    dma[2] = 0x84000138;
    dma[2];
    dma[0] = (u32)D_08328E30;
    dma[1] = 0x05000000;
    dma[2] = 0x80000004;
    dma[2];
    func_080014A8(0xFFFF, func_08009A54);
    D_03002334 = 1;
    func_08009B30(D_08329F08, 0x260);
    for (;;)
    {
        keys = func_0800175C(0x10, 6);
        if (D_0300235A & 8)
            break;
        if ((keys & 0x20) && sel)
            sel--;
        if ((keys & 0x10) && sel <= 0x68)
            sel++;
        if (keys & 1)
            func_080019EC(D_08329518[sel].id);
        if (keys & 2)
            func_080019EC(0);
        if (keys & 0x200)
            func_08001A08(D_02000B56);
        if (keys & 0x100)
            func_08001A18(D_02000B56);
        if (keys & 4)
            func_08001988();
        func_08009AD4(sel, 0x144);
        func_08009B30(D_08329F14, 0x149);
        func_08009B30(D_08329518[sel].name, 0x149);
        func_08009AD4(D_08329518[sel].id, 0x169);
        func_08001D04(1);
    }
    D_03002334 = 0;
    func_080019EC(0);
}

s32 func_08009D30(u16 model, u16 anim)
{
    u16 tile = 0;
    vu32 *dma = (vu32 *)0x040000D4;

    dma[0] = (u32)D_08318CE4[model].palette;
    dma[1] = 0x05000200;
    dma[2] = 0x80000010;
    dma[2];
    D_03004BBC[0].x = D_08318CE4[model].x;
    D_03004BBC[0].y = D_08318CE4[model].y;
    D_03004BBC[0].frames = D_08318CE4[model].frames;
    D_03004BBC[0].anims = D_08318CE4[model].anims;
    D_03004BBC[0].tile = tile;
    D_03004BBC[0].vram = 0x06010000;
    D_03004BBC[0].tiles = D_08318CE4[model].tiles;
    func_08000BD8(0, anim);
}
