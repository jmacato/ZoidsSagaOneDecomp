#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[0x32];
    u16 frame;
    u16 anim;
    u16 mode;
    u8 pad_3A[0x14];
    u16 tile_x;
    u16 tile_y;
    u8 pad_52[8];
    u16 kind;
    u8 pad_5C[4];
    u16 state;
    u8 pad_62[8];
    u16 target_x;
    u16 target_y;
    u16 delay;
    u8 pad_70[0xC];
    u32 speed;
    u8 pad_80[8];
};

extern struct Sprite D_03004BBC[];

extern struct
{
    u8 pad_0[0x18];
    u16 scale;
} D_0200000C;

extern struct
{
    u8 pad_0[8];
    u16 counter;
} D_02000000;

void func_08000BD8(s32, s32);
void func_080019EC(s32);
void func_08008B70(s32, s32, s32);
void func_0805EE78(s32);
s32 func_080084D4(u16, s16, s16);
void func_080083B8(u16, u16 *, u16 *, u16 *, u16 *);
void func_08001524(s32, void *);
void func_0800BEC8(void);
void func_08007188(u16, u16, u16, s32);
void func_080014A8(s32, void *);
void func_08003DD8(s32);

s32 func_0800960C(void)
{
    u16 area;
    u16 x;
    u16 y;
    u16 dir;
    u16 i;

    for (i = 1; i <= 0x1D; i++)
    {
        if ((D_03004BBC[i].flags & 0x8000) && D_03004BBC[i].kind == 0xF7)
            break;
    }
    if (i != 0x1E)
    {
        D_03004BBC[1].state = 0xB;
        D_03004BBC[1].target_x = D_03004BBC[i].tile_x;
        D_03004BBC[1].target_y = D_03004BBC[i].tile_y;
        D_03004BBC[1].speed = 0x10000;
        D_03004BBC[1].delay = D_0200000C.scale << 3;
        D_03004BBC[1].mode = 1;
        func_08000BD8(i, 1);
        D_03004BBC[i].flags |= 0x400;
        func_080019EC(0x6F);
        while (!(D_03004BBC[i].flags & 4))
        {
            if (D_03004BBC[i].frame == 0x10 && D_03004BBC[i].anim == 1)
                func_08008B70(0, 0xFF, 0xFF);
            if (D_03004BBC[i].frame == 0x52 && D_03004BBC[i].anim == 1)
                func_080019EC(0x44);
            func_0805EE78(1);
        }
        func_08000BD8(i, 0);
        D_03004BBC[i].flags &= 0xFBFF;
    }
    func_0805EE78(0x3C);
    func_080083B8(func_080084D4(i, 0, 0), &area, &x, &y, &dir);
    func_08001524(0, func_0800BEC8);
    func_08007188(area, x, y, 0xFFFF);
    D_03004BBC[1].state = 1;
    D_02000000.counter |= 2;
    func_08008B70(0, 0xFF, 0xFF);
    for (i = 1; i <= 0x1D; i++)
    {
        if ((D_03004BBC[i].flags & 0x8000) && D_03004BBC[i].kind == 0xF7)
            break;
    }
    if (i == 0x1E)
        func_08008B70(0, x, y);
    func_080014A8(0, func_0800BEC8);
    func_0805EE78(0x3C);
    if (i != 0x1E)
    {
        func_08000BD8(i, 2);
        D_03004BBC[i].flags |= 0x400;
        func_080019EC(0x6F);
        while (!(D_03004BBC[i].flags & 4))
        {
            if (D_03004BBC[i].frame == 0x30 && D_03004BBC[i].anim == 1 && (0x2000 & func_080084D4(i, 0, 1)))
            {
                func_080019EC(0x6F);
                D_03004BBC[i].frame = 0;
            }
            if (D_03004BBC[i].frame == 0x40 && D_03004BBC[i].anim == 1)
            {
                D_03004BBC[1].flags |= 0x8000;
                func_08008B70(0, D_03004BBC[i].tile_x, D_03004BBC[i].tile_y);
                D_03004BBC[1].state = 0xA;
                D_03004BBC[1].target_x = D_03004BBC[i].tile_x;
                D_03004BBC[1].target_y = D_03004BBC[i].tile_y + 1;
                D_03004BBC[1].speed = 0x10000;
                D_03004BBC[1].delay = D_0200000C.scale << 3;
                D_03004BBC[1].mode = 1;
                func_080019EC(0x49);
            }
            func_0805EE78(1);
        }
        func_08000BD8(i, 0);
        D_03004BBC[i].flags &= 0xFBFF;
    }
    D_02000000.counter &= 0xFFFD;
    D_03004BBC[1].state = 0;
    func_08003DD8(10);
}
