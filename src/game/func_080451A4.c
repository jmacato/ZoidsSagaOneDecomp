#include "types.h"

struct Sprite
{
    u8 pad_0[0x4C];
    u16 visible;
    u8 pad_4E[0x3A];
};

struct Stat
{
    u16 value;
    u8 pad_2[0x1A];
};

extern struct Sprite D_03004BBC[];
extern struct Stat D_0200D920[];
extern u8 D_086D41CC[];
extern u8 D_086D41D2[];

u8 func_08032A88(s32, u8);
void func_08044F98(void *, u8, u8, s32, s32, s32);
void func_080455A8(u8, s32, s32);

void func_080451A4(void *window, u8 side)
{
    u8 i;
    u16 value;

    for (i = 0; i < 6; i++)
    {
        switch (side)
        {
        case 0:
            if (!func_08032A88(0, D_086D41CC[i]))
                D_03004BBC[i + 14].visible = 0;
            else
            {
                value = D_0200D920[D_086D41CC[i]].value;
                if (value)
                {
                    func_08044F98(window, i + 14, value, 0, 0, 0);
                    func_080455A8(i + 14, 0, 0);
                    D_03004BBC[i + 14].visible = 1;
                }
                else
                    D_03004BBC[i + 14].visible = value;
            }
            break;
        case 1:
            if (!func_08032A88(1, D_086D41D2[i]))
                D_03004BBC[i + 14].visible = 0;
            else
            {
                value = D_0200D920[D_086D41D2[i] + 6].value;
                if (value)
                {
                    func_08044F98(window, i + 14, value, 0, 0, 1);
                    func_080455A8(i + 14, 0, 0);
                    D_03004BBC[i + 14].visible = 1;
                }
                else
                    D_03004BBC[i + 14].visible = value;
            }
            break;
        }
    }
}
