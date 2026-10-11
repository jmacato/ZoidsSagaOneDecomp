#include "types.h"

struct Slot
{
    u8 side;
    u8 unit;
    u8 pad_2[2];
};

extern struct
{
    u8 pad_0[0x21F0];
    u8 refresh;
    u8 pad_21F1[3];
    struct Slot slots[6];
} D_0200EB84;

extern u8 D_0200DA93;
extern u8 D_0200DA80[2][8];

void func_08042100(void)
{
    u16 i;

    D_0200DA93 = D_0200EB84.refresh;
    for (i = 0; i <= 5; i++)
    {
        u8 unit = D_0200EB84.slots[i].unit;

        if (D_0200EB84.slots[i].side == 0)
        {
            if (unit != 0xFF)
                D_0200DA80[0][i] = 1;
        }
        else if (unit != 0xFF)
        {
            D_0200DA80[1][i] = 1;
        }
    }
}
