#include "types.h"

struct Slots
{
    u8 pad_0[4];
    u16 slots[6];
};

struct Object
{
    u16 flags;
    u8 pad_2[0x48];
    u16 field_4A;
    u8 pad_4C[0x3C];
};

extern struct Object D_03004BBC[];

u8 func_08047D44(struct Slots *slots, u8 index)
{
    u8 count = 0;

    if (index > 200)
        index = 5;
    do
    {
        if (slots->slots[index] != 0)
            break;
        index--;
        count++;
        if (index > 200)
            index = 5;
    } while (count <= 10);
    return index;
}

void func_08047D78(void)
{
    u8 i;

    for (i = 0; i <= 2; i++)
    {
        if (D_03004BBC[i + 20].field_4A != 0)
            D_03004BBC[i + 20].flags |= 0x8000;
    }
}
