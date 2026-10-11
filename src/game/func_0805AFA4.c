#include "types.h"

struct Slot
{
    u16 pad_0;
    u16 id;
};

struct List
{
    u8 pad_0[0x18];
    struct Slot slots[16];
};

extern u8 D_0300232A;

u8 func_08059A88(u8, u8);

void func_0805AFA4(struct List *list, u16 id)
{
    u8 i;

    for (i = 0; i < D_0300232A; i++)
    {
        if (list->slots[i].id != id)
        {
            func_08059A88(i, 0xFF);
            i--;
        }
    }
}
