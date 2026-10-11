#include "types.h"

struct Unit
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[0x2C2];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

extern struct
{
    struct Side sides[2];
    u8 pad_21B0[0x40];
    u8 refresh;
    u8 pad_21F1[3];
    u8 side;
    u8 unit;
} D_0200EB84;

void func_08033628(s32, s32, s32, s32, s32, s32, s32);

void func_0803DAA4(void)
{
    func_08033628(1, 0, 5, 0x11, 0x64, 0, 1);
    func_08033628(1, 0, 5, 0x802, 0x32, 0, 1);
    D_0200EB84.refresh = 0xFF;
}

void func_0803DAF4(void)
{
    D_0200EB84.sides[D_0200EB84.side].units[D_0200EB84.unit].flags |= 4;
    D_0200EB84.refresh = 0xFF;
}
