#include "types.h"

struct Sprite
{
    u16 flags;
    u16 flags2;
    u8 pad_4[0x46];
    u16 state;
    u8 pad_4C[0x3C];
};

extern struct Sprite D_03004BBC[];

void func_080480D4(u16, u16, s32, s32);
void func_08048084(s32, s32, s32, s32);

s32 func_08048140(u32 incoming_mode, u32 incoming_timer, u32 incoming_closing)
{
    u8 mode = (u8)incoming_mode;
    u8 timer = (u8)incoming_timer;
    u8 closing = (u8)incoming_closing;
    s32 a;
    s32 b;

    switch (mode)
    {
    case 0:
        if (!closing)
        {
            if (timer == 0)
            {
                func_080480D4(15, 0, 0, 6);
                func_08048084(0x40, 2, 0x16, 0);
                D_03004BBC[20].flags2 |= 0x400;
                D_03004BBC[21].flags2 |= 0x400;
            }
            func_080480D4(15 - timer, timer, 0, 6);
            D_03004BBC[20].flags2 |= 0x400;
            if (D_03004BBC[20].state && timer > 8)
                D_03004BBC[20].flags &= 0x7FFF;
            D_03004BBC[21].flags2 |= 0x400;
            timer++;
            if (timer > 11)
                timer = 0;
        }
        else if (timer == 100)
        {
            func_08048084(0, 0, 0, 1);
            timer = 0;
        }
        else
        {
            func_080480D4(timer + 4, 11 - timer, 0, 6);
            timer++;
            if (D_03004BBC[20].state && timer > 8)
                D_03004BBC[20].flags |= 0x8000;
            if (timer > 11)
            {
                D_03004BBC[20].flags2 &= 0xFBFF;
                D_03004BBC[21].flags2 &= 0xFBFF;
                timer = 100;
            }
        }
        break;
    case 1:
        if (!closing)
        {
            func_080480D4(15, 8, 0, 6);
            func_08048084(0, 0x10, 0x16, 0);
        }
        else
            func_08048084(0, 0, 0, 1);
        break;
    case 2:
        if (!closing)
        {
            if (timer == 0)
            {
                a = 0;
                b = 15;
            }
            else
            {
                a = (timer / 2) * 15 >> 4;
                b = 15 - ((timer / 2) * 7 >> 4);
            }
            func_080480D4(a, b, 0, 6);
            timer++;
            if (timer / 2 == 16)
                timer = 0;
        }
        else
            func_08048084(0, 0, 0, 1);
        break;
    }
    return timer;
}
