#include "types.h"

struct Part
{
    u32 flags;
    u8 pad_4[0x10];
};

struct Unit
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[0x46];
    struct Part parts[6];
    u8 pad_C8[0x204];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Turn
{
    u8 side;
    u8 slot;
    u8 pad_2[2];
};

struct Command
{
    u8 part;
    u8 pad_1[3];
    u8 side;
    u8 pad_5[0xF];
};

struct Message
{
    u8 pad_0[0x10];
    struct Command commands[2];
};

extern struct
{
    u8 pad_0[8];
    struct Side sides[2];
    u8 pad_21B8[0x34];
    u8 side;
    u8 field_21ED;
    u8 pad_21EE[2];
    u8 part;
    u8 count;
    u8 pad_21F2[2];
    struct Turn turns[6];
} D_0200EB84;

void func_0805D270(const void *, void *, u32);

void func_0803DE74(struct Message *message)
{
    vu16 zero;
    s16 i;
    s16 other;

    D_0200EB84.count = 0;
    zero = 0;
    func_0805D270((void *)&zero, &D_0200EB84.side, 0x01000002);
    for (i = 0; i < 6; i++)
    {
        vu16 clear = 0;

        func_0805D270((void *)&clear, &D_0200EB84.turns[i], 0x01000002);
    }
    D_0200EB84.side = message->commands[1].side;
    D_0200EB84.field_21ED = 1;
    other = !message->commands[1].side;
    D_0200EB84.part = message->commands[message->commands[1].side].part;
    if (D_0200EB84.part == 0xFF)
        D_0200EB84.part = 3;
    for (i = 0; i < 6; i++)
    {
        D_0200EB84.turns[i].side |= 0xFF;
        D_0200EB84.turns[i].slot |= 0xFF;
    }
    D_0200EB84.turns[1].side = other;
    D_0200EB84.turns[1].slot = 1;
    D_0200EB84.sides[D_0200EB84.side].units[1].parts[D_0200EB84.part].flags |= 0x40000000;
    if (D_0200EB84.sides[other].units[1].parts[message->commands[other].part].flags & 0x4000)
        D_0200EB84.sides[other].units[1].flags |= 0x8000;
}
