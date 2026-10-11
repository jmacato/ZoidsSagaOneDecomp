#include "types.h"

struct Slots
{
    u8 pad_0[4];
    u16 slots[6];
};

u8 func_08047D18(struct Slots *slots, u8 index)
{
    u8 count = 0;

    do
    {
        if (slots->slots[index] != 0)
            break;
        index++;
        count++;
        if (index > 5)
            index = 0;
    } while (count <= 10);
    return index;
}
