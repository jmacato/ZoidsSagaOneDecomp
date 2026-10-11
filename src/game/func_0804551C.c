#include "types.h"

struct Sprite
{
    u8 pad_0[0x44];
    u16 field_44;
    u16 field_46;
    u16 field_48;
    u8 pad_4A[0x3E];
};

extern struct Sprite D_03004BBC[];
extern u16 D_086D41D8[];

void func_0804551C(u32 unused, u16 index)
{
    u8 i;

    for (i = 0; i <= 5; i++)
    {

        D_03004BBC[i + 14].field_44 = ~D_086D41D8[index] + 1;
        D_03004BBC[i + 14].field_46 = D_086D41D8[index];
        D_03004BBC[i + 14].field_48 = 0;
    }
}
