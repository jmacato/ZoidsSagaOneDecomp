#include "types.h"

struct Sprite
{
    u8 pad_0[0x4C];
    u16 speed;
    u16 tile_x;
    u16 tile_y;
    u8 pad_52[4];
    u16 dir;
    u8 pad_58[0x24];
    u32 step;
    u8 pad_80[8];
};

extern struct Sprite D_03004BBC[];

extern struct
{
    u8 pad_0[0x18];
    u16 scale;
} D_0200000C;

u16 func_08001080(void);
u16 func_0800A54C(void);
void func_0800A594(u16);

void func_0800A5E4(u16 sprite, u16 range, u16 flee, u16 x, u16 y)
{
    u16 dx;
    u16 dy;
    s16 sx;
    s16 sy;
    u16 ax;
    u16 ay;
    u16 r;

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
    if (ax <= range && ay <= range)
    {
        r = func_08001080();
        if (ax == ay)
        {
            if (r < 0x1000)
                D_03004BBC[sprite].dir = func_0800A54C();
            else if ((s16)r >= 0)
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
            else
            {
                if (!flee)
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
            }
        }
        else if (ax > ay)
        {
            if (r < 0x1000)
                D_03004BBC[sprite].dir = func_0800A54C();
            else if (!flee)
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
        else
        {
            if (r < 0x1000)
                D_03004BBC[sprite].dir = func_0800A54C();
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
        }
        D_03004BBC[sprite].step = 0x10000;
        D_03004BBC[sprite].speed = D_0200000C.scale << 3;
    }
    else
        func_0800A594(sprite);
}
