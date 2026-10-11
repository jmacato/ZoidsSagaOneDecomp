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
extern const u8 D_086D41CC[2][6];

void func_08033E40(void);

void func_08046884(void)
{
    u8 i;
    u8 side;

    for (i = 0; i <= 5; i++)
    {
        D_0200EB84.slots[i].side |= 0xFF;
        D_0200EB84.slots[i].unit |= 0xFF;
    }
    for (side = 0; side <= 1; side++)
    {
        for (i = 0; i <= 5; i++)
        {
            if (D_0200DA80[side][i] != 0)
            {
                D_0200EB84.slots[i].side = side;
                D_0200EB84.slots[i].unit = D_086D41CC[side][i];
            }
        }
    }
    D_0200EB84.refresh = D_0200DA93;
    func_08033E40();
}
