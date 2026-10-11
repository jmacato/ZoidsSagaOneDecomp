#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[4];
    u16 attr;
    u8 pad_8[0x44];
    u16 field_4C;
    u16 field_4E;
    u16 field_50;
    u8 pad_52[2];
    u16 field_54;
    u8 pad_56[0xE];
    u16 field_64;
    u8 pad_66[0x1E];
    void *func;
};

struct Layout
{
    u8 kind[18];
    u16 x[18];
    u16 y[18];
    u32 flags[18];
};

extern struct Sprite D_03004BBC[];
extern struct Layout D_086D6FE8;
extern u8 D_086D70B0[];
extern void *D_086D45E0[];
extern u8 D_0200E28C;

u16 func_08045784(u16, u8);
u16 func_080457BC(u16, u8);
void func_08048320(u16 *, u8, u8, u16, u16, u32);

s32 func_08048B0C(u16 *pos, u8 side)
{
    u16 i;
    u32 kind;
    u16 x;
    u16 y;
    u32 flags;

    D_0200E28C = 0;
    for (i = 0; i <= 6; i++)
    {
        kind = D_086D6FE8.kind[i];
        if (D_086D6FE8.flags[i] & 4)
        {
            x = func_08045784(*pos, side) + D_086D6FE8.x[i] + 0x70;
            y = func_080457BC(*pos, side) + D_086D6FE8.y[i];
            flags = D_086D6FE8.flags[i];
            if (side == 1)
                y -= 0x10;
        }
        else
        {
            x = D_086D6FE8.x[i];
            y = D_086D6FE8.y[i];
            flags = D_086D6FE8.flags[i];
        }
        func_08048320(pos, i, kind, x, y, flags);
        D_03004BBC[i + 1].flags = (D_03004BBC[i + 1].flags & 0xFFFE) | 0x8000;
        D_03004BBC[i + 1].attr = (D_03004BBC[i + 1].attr & 0xF3FF) | 0x400;
        if (D_086D70B0[i])
        {
            D_03004BBC[i + 1].field_64 = 1;
            if (flags & 0x10)
                D_03004BBC[i + 1].field_4C = 1;
            else
                D_03004BBC[i + 1].field_4C = 0;
            D_03004BBC[i + 1].field_4E = i + 1;
            D_03004BBC[i + 1].field_50 = 0;
            D_03004BBC[i + 1].field_54 = side;
            D_03004BBC[i + 1].func = D_086D45E0[D_086D70B0[i]];
        }
    }
}
