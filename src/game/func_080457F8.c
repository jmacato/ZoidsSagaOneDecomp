#include "types.h"

struct Sprite
{
    u8 pad_0[0x4A];
    u16 field_4A;
    u8 pad_4C[2];
    u16 field_4E;
    u8 pad_50[0x38];
};

extern struct Sprite D_03004BBC[];
extern u16 D_0200E23C[];

struct Unit
{
    u16 pos;
    u8 pad_2[2];
    u16 kinds[7];
};

void func_080455E4(struct Unit *, u8, u8);

void func_080457F8(struct Unit *unit, u8 mode)
{
    u8 i;

    for (i = 0; i <= 6; i++)
    {
        if (unit->kinds[i] != 0)
        {
            if (i <= 2)
            {
                func_080455E4(unit, i, mode);
                D_03004BBC[i + 20].field_4A = 1;
                D_0200E23C[i] = unit->kinds[i];
                if (i == 1)
                    D_0200E23C[1] += 0x1000;
            }
            else
            {
                D_0200E23C[i] = unit->kinds[i];
            }
        }
        else
        {
            if (i <= 2)
            {
                D_03004BBC[i + 20].field_4A = 0;
                D_03004BBC[i + 20].field_4E = 0;
            }
            D_0200E23C[i] = 0;
        }
    }
}
