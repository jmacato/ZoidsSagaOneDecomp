#include "types.h"

struct Slot
{
    u8 side;
    u8 unit;
    u8 pad_2[2];
};

extern struct
{
    u8 pad_0[0x21F1];
    u8 count;
    u8 pad_21F2[2];
    struct Slot slots[6];
} D_0200EB84;

void func_0805D270(const void *, void *, u32);

void func_08034448(void)
{
    struct Slot slots[6];
    vu16 zero;
    vu16 clear;

    zero = 0;
    func_0805D270((void *)&zero, slots, 0x0100000C);
    if (D_0200EB84.count == 0)
    {
        u16 count = 0;
        u16 i;

        for (i = 0; i <= 5; i++)
        {
            if (D_0200EB84.slots[i].unit != 0xFF)
            {
                slots[count].unit = i;
                slots[count].side = D_0200EB84.slots[i].side;
                count++;
            }
        }
        D_0200EB84.count = count;
        clear = 0;
        func_0805D270((void *)&clear, D_0200EB84.slots, 0x0100000C);
        for (i = 0; i < count; i++)
            D_0200EB84.slots[i] = slots[i];
    }
}
