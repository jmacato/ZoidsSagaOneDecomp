#include "types.h"

struct Sprite
{
    u8 pad_0[0x4C];
    u16 speed;
    u16 tile_x;
    u16 tile_y;
    u8 pad_52[4];
    u16 dir;
    u8 pad_58[0x16];
    u16 base_speed;
    u8 pad_70[0x18];
};

extern struct Sprite D_03004BBC[];

void func_0800A864(u16 sprite, s32 unused, u16 flee, u16 x, u16 y)
{
    u16 dx;
    s16 dy;
    s16 sx;
    s32 sy;
    u16 ax;
    u16 ay;

    D_03004BBC[sprite].dir = 0;
    if (x == 0xFFFF && y == 0xFFFF)
    {
        dx = D_03004BBC[1].tile_x - D_03004BBC[sprite].tile_x;
        dy = D_03004BBC[1].tile_y - D_03004BBC[sprite].tile_y;
    }
    else
    {
        dx = x - D_03004BBC[sprite].tile_x;
        dy = y - D_03004BBC[sprite].tile_y;
    }
    sx = dx;
    ax = sx < 0 ? -sx : sx;
    sy = dy;
    ay = sy < 0 ? -sy : sy;
    if (ax == ay)
    {
        if (!flee)
        {
            if (sx < 0)
                D_03004BBC[sprite].dir = 0x20;
            else
                D_03004BBC[sprite].dir = 0x10;
        }
        else
        {
            if (sx < 0)
                D_03004BBC[sprite].dir = 0x10;
            else
                D_03004BBC[sprite].dir = 0x20;
        }
    }
    else if (ax > ay)
    {
        if (!flee)
        {
            if (sx < 0)
                D_03004BBC[sprite].dir = 0x20;
            else
                D_03004BBC[sprite].dir = 0x10;
        }
        else
        {
            if (sx < 0)
                D_03004BBC[sprite].dir = 0x10;
            else
                D_03004BBC[sprite].dir = 0x20;
        }
    }
    else if (!flee)
    {
        if (sy < 0)
            D_03004BBC[sprite].dir = 0x40;
        else
            D_03004BBC[sprite].dir = 0x80;
    }
    else
    {
        if (sy < 0)
            D_03004BBC[sprite].dir = 0x80;
        else
            D_03004BBC[sprite].dir = 0x40;
    }
    D_03004BBC[sprite].speed = D_03004BBC[sprite].base_speed;
}
