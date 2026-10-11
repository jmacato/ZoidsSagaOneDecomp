#include "types.h"

struct Member
{
    u16 flags[6];
    s16 speed[6];
    s32 power[6];
    u8 pad_30[0x10];
};

struct Team
{
    u8 kind;
    u8 field_1;
    s16 field_2;
    u8 pad_4[4];
    struct Member members[6];
};

extern struct Team D_02010E40[];
extern u8 D_0300232A;
extern u8 D_0300232B[];
extern u8 D_03002300[];
extern u8 D_03002306[][6];

u8 func_08059A88(u8, u8);

void func_08059C98(void)
{
    u8 i;
    u8 j;
    u8 k;
    struct Member *member;

    for (i = 0; i < D_0300232A; i++)
    {
        for (j = 0; j < D_0300232B[i]; j++)
        {
            member = &D_02010E40[D_03002300[i]].members[D_03002306[i][j]];
            for (k = 0; k < 6; k++)
            {
                if ((member->flags[k] & 0x8001) == 0x8001)
                    break;
            }
            if (k == 6)
            {
                if (!func_08059A88(i, j))
                {
                    i--;
                    break;
                }
                j--;
            }
        }
    }
}
