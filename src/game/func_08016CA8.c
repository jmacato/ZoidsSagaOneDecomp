#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[0xA];
    s32 y;
    u8 pad_10[0x78];
};

extern struct Sprite D_03004BBC[];

void func_08008B70(u16, u16, u16);
void func_08000BD8(s32, s32);
void func_080019EC(s32);
void func_0805EE78(s32);

void func_08016CA8(s32 slot, s32 x, s32 y)
{
    func_08008B70(slot, x, y);
    D_03004BBC[slot + 1].y++;
    func_08000BD8(slot + 1, 0);
    D_03004BBC[slot + 1].flags |= 0x400;
    func_080019EC(0x5B);
    while (!(D_03004BBC[slot + 1].flags & 4))
        func_0805EE78(1);
    func_08008B70(slot, 0xFF, 0xFF);
}
