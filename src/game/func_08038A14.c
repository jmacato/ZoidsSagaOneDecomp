#include "types.h"

struct Slot
{
    u8 field_0;
    u8 unit;
    u8 pad_2[2];
};

extern struct
{
    u8 pad_0[0x21F0];
    u8 refresh;
    u8 pad_21F1[3];
    struct Slot slots[6];
    u8 pad_220C[0xA5];
    u8 field_22B1;
    u8 field_22B2;
    u8 pad_22B3;
    u8 units[6];
} D_0200EB84;

void func_08038A14(void)
{
    u16 i;

    D_0200EB84.field_22B2 = 0;
    D_0200EB84.refresh = D_0200EB84.field_22B1;
    for (i = 0; i <= 5; i++)
        D_0200EB84.slots[i].unit = D_0200EB84.units[i];
}
