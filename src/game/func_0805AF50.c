#include "types.h"

struct Team
{
    u8 kind;
    u8 field_1;
    s16 field_2;
    u32 flags;
    u8 pad_8[0x180];
};

extern struct Team D_02010E40[];
extern u8 D_0300232A;
extern u8 D_03002300[];

u8 func_08059A88(u8, u8);

void func_0805AF50(u32 mask)
{
    u8 i;

    for (i = 0; i < D_0300232A; i++)
    {
        if (((D_02010E40 + D_03002300[i])->flags & mask) != mask)
        {
            func_08059A88(i, 0xFF);
            i--;
        }
    }
}
