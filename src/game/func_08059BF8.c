#include "types.h"

struct Entry
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[0x186];
};

extern struct Entry D_02010E40[];
extern u8 D_03002300[];
extern u8 D_0300232A;

u8 func_08059A88(u8, u8);

void func_08059BF8(void)
{
    u8 i;

    for (i = 0; i < D_0300232A; i++)
    {
        if ((D_02010E40 + D_03002300[i])->field_1 != 0)
        {
            func_08059A88(i, 0xFF);
            i--;
        }
    }
}
