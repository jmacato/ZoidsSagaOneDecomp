#include "types.h"

struct Slot
{
    u8 pad_0[0x18];
    u16 id;
    u8 pad_1A[0xC2];
    u16 field_DC;
    u16 field_DE;
};

struct Unit
{
    u8 bytes[0x2CC];
};

extern struct Unit D_0200EB8C[];

void func_08033A34(struct Unit *, u8);

void func_080337F0(void)
{
    u8 i;
    u8 j;

    for (i = 0; i <= 5; i++)
    {
        struct Unit *unit = &D_0200EB8C[i];

        for (j = 0; j <= 2; j++)
        {
            struct Slot *slot = (struct Slot *)(unit->bytes + j * 4);

            if (slot->id != 0)
            {
                func_08033A34(unit, j);
                slot->field_DC = 0;
                slot->field_DE = 0xFFFF;
            }
        }
    }
}
