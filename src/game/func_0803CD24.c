#include "types.h"

struct Unit
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[6];
    u16 status;
    u8 pad_12[0x33];
    u8 kind;
    u8 pad_46[0x286];
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
    u8 field_21F0;
} D_0200EB84;

s32 func_08032A88(u8, u8);

void func_0803CD24(void)
{
    u8 side;
    u8 slot;

    for (side = 0; side < 2; side++)
    {
        for (slot = 0; slot < 6; slot++)
        {
            if (func_08032A88(side, slot) && (D_0200EB84.sides[side].units[slot].status & 4))
                D_0200EB84.sides[side].units[slot].flags |= 1;
        }
    }
    D_0200EB84.field_21F0 = 0xFF;
}
