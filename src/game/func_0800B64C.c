#include "types.h"

struct Sprite
{
    u8 pad_0[0x30];
    u16 dir;
    u8 pad_32[6];
    u16 moving;
    u8 pad_3A[0x1C];
    u16 input;
    u8 pad_58[8];
    u16 state;
    u16 locked;
    u8 pad_64[0x10];
    u32 dx;
    u32 dy;
    u8 pad_7C[0xC];
};

extern struct Sprite D_03004BBC[];
extern void (*D_08666D04[])(u16);

void func_0800B4C8(u16);
void func_0800B328(u16, u16, s16, s16);
void func_0800AE7C(u16, u16, s16, s16);

void func_0800B64C(u16 sprite)
{
    u16 input;

    D_03004BBC[sprite].dx = 0;
    D_03004BBC[sprite].dy = 0;
    D_08666D04[D_03004BBC[sprite].state](sprite);
    input = D_03004BBC[sprite].input;
    if (input & 8)
        func_0800B4C8(sprite);
    else if (input & 1)
    {
        if (D_03004BBC[sprite].dir == 0)
            func_0800B328(sprite, 0, 0, -1);
        else if (D_03004BBC[sprite].dir == 1)
            func_0800B328(sprite, 1, 0, 1);
        else if (D_03004BBC[sprite].dir == 2)
            func_0800B328(sprite, 2, -1, 0);
        else if (D_03004BBC[sprite].dir == 3)
            func_0800B328(sprite, 3, 1, 0);
    }
    else if (input & 0x40)
        func_0800AE7C(sprite, 0, 0, -1);
    else if (input & 0x80)
        func_0800AE7C(sprite, 1, 0, 1);
    else if (input & 0x20)
        func_0800AE7C(sprite, 2, -1, 0);
    else if (input & 0x10)
        func_0800AE7C(sprite, 3, 1, 0);
    else if (D_03004BBC[sprite].locked == 0)
        D_03004BBC[sprite].moving = 1;
    else
        D_03004BBC[sprite].moving = 0;
}
