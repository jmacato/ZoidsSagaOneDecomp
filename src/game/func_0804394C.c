#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[4];
    u16 attr;
    u8 pad_8[4];
    s32 y;
    u8 pad_10[0x3C];
    u16 active;
    u8 pad_4E[0x3A];
};

struct Scene
{
    u8 count;
    u8 pad_1[3];
    s32 speed;
    u8 kinds[20];
};

extern struct Sprite D_03004BBC[];
extern struct Scene D_086D3CB4[];

void func_080490C0(u8, u8, u8, u8, u16, u16, s32);
void func_0805EE78(s32);

s32 func_0804394C(u16 scene)
{
    u8 count;
    s32 speed;
    u8 done;
    u8 i;
    u8 kind;
    u16 x;

    count = D_086D3CB4[scene].count;
    speed = D_086D3CB4[scene].speed;
    done = 0;
    for (i = 0; i < 20 && (kind = D_086D3CB4[scene].kinds[i]) != 0xFF; i++)
    {
        x = 16;
        if (i == 0)
            x = 8;
        func_080490C0(i, 0x7F, 0x1D, kind, x + 0x80, i * 16 + 0xA0, 0x80000000);
        D_03004BBC[i].active = 1;
        func_080490C0(i + 10, 0x7F, 0x1D, kind, x + 0x81, i * 16 + 0xA1, 0x80000000);
        D_03004BBC[i + 10].attr = (D_03004BBC[i + 10].attr & 0xFFF) | 0xF000;
    }
    while (done != count)
    {
        for (i = 0; i < count; i++)
        {
            if (D_03004BBC[i].active)
            {
                D_03004BBC[i].y -= speed;
                D_03004BBC[i + 10].y -= speed;
                if ((u16)(D_03004BBC[i].y >> 16) <= 0x9F)
                {
                    D_03004BBC[i].flags |= 0x8000;
                    D_03004BBC[i + 10].flags |= 0x8000;
                }
                if ((u16)(D_03004BBC[i].y >> 16) == 0)
                {
                    D_03004BBC[i].flags &= 0x7FFF;
                    D_03004BBC[i + 10].flags &= 0x7FFF;
                    D_03004BBC[i].active = 0;
                    done++;
                }
            }
        }
        if (D_086D3CB4[scene + 1].count == 0xFF && D_03004BBC[0].y == 0x400000)
            return 1;
        func_0805EE78(1);
    }
    return 0;
}
