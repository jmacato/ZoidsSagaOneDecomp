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

void func_08059D60(void)
{
    s32 best = 0;
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
                if ((member->flags[k] & 1) && member->power[k] > best)
                    best = member->power[k];
            }
        }
    }
    for (i = 0; i < D_0300232A; i++)
    {
        for (j = 0; j < D_0300232B[i]; j++)
        {
            member = &D_02010E40[D_03002300[i]].members[D_03002306[i][j]];
            for (k = 0; k < 6; k++)
            {
                if ((member->flags[k] & 1) && member->power[k] == best)
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

void func_08059EE0(void)
{
    s32 best = 0;
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
                if ((member->flags[k] & 1) && member->speed[k] > best)
                    best = member->speed[k];
            }
        }
    }
    for (i = 0; i < D_0300232A; i++)
    {
        for (j = 0; j < D_0300232B[i]; j++)
        {
            member = &D_02010E40[D_03002300[i]].members[D_03002306[i][j]];
            for (k = 0; k < 6; k++)
            {
                if ((member->flags[k] & 1) && member->speed[k] == best)
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

void func_0805A068(void)
{
    s32 best = 0x7FFFFFFF;
    u8 i;
    u8 j;

    for (i = 0; i < D_0300232A; i++)
    {
        for (j = 0; j < D_0300232B[i]; j++)
        {
            if (D_02010E40[D_03002300[i]].field_2 < best)
                best = D_02010E40[D_03002300[i]].field_2;
        }
    }
    for (i = 0; i < D_0300232A; i++)
    {
        for (j = 0; j < D_0300232B[i]; j++)
        {
            if ((D_02010E40 + D_03002300[i])->field_2 != best)
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
