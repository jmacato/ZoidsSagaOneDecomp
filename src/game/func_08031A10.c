#include "types.h"

struct Data
{
    u8 pad_0[8];
    u32 x;
    u32 y;
};

struct Unit
{
    u8 pad_0[0x16];
    u16 kind;
    u32 a;
    u32 b;
    u8 pad_20[0xB0];
    struct Data *data;
    u8 pad_D4[0x1F8];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Sprite
{
    u16 flags;
    u8 pad_2[4];
    u16 attr;
    u32 x;
    u32 y;
    u8 pad_10[0x78];
};

extern struct Side D_0200EB84[];
extern struct Sprite D_03004BBC[];
extern const u8 D_0866B6D8[];

s32 func_08032A88(s32, u8);
void func_08031FB4(u32, u32, u8);
void func_08031B70(u8, s32, s32);

void func_08031A10(void)
{
    u8 i;

    for (i = 0; i < 6; i++)
    {
        if (func_08032A88(0, i))
        {
            func_08031FB4(D_0200EB84[0].units[i].a, D_0200EB84[0].units[i].b, i);
            func_08031B70(D_0866B6D8[i], i + 5, 2);
            D_03004BBC[i + 5].attr |= 0x400;
            D_03004BBC[i + 5].x = D_0200EB84[0].units[i].data->x;
            D_03004BBC[i + 5].y = D_0200EB84[0].units[i].data->y;
        }
        else
            D_03004BBC[i + 5].flags &= 0x7FFF;
    }
}

void func_08031AD0(void)
{
    u8 i;

    for (i = 0; i < 6; i++)
    {
        if (D_0200EB84[0].units[i].kind != 0xFF)
            func_08031FB4(D_0200EB84[0].units[i].a, D_0200EB84[0].units[i].b, i);
    }
}
