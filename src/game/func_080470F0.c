#include "types.h"

struct Sprite
{
    u8 pad_0[0x4C];
    u16 active;
    u8 pad_4E[0x3A];
};

extern struct Sprite D_03004BBC[];

u8 func_080470F0(u8 slot)
{
    u8 result = 0;

    switch (slot)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        result = D_03004BBC[slot + 14].active;
        break;
    case 6:
        if (D_03004BBC[17].active)
            result = slot;
        if (D_03004BBC[14].active)
            result = slot;
        break;
    case 7:
        if (D_03004BBC[18].active)
            result = slot;
        if (D_03004BBC[15].active)
            result = slot;
        break;
    case 8:
        if (D_03004BBC[19].active)
            result = slot;
        if (D_03004BBC[16].active)
            result = slot;
        break;
    case 9:
        if (D_03004BBC[16].active)
            result = slot;
        if (D_03004BBC[15].active)
            result = slot;
        if (D_03004BBC[14].active)
            result = slot;
        break;
    case 10:
        if (D_03004BBC[19].active)
            result = slot;
        if (D_03004BBC[18].active)
            result = slot;
        if (D_03004BBC[17].active)
            result = slot;
        break;
    case 11:
        if (D_03004BBC[18].active)
            result = slot;
        if (D_03004BBC[17].active)
            result = slot;
        if (D_03004BBC[15].active)
            result = slot;
        if (D_03004BBC[14].active)
            result = slot;
        break;
    case 12:
        if (D_03004BBC[19].active)
            result = slot;
        if (D_03004BBC[18].active)
            result = slot;
        if (D_03004BBC[16].active)
            result = slot;
        if (D_03004BBC[15].active)
            result = slot;
        break;
    case 13:
        result = slot;
        break;
    }
    return result;
}
