#include "types.h"

struct Member
{
    u16 flags[6];
    u8 pad_C[0x2A];
    u8 active;
    u8 pad_37[9];
};

struct Team
{
    u8 kind;
    u8 pad_1[7];
    struct Member members[6];
};

extern struct Team D_02010E40[];
extern u8 D_0300232A;
extern u8 D_0300232B[];
extern u8 D_03002300[];
extern u8 D_03002306[][6];

void func_08059980(void)
{
    u8 i;
    u8 j;
    u8 k;

    D_0300232A = 0;
    for (i = 0; i < 6; i++)
    {
        struct Team *team = &D_02010E40[i];

        D_0300232B[D_0300232A] = 0;
        if (team->kind != 0 && team->kind != 0xFF)
        {
            for (j = 0; j < 6; j++)
            {
                struct Member *member = &team->members[j];

                if (member->active)
                {
                    for (k = 0; k < 6; k++)
                    {
                        if (member->flags[k] & 1)
                        {
                            D_03002306[D_0300232A][D_0300232B[D_0300232A]] = j;
                            D_0300232B[D_0300232A]++;
                            break;
                        }
                    }
                }
            }
        }
        if (D_0300232B[D_0300232A])
        {
            D_03002300[D_0300232A] = i;
            D_0300232A++;
        }
    }
}
