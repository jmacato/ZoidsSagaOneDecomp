#include "types.h"

struct Member
{
    u16 flags[6];
    u8 pad_C[0x34];
};

struct Team
{
    u8 kind;
    u8 side;
    u8 pad_2[2];
    u32 status;
    struct Member members[6];
};

struct Skill
{
    u8 pad_0[5];
    u8 active;
    u16 id;
};

struct Skills
{
    struct Skill skills[48];
    u8 pad_180[0x14C];
};

struct Target
{
    u8 pad_0[0x62];
    u16 id;
};

extern struct Team D_02010E40[];
extern struct Skills D_0200FDA8[];
extern u8 D_0300232A;
extern u8 D_0300232B[];
extern u8 D_03002300[];
extern u8 D_03002306[][6];

u8 func_08059A88(u8, u8);

void func_0805AD14(u8 *targets)
{
    u8 i;
    u8 j;
    u8 k;
    u8 m;

    for (i = 0; i < D_0300232A; i++)
    {
        struct Team *team = &D_02010E40[D_03002300[i]];

        if (team->status & 0x480000)
        {
            func_08059A88(i, 0xFF);
            i--;
            continue;
        }
        for (j = 0; j < D_0300232B[i]; j++)
        {
            struct Member *member = &D_02010E40[D_03002300[i]].members[D_03002306[i][j]];

            for (k = 0; k < 6; k++)
            {
                if (member->flags[k] & 1)
                {
                    struct Skills *skills;

                    m = 0;
                    skills = &D_0200FDA8[k];
                    for (; m < 48; m++)
                    {
                        if (skills->skills[m].active && skills->skills[m].id == ((struct Target *)(targets + D_03002300[i] * 20))->id)
                            break;
                    }
                    if (m == 48)
                        break;
                }
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
