#include "types.h"

struct Sprite
{
    u8 pad_0[8];
    u32 x;
    u32 y;
    u8 pad_10[0x20];
    u16 dir;
    u8 pad_32[0x18];
    u16 timer;
    u16 moving;
    u16 tile_x;
    u16 tile_y;
    u16 last_x;
    u16 last_y;
    u8 pad_56[2];
    u16 step;
    u8 pad_5A[2];
    u16 warp;
    u8 pad_5E[6];
    u16 slot;
    u8 pad_66[0xE];
    u32 dx;
    u32 dy;
    u8 pad_7C[0xC];
};

struct Slot
{
    u8 pad_0[2];
    u8 x;
    u8 y;
    u8 pad_4[0xC];
};

extern struct Sprite D_03004BBC[];

extern struct
{
    u8 pad_0[0x50];
    struct Slot slots[1];
} D_02000B5C;

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

void func_08008274(u32, u32);
u16 func_08001080(void);
void func_08000BD8(u16, s32);
u16 func_08008434(s32, s32, s32);
void func_080083B8(u16, u16 *, u16 *, u16 *, u16 *);
void func_08001524(s32, void *);
void func_0800BEC8(void);
void func_08007188(u16, u16, u16, u16);
void func_080014A8(s32, void *);

void func_0800B764(u16 sprite)
{
    u16 x;
    u16 y;
    u16 dir;
    u16 extra;

    if (sprite == 1)
        func_08008274(D_03004BBC[1].dx, D_03004BBC[1].dy);
    D_03004BBC[sprite].x += D_03004BBC[sprite].dx;
    D_03004BBC[sprite].y += D_03004BBC[sprite].dy;
    D_03004BBC[sprite].moving--;
    if (D_03004BBC[sprite].moving == D_03004BBC[sprite].step)
    {
        D_03004BBC[sprite].last_x = D_03004BBC[sprite].tile_x;
        D_03004BBC[sprite].last_y = D_03004BBC[sprite].tile_y;
        if (D_03004BBC[sprite].slot != 0xFFFF)
        {
            D_02000B5C.slots[D_03004BBC[sprite].slot].x = D_03004BBC[sprite].tile_x;
            D_02000B5C.slots[D_03004BBC[sprite].slot].y = D_03004BBC[sprite].tile_y;
        }
    }
    if (D_03004BBC[sprite].moving == 0)
    {
        D_03004BBC[sprite].timer = 0;
        D_03004BBC[sprite].moving = (u8)func_08001080() & 0x7F;
        func_08000BD8(sprite, D_03004BBC[sprite].dir - 4);
        if (sprite == 1)
        {
            u16 warp = func_08008434(1, 0, 0);

            if ((D_02000000.counter & 4) || *(u16 *)((u8 *)D_03004BBC + 0xE8) == 0xB)
                warp &= 0xFFF;
            if (warp & 0x4000)
            {
                func_080083B8(warp, &x, &y, &dir, &extra);
                func_08001524(0, func_0800BEC8);
                func_08007188(x, y, dir, extra);
                func_080014A8(0, func_0800BEC8);
            }
            else
                D_03004BBC[sprite].warp = warp;
        }
    }
}
