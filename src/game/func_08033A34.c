#include "types.h"

struct Pair
{
    u8 pad_0[2];
    u16 id;
};

struct Slot
{
    u16 values[9];
    u16 id;
};

struct Board
{
    u8 pad_0[0x18];
    struct Pair pairs[14];
    struct Slot slots[6];
};

void func_0805D270(void *, void *, u32);

void func_08033A34(struct Board *board, u8 index)
{
    vu16 zero;

    board->pairs[index].id = 0xFFFF;
    zero = 0;
    func_0805D270(&zero, &board->slots[index], 0x0100000A);
    board->slots[index].id = -1;
}
