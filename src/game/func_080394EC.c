#include "types.h"

struct Entry
{
    u16 active;
    u16 pad_2;
    u8 data[8];
};

extern struct
{
    u8 pad_0[0x21F1];
    u8 busy;
    u8 pad_21F2[2];
    u8 side;
    u8 slot;
    u8 pad_21F6[0x16];
    struct Entry entries[2][6];
} D_0200EB84;

extern void (*const D_08683900[])(void *, u8 *);

void func_080394EC(u32 incoming_action, void *arg, u32 incoming_side, u32 incoming_slot)
{
    u8 action = (u8)incoming_action;
    u8 side = (u8)incoming_side;
    u8 slot = (u8)incoming_slot;
    void (*func)(void *, u8 *);

    D_0200EB84.busy = 1;
    D_0200EB84.side = side;
    D_0200EB84.slot = slot;
    D_0200EB84.entries[side][slot].active = 1;
    func = D_08683900[action];
    func(arg, D_0200EB84.entries[side][slot].data);
}
