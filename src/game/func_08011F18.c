#include "types.h"

struct Sprite
{
    u8 pad_0[8];
    u32 x;
    u32 y;
    u8 pad_10[0x20];
    u16 dir;
    u8 pad_32[0x56];
};

extern struct Sprite D_03004BBC[];

void func_08000BD8(s32, s32);
void func_08011E40(u16, u8, s32, u8);
void func_08011EAC(u16, u8, s32, u8);

void func_08011F18(u16 slot, u16 x, u16 y, u8 step, u8 speed, u8 mode)
{
    u8 done = 0;
    u32 target_x;
    u32 target_y;
    u8 count;
    s32 delta;
    u16 dir;

    if (step == 16)
        x -= 8;
    target_x = x << 16;
    target_y = y << 16;
    dir = D_03004BBC[slot + 1].dir;
    count = step / speed;
    do
    {
        if (D_03004BBC[slot + 1].x != target_x)
        {
            delta = -speed;
            if (D_03004BBC[slot + 1].x < target_x)
                delta = speed;
            func_08000BD8(slot + 1, delta == speed ? 7 : 6);
            func_08011E40(slot, count, delta, mode);
            dir = delta == speed ? 3 : 2;
        }
        else
            done |= 1;
        if (D_03004BBC[slot + 1].y != target_y)
        {
            delta = -speed;
            if (D_03004BBC[slot + 1].y < target_y)
                delta = speed;
            func_08000BD8(slot + 1, delta == speed ? 5 : 4);
            func_08011EAC(slot, count, delta, mode);
            dir = delta == speed ? 1 : 0;
        }
        else
            done |= 2;
    } while (done != 3);
    func_08000BD8(slot + 1, dir);
}
