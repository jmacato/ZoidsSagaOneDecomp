#include "types.h"

struct Entry
{
    u8 zoid;
    u8 pad_1[3];
};

struct Zoid
{
    u8 pad_0[0x31];
    u8 state;
    u8 pad_32[6];
};

extern struct
{
    u8 pad_0[0xD30];
    struct Zoid zoids[1];
    u8 pad_D68[0x3600 - 0xD68];
    struct Entry entries[6];
} D_02000B5C;

u8 func_080371E8(u8 position)
{
    u8 result = 0xFF;
    u8 slot;
    u8 zoid;

    switch (position)
    {
    case 0:
    case 1:
    case 2:
        slot = 1;
        break;
    case 3:
    case 4:
    case 5:
        slot = 4;
        break;
    }
    zoid = D_02000B5C.entries[slot].zoid;
    if (zoid != 0xFF && D_02000B5C.zoids[zoid].state == 2)
        result = slot;
    return result;
}
