#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[0xA];
    u32 depth;
    u8 pad_10[0x78];
};

extern struct Sprite D_03004BBC[];
extern u8 D_02006086[];
extern struct
{
    u8 pad_0[6];
    u16 count;
} D_0200000C;

void sort_sprite_order(void)
{
    u16 i;
    u16 j;

    for (i = 1; i < D_0200000C.count; i++)
    {
        if (D_03004BBC[D_02006086[i]].flags & 0x8000)
        {
            for (j = i + 1; j < D_0200000C.count + 1; j++)
            {
                u8 *slot = &D_02006086[j];
                u8 other = *slot;

                if ((D_03004BBC[other].flags & 0x8010) == 0x8000)
                {
                    u8 current = D_02006086[i];

                    if (D_03004BBC[current].depth < D_03004BBC[other].depth)
                    {
                        D_02006086[i] = other;
                        *slot = current;
                    }
                }
            }
        }
    }
}
