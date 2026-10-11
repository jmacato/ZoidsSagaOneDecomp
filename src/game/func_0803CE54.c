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

void func_080335B4(s32, s32, s32, s32);

void func_0803CE54(void)
{
    D_0200EB84.sides[D_0200EB84.side].units[D_0200EB84.unit].flags |= 1;
    func_080335B4(1, 3, 5, 1);
    D_0200EB84.refresh = 0xFF;
}
